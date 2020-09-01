/*

PROBLEM STATEMENT
    BACKGROUND

        1. Carl Jonhson (CJ) wants to send a message to the Grove Street Families for help. 
        2. He knows that if the Ballas Gang finds his message then they will ambush them and kill his brother Sweet.
        3. Help CJ to send the message that the grove street families can understand
    
    IMPLEMENTATION DETAIL
        1. In the message if a word is 'HELP' it should be encoded as 'EHLP' (ascending order of words) and so on for other words.
        2. Additionally CJ has encoded 2 extra letters at the end that tells Grove Street Families that the message is from HIM.
           Don't CHANGE THESE 2 LETTERS. YOU DON'T HAVE TO TOUCH IT.
        3. Finally to check if his output is correct CJ put a HASHMYWORDS() method which will provide him with the password.
        4. CHECK FOR ERRORS/BUGS in the PROGRAM AND CORRECT IT TO SAVE SWEET AND CJ.

INSTRUCTIONS

    1. You are not supposed to touch the HASHMYWORDS Function, IT IS ABSOLUTELY CORRECT
    2. INPUT is ALREADY HANDLED. Please DON'T TOUCH THE HEADER FILES. 


INPUT
    1. THIS IS ALREADY HANDLED FOR YOU, YOU DON'T HAVE TO WORRY ABOUT IT.
    2. HEADER FILE IS GIVING THE MESSAGE TO YOU IN **mywords** character array.
    3. THE INPUT ARRAY IS A CHARACTER ARRAY OF SIZE 7X7

OUTPUT
    1. THE OUTPUT IS THE ENCODED STRING WHICH IS YOUR PASSWORD TO THE NEXT LEVEL.
    2. WE HAVE ADDED SOME ADDITIONAL PRINT STATEMENTS TO HELP YOU DEBUG THE CODE.
    3. THE OUTPUT IS OF THE FORMAT
        Password: XXXXXXXXXXXXXXXXXXXXXXRPU
                  

*/

#include<stdio.h>
#include "helpers.h"
void sort(char*,int size);
void hashmywords(char arr[][7],int i);
void main()
{
    printf("Encrypted Message: \n");
    for(int i=0;mywords[i]!='\0';i++)        
    {
        sort(&mywords[i],strlen(mywords[i]));    
        printf("%s ",mywords[i]);
    }
    int a=(int)mywords[0][0];
    printf("\n-%c",a);
    printf("%c\n",74);
    printf("KEY: ");
    hashmywords(mywords,7);
}
void sort(char* s,int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(*(s+i)>*(s+j))       
            {
                int temp=*(s+j);        
                *(s+j)=*(s+j+1);          
                *(s+j+1)=temp;            
            }
        }
    }
}

