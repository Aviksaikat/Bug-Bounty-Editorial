/*
    (NOTE: DON'T GET INTIMIDATED BY THE HUGE COMMENTS. THEY ARE ONLY HERE TO HELP YOU. SPEND SOME TIME READING THROUGH THEM AND YOU'LL QUICKLY UNDERSTAND HOW THE SOLUTION WORKS AND HENCE, HOW TO DEBUG THE CODE)


    PROBLEM STATEMENT:
        There are n people who want to participate in a boxing competition. The weight of the i-th participant is wi. Only teams 
        consisting of two people can participate in this competition. As an organizer, you think that it's fair to allow only teams with 
        the same total weight.

        So in other words, if there are k teams (a1, b1), (a2, b2), ....., (ak, bk), where ai is the weight of the first participant of 
        the i-th team and bi is the weight of the second participant of the i-th team, then the condition a1+b1 = a2+b2= ..... = ak+bk = s, 
        where s is the total weight of each team, should be satisfied.

        Your task is to maximise the number of teams people can form by choosing some optimal weight 's'. Note that each participant can 
        be in no more than one team.


    INPUT FORMAT:   
        1st line is the number of test cases, t (1 <= t <= 10)
        For each test case, you have 2 lines.
            1st line of a test case is the number of people, n (1 <= n <= 100)
            2nd line of a test case consists of n numbers, each corresponding to the weight of a person (each of whose value varies from 1 to n)
    
    SAMPLE INPUT:   
        1
        5
        2 4 6 8 10
    
    SAMPLE OUTPUT:  2
    
    EXPLANATION:    
        The optimal weight in this case is 12, so we can team up the 1st and the 5th person, the 2nd and 4th person to
        form a total of 2 teams (i.e., the output). Unfortunately the 3rd person with weight 6 can't participate since 
        there is no one else left to team up with the 3rd person to form a total weight of 12.

    NOTE:   
        The output obtained for each test case is then automatically passed to a hash function and that hashed output is what's 
        displayed as final output. It's this hashed final output that you should enter in the website to get the password for the zip file.
        Don't worry about how the hashing is done, just focus on getting the correct output for the given input


    KEY: 4207081239

    {
        TEST RESULTS:   1) OS - Windows(WSL), Ubuntu
                        2) Editor - VS Code
                        3) Key - As expected
    }
*/

#include <stdio.h>
#include "helpers.h"

int main()
{
    char hashInput[6];
    int t, n, index = 0;
    FILE *file = fopen("input.txt", "r");
    fscanf(file, "%d", &t);

    while (t--)
    {
        fscanf(file, "%d", &n);
        int weightInput, frequency[101] = {0}; // Buggy file says, 'frequency[101]' instead of 'frequency[101] = {0}'
        for (int i = 0; i < n; ++i)
        {
            fscanf(file, "%d", &weightInput);
            ++frequency[weightInput];
        }

        int maxNumberOfTeams = 0;
        for (int s = 2; s <= 2 * n; ++s)
        {
            int currentNumberOfTeams = 0;

            for (int i = 1; i < (s + 1) / 2; ++i) // Buggy file says, 'i <= (s + 1) / 2' instead of 'i < (s + 1) / 2'
            {
                if (s - i > n)
                    continue; // Buggy file says, break instead of break

                if (frequency[i] < frequency[s - i])
                    currentNumberOfTeams += frequency[i];
                else
                    currentNumberOfTeams += frequency[s - i];
            }
            if (s % 2 == 0)
                currentNumberOfTeams += frequency[s / 2] / 2; // Buggy file says, 'frequency[s / 2]' instead of 'frequency[s / 2] / 2'

            if (currentNumberOfTeams > maxNumberOfTeams)
                maxNumberOfTeams = currentNumberOfTeams;
        }

        hashInput[index] = simpleHash(maxNumberOfTeams);
        ++index;
    }
    hashInput[5] = '\0';
    printf("Key : %u\n", complexHash(hashInput));

    fclose(file);

    return 0;
}