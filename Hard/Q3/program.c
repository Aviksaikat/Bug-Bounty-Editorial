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
    
    
    KEY FORMAT: XXXXXXXX39
*/

#include <stdio.h>
#include "helpers.h"

int main()
{
    char hashInput[6];                    // This is used for hashing, don't worry about it
    int t, n, index = 0;                  // t = number of test cases, n = number of people, 'index' is also used for hashing purposes and again don't worry about it.
    FILE *file = fopen("input.txt", "r"); // The input is being automatically read from the given input file
    fscanf(file, "%d", &t);               // First the number of test cases is being read from the file

    // For each test case, we do the following
    while (t--)
    {
        fscanf(file, "%d", &n); // The number of people for a given test case is being read from the file
        int weightInput, frequency[101];
        for (int i = 0; i < n; ++i)
        {
            fscanf(file, "%d", &weightInput); // The weight of each person for a given test case is being read from the file
            ++frequency[weightInput];         // The frequency of each weight is being stored in frequency[] array
        }
        int maxNumberOfTeams = 0; // The max number of teams we can form is stored in this variable (our required output)

        /*
            Let's go over the logic used to solve this problem. We are using brute force technique here to keep things simple. 
            As the question says, first we need to fix some total weight 's' and then for that total weight 's', we are checking the 
            number of teams we can form such that the total weight of each team = 's'. We repeat this step for different total weights 
            starting from s = 2 to s = 2*n (see the outer for-loop) and hence, we get different number of teams we can form for each 
            total weight. Finally we just check in which case we get max teams and that's the answer we want.

            If you are wondering why we only loop till s = 2*n instead of s = 10*n or whatever, it's because s = 2*n is enough as
            the inputs we have given you are small enough to brute force only till s = 2*n.
        */
        for (int s = 2; s <= 2 * n; ++s)
        {
            int currentNumberOfTeams = 0; // currentNumberOfTeams stores the number of teams we can form for a given total weight 's'.

            /*
                Now that we have fixed a total weight 's', we are now checking if for some person's weight i, is there any other 
                person of weight (s - i) so that those 2 weights add up to 's' (which is what we want to do). If yes, then we team
                them up and increase currentNumberOfTeams by 1. If no, then we just continue looping.

                Note: We only need to check i from 1 to (s+1)/2 since the other half is covered by (s-i), i.e., to avoid repetitions.    
            */
            for (int i = 1; i <= (s + 1) / 2; ++i)
            {
                if (s - i > n)
                    break;

                /*  
                    If we have, say 5 ppl with weight i and 10 ppl with weight (s - i), then we have 5 teams. This number 5 is nothing 
                    but the lesser of the frequency of the number of ppl with weight i and weight (s - i). This is what we are trying
                    to do in the below piece of code   
                */
                if (frequency[i] < frequency[s - i])
                    currentNumberOfTeams += frequency[i];
                else
                    currentNumberOfTeams += frequency[s - i];
            }
            if (s % 2 == 0)
                currentNumberOfTeams += frequency[s / 2];

            /*  
                If the number of teams that can be formed for the given total weight 's' is greater than the max number of teams at the
                moment, then we assign that new max value to 'maxNumberOfTeams' variable.
            */
            if (currentNumberOfTeams > maxNumberOfTeams)
                maxNumberOfTeams = currentNumberOfTeams;
        }

        // Some hashing stuff to not worry about
        hashInput[index] = simpleHash(maxNumberOfTeams);
        ++index;
    }
    // More hashing stuff, again nevermind
    hashInput[5] = '\0';
    printf("Key : %u\n", complexHash(hashInput));

    // The input file is closed.
    fclose(file);

    return 0;
}