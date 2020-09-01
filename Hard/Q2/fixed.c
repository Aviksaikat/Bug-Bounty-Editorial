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
    int p[n], t[n], i;
    for (i = 0; i < n; i++)
        fscanf(file, "%d %d", &p[i], &t[i]);
    int tm, j;
    char hashInput[2];

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[j] > p[i])
            {
                tm = p[j];
                p[j] = p[i];
                p[i] = tm;

                tm = t[j];
                t[j] = t[i];
                t[i] = tm;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i] > p[j])
                break;
            if (t[i] > t[j])
            {
                tm = t[i];
                t[i] = t[j];
                t[j] = tm;
            }
        }
    }

    int x = p[k - 1], y = t[k - 1], ans = 1;
    for (i = k - 2; i >= 0; i--)
    {
        if (p[i] != x || t[i] != y)
            break;
        ans++;
    }

    for (i = k; i < n; i++)
    {
        if (p[i] != x || t[i] != y)
            break;
        ans++;
    }
    sprintf(hashInput, "%d", ans);
    printf("Key : %lu\n", hash(hashInput));

    return 0;
}