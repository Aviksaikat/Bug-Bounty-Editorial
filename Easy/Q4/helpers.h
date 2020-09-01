/**
    THIS FILE IS ABSOLUTELY CORRECT AND HAS NO ERRORS WHATSOEVER
    PLEASE DO NOT TOUCH THIS FILE
*/

#include<stdio.h>
#include<string.h>

char mywords[7][7]={{'D','S','C'},{'S','E','N','D'},{'H','E','L','P'},{'W','E'},{'A','R','E'},{'I','N'},{'T','R','O','U','B','L','E'}};

void hashmywords(char arr[][7],int i)
{
    for(int k=0;k<i;k++)
    {
        for(int l=0;l<strlen(arr[k]);l++)
        {
            switch(arr[k][l])
            {
                case 'A': arr[k][l]='Z';
                    break;
                case 'P': arr[k][l]='X';
                    break;
                case 'D': arr[k][l]='Y';
                    break;
                case 'S': arr[k][l]='Y';
                    break;
                case 'T': arr[k][l]='P';
                    break;
            }
            printf("%c",arr[k][l]);
        }
    }
}