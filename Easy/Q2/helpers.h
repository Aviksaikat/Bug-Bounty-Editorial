/**
    THIS FILE IS ABSOLUTELY CORRECT AND HAS NO ERRORS WHATSOEVER
    PLEASE DO NOT TOUCH THIS FILE
*/

#include<stdio.h>

char *getString(){
    char word[316] = "nation991economy99169safety897178and8971789630quality9999989593968of7760760631life9945707775are174influenced134byawellmanagedtransportat6965982ionsystemYetdemandsin7259262371transpor9628tationareeverincreasingduetotrendsinpopulationgrowthemerging24022001technologiesand2201theincreasedgl65975obalizationontheeconomy";
    char *returnP = word;
    return returnP;
    
}

void hash(int arr[])
{
    int *ptr = arr;
    printf("KEY: ");
    for(int i = 0 ; i < 10 ; i++)
    {
        if((*ptr)>0)
            printf("%c",(--*ptr)%26+97); 
        *++ptr;
    }
}