/**
    THIS FILE IS ABSOLUTELY CORRECT AND HAS NO ERRORS WHATSOEVER
    PLEASE DO NOT TOUCH THIS FILE
*/

#include <stdio.h>
#include <stdlib.h>

void hash(int arr[6],int size);
void secondaryhash(int arr[6],int size);

char **getArray()
{
    char arrofHex[6][7] = {{'0', 'x', '6', 'F', 'E', 'F', '\0'}, {'0', 'x', '8', '0', '\0'}, {'0', 'x', 'F', 'F', '\0'}, {'0', 'x', 'A', 'B', 'C', 'D', '\0'}, {'0', 'x', '1', '3', '8', '8'}, {'0', 'x', '1', '2', '1', 'F'}};
    char **arr = (char **)malloc(sizeof(char *) * 7);
    for (int i = 0; i < 6; i++) //checking purpose
    {
        arr[i] = (char *)malloc(sizeof(char) * 8);
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            arr[i][j] = arrofHex[i][j];
        }
    }
    for (int i = 6; i < 7; i++)
    {
        arr[i] = NULL;
    }

return arr;
}

void hash(int arr[50],int size)
{
    for(int k=0;k<size;k++)
    {
        arr[k]%=22;
    }
    secondaryhash(arr,size);
}

void secondaryhash(int arr[50],int size)
{
    for(int k=0;k<size;k++)
    {
        arr[k]/=2;
        printf("%d",arr[k]+99);
    }
}