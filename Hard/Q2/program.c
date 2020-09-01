/*
    (NOTE: DON'T GET INTIMIDATED BY THE HUGE COMMENTS. THEY ARE ONLY HERE TO HELP YOU. SPEND SOME TIME READING THROUGH THEM AND YOU'LL QUICKLY UNDERSTAND HOW THE SOLUTION WORKS AND HENCE, HOW TO DEBUG THE CODE)


    PROBLEM STATEMENT:
        Congrats on finishing yet another contest. Unfortunately the server's down and you don't know the final standings. However, your
        smart friend took a pic of the results table just before the server went down but he wasn't smart enough to also take the pic of 
        ranks. Instead all you have are the number of problems solved and the penalty time for each team. Its now your job to rank all the teams.

        Here are the rules for ranking each team. Let's say that team 'a' solved Pa problems with total penalty time Ta and team 'b' 
        solved Pb problems with total penalty time Tb. Team 'a' gets a higher place than team 'b' in the end, if it either solved more 
        problems on the contest, or solved the same number of problems but in less total time. In other words, team 'a' gets a higher 
        place than team 'b' in the final results table if either Pa > Pb, or Pa = Pb and Ta < Tb.

        It is considered that the teams that solve the same number of problems with the same penalty time share all corresponding places. 
        In other words, let's say there is a group of 'x' teams that solved the same number of problems with the same penalty time. Let's 
        also say that 'y' teams performed better than the teams from this group. In this case all teams from the group share places 
        y+1, y+2, ....., y+x. The teams that performed worse than the teams from this group, get their places in the results table 
        starting from the (y+x+1)-th place.

        Your task is to count how many teams from the given list of teams shared the k-th place in the results table.

    INPUT FORMAT:   
        1st line contains 2 integers, n = number of teams and k = the place in the results table for which you need to find the number of teams who achieved it.
        The next 'n' lines contain the description of the teams: 
            The i-th line contains two integers Pi and Ti (1 ≤ Pi, Ti ≤ 50) — The number of solved problems and the total penalty time of the i-th team, respectively, separated by spaces.
    
    SAMPLE INPUT:   
        7 2
        4 10
        4 10
        4 10
        3 20
        2 1
        2 1
        1 10
    
    SAMPLE OUTPUT:  3

    EXPLANATION:    
        The final results table is - 
        1-3 places —> 4 solved problems, the penalty time equals 10
        4th place —> 3 solved problems, the penalty time equals 20
        5-6 places —> 2 solved problems, the penalty time equals 1
        7th place —> 1 solved problem, the penalty time equals 10
        The table shows that the second place is shared by the teams that solved 4 problems with penalty time 10. There are 3 such teams.
    
    NOTE:   
        The output obtained is then automatically passed to a hash function and that hashed output is what's displayed as final 
        output on your screen. It's this hashed final output that you should enter in the website to get the password for the zip 
        file. Don't worry about how the hashing is done, just focus on getting the correct output for the given input.
    
    
    KEY FORMAT: XXXXXX16
*/

#include <stdio.h>
#include "helpers.h"

int main()
{
    int n, k; // n and k are explained above under 'Input Format'
    FILE *file = fopen("input.txt", "r");
    fscanf(file, "%d %d", &n, &k);         // n and k values are being read automatically from the given input file
    int problemsSolved[n], timePenalty[n]; // problemsSolved[] array stores the number of problems solved by each team. timePenalty[] array stores the penalty time for each team
    for (int i = 0; i < n; i++)
        fscanf(file, "%d %d", &problemsSolved[i], &timePenalty[i]); // The values for problemsSolved[] and timePenalty[] arrays are being read from the given input file
    int temp;                                                       // temp is used for swapping values later on while sorting
    char hashInput[2];                                              // hashInput[] is used for hashing purposes. Don't worry about it

    /*
        Let's checkout the logic behind the solution to this problem. Luckily, it's pretty straightforward. First we begin by sorting
        the problemsSolved[] array in decreasing order as teams who have solved more problems will have the top ranks. That's exactly 
        what the below for-loop does. Notice that we swap the values in timePenalty[] array too so that we can keep track of which 
        penalty time corresponds to which team.
    */
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (problemsSolved[j] > problemsSolved[i])
            {
                temp = problemsSolved[j];
                problemsSolved[j] = problemsSolved[i];
                problemsSolved[i] = temp;

                temp = timePenalty[i];
                timePenalty[i] = timePenalty[j];
                timePenalty[j] = temp;
            }
        }
    }

    /*
        Then, we sort timePenalty[] array values in increasing order if and only if the corresponding problemsSolved[] array values 
        are the same for some teams. We sort it in increasing order as teams with lower penalty times will have the top ranks, if they 
        have solved the same number of problems.
    */
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (problemsSolved[i] > problemsSolved[j])
                continue;
            if (timePenalty[i] > timePenalty[j])
            {
                temp = timePenalty[i];
                timePenalty[i] = timePenalty[j];
                timePenalty[j] = temp;
            }
        }
    }

    /*
        problemsSolvedByKthTeam = The number of problems solved by the team at the k-th index (or k-th place), 
        timePenaltyForKthTeam = The penalty time for the team at the k-th index (or k-th place),
        teamsSharingKthPlace = It stores the number of teams which share the same k-th place (our required output)
    */
    int problemsSolvedByKthTeam = problemsSolved[k], timePenaltyForKthTeam = timePenalty[k], teamsSharingKthPlace = 0;

    /* 
        In this for-loop, we are computing the number of teams which share the same k-th place, to the left of the team with the 
        k-th index.
    */
    for (int i = k - 2; i >= 0; i--)
    {
        if (problemsSolved[i] != problemsSolvedByKthTeam && timePenalty[i] != timePenaltyForKthTeam)
            break;
        teamsSharingKthPlace++;
    }

    /* 
        In this for-loop, we are computing the number of teams which share the same k-th place, to the right of the team with the 
        k-th index.
    */
    for (int i = k; i < n; i++)
    {
        if (problemsSolved[i] != problemsSolvedByKthTeam && timePenalty[i] != timePenaltyForKthTeam)
            break;
        teamsSharingKthPlace++;
    }

    // Some hashing stuff you don't have to worry about.
    sprintf(hashInput, "%d", teamsSharingKthPlace);
    printf("Key : %lu\n", hash(hashInput));

    // The input file is closed.
    fclose(file);

    return 0;
}