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
    
    
    KEY: 13550916

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
    int n, k;
    FILE *file = fopen("input.txt", "r");
    fscanf(file, "%d %d", &n, &k);
    int problemsSolved[n], timePenalty[n], i;
    for (i = 0; i < n; i++)
        fscanf(file, "%d %d", &problemsSolved[i], &timePenalty[i]);
    int temp, j;
    char hashInput[2];

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (problemsSolved[j] > problemsSolved[i])
            {
                temp = problemsSolved[j];
                problemsSolved[j] = problemsSolved[i];
                problemsSolved[i] = temp;

                temp = timePenalty[j];           // Buggy file says, 'timePenalty[i]' instead of 'timePenalty[j]'
                timePenalty[j] = timePenalty[i]; // Buggy file says, 'timePenalty[i] = timePenalty[j]' instead of 'timePenalty[j] = timePenalty[i]'
                timePenalty[i] = temp;           // Buggy file says, 'timePenalty[j]' instead of 'timePenalty[i]'
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (problemsSolved[i] > problemsSolved[j])
                break; // Buggy file says, 'continue' instead of 'break'
            if (timePenalty[i] > timePenalty[j])
            {
                temp = timePenalty[i];
                timePenalty[i] = timePenalty[j];
                timePenalty[j] = temp;
            }
        }
    }

    int problemsSolvedByKthTeam = problemsSolved[k - 1], // Buggy file says, 'problemsSolved[k]' instead of 'problemsSolved[k - 1]'
        timePenaltyForKthTeam = timePenalty[k - 1],      // Buggy file says, 'timePenalty[k]' instead of 'timePenalty[k - 1]'
        teamsSharingKthPlace = 1;                        // Buggy file says, '0' instead of '1'

    for (i = k - 2; i >= 0; i--)
    {
        if (problemsSolved[i] != problemsSolvedByKthTeam || timePenalty[i] != timePenaltyForKthTeam) // Buggy file says, '&&' instead of '||'
            break;
        teamsSharingKthPlace++;
    }

    for (i = k; i < n; i++)
    {
        if (problemsSolved[i] != problemsSolvedByKthTeam || timePenalty[i] != timePenaltyForKthTeam) // Buggy file says, '&&' instead of '||'
            break;
        teamsSharingKthPlace++;
    }
    sprintf(hashInput, "%d", teamsSharingKthPlace);
    printf("Key : %lu\n", hash(hashInput));

    return 0;
}