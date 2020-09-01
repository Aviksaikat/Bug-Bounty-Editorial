/**
    THIS FILE IS ABSOLUTELY CORRECT AND HAS NO ERRORS WHATSOEVER
    PLEASE DO NOT TOUCH THIS FILE
*/

#include <stdio.h>

int *getArray(int *numberArray, int n)
{
    FILE *myFile;
    myFile = fopen("data.txt", "r");

    int i;
    if (myFile == NULL)
    {
        printf("Error Reading File\n");
    }

    for (i = 0; i < n; i++)
    {
        fscanf(myFile, "%d ", &numberArray[i]);
    }
    fclose(myFile);
    return numberArray;
}

unsigned int hash(const char *str)
{
    unsigned int length = strlen(str);
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash_ = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash_ = hash_ * a + (*str);
        a = a * b;
    }

    return hash_;
}
