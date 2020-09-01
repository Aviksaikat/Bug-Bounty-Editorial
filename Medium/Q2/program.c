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
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long int ans = 1; ///////////////////// DON'T CHANGE THIS LINE///////////////////

typedef struct
{
    char name[100];
    int jersey;
} football;

int cnt = 0;
football players[] = new football[100];

void addplayer(char s[], int j)
{
    football p;
    p->name = s;
    p->jersey = j;
    players[cnt] = p;

    ans = ans * j + cnt; ///////////////////// DON'T CHANGE THIS LINE///////////////////
}

void printplayers()
{
    int i;
    for (i = 0; i < cnt; i++)
    {
        printf("%s", players[i]->name);
        printf("%d\n", players[i]->jersey);
    }
}

int main()
{
    FILE infile;
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
    printf("\nKEY to be entered is: %lu\n", ans);
}