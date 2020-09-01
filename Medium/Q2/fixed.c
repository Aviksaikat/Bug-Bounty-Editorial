/* 

PROBLEM STATEMENT: 
    Now that Messi is leaving Barcelona a football fan wants to show a list of all his favourite football players and their jersey numbers.
    He is writing a C program to read players names and jersey numbers from a file, store them to an array of structures and display their details.
    Unfortunately he ran into a few bugs. Solve those bugs and he will give you the KEY as a token of appreciation for helping him.

INPUT:
    1. This is taken from a file. Do not modify the contents of the file.

OUTPUT: 
    1. Names and Jersey numbers of players, and the KEY which is to be entered into the website
    messi 10
    ronaldo 7
    pulisic 22
    giroud 18
    drogba 11
    lampard 8
    terry 8
    KEY to be entered in website is: XXXXXX43

ANSWER:
    KEY to be entered in website is: 22065143
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    int jersey;
} football;

int cnt = 0;
unsigned long int ans = 1;
football players[100]; //////////////////// SYNTAX BUG HERE, java array init instead of C init

void addplayer(char s[], int j)
{
    football p;
    strcpy(p.name, s); // bug here use strcpy to assign strings = cannot be used
    p.jersey = j;      //bug here use '.' operator to use members directly
    players[cnt] = p;
    cnt++; //bug here increase count
    ans = ans * j + cnt; //do not change this line
}

void printplayers()
{
    int i;
    for (i = 0; i < cnt; i++)
    {
        printf("%s ", players[i].name);    // SYNTAX BUG HERE, use '.' operator to use members directly
        printf("%d\n", players[i].jersey); // SYNTAX BUG HERE, use '.' operator to use members directly
    }
}

int main()
{
    FILE *infile; //////// SYNTAX BUG HERE, initialised as a variable instead of a pointer
    football input;
    char buffer[255];
    int bufferLength = 255;
    char *pch;

    infile = fopen("data.txt", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }

    while (fgets(buffer, bufferLength, infile))
    {
        pch = strtok(buffer, " \n");

        int temp = 0;
        while (pch != NULL)
        {
            temp++;
            if (temp == 1)
            {
                strcpy(input.name, pch);
            }
            else
            {
                input.jersey = atoll(pch);
                addplayer(input.name, input.jersey);
            }

            pch = strtok(NULL, " \n");
        }
    }
    fclose(infile);

    printplayers();
    printf("hash to be entered in website is: %lu\n", ans);
}
