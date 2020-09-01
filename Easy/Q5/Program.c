/*

PROBLEM STATEMENT
    1. Inspired by the Salem Witch Trials, a geek in RIT  wrote a C Program that tells 
        whether a person is A WITCH, A WIZARD, OR A HUMAN based on his HexaDecimal Identity values.
    2. The HexaDecimal Identity values are stored as an array of strings where the index is the
        person number and the value at the index is their HexaDecimal Identity value
    3. If we left shift the HexaDecimal values to get a Decimal, we get their Energy levels and 
        based on that WE CLASSIFY THEM AS A WIZARD, WITCH OR HUMAN.
    4. The code written below attempts to do that, but has some bugs in the conversion.
    5. You are supposed to fix the BUGS to get correct DECMIMAL Values which IN TURN ARE THE 
        ENERGY LEVELS.
    6. If you manage to do that, You will get A PASSWORD WHICH IS YOUR KEY TO THE NEXT LEVEL.

INSTRUCTIONS

    1. You are not supposed to touch the HASH AND THE SECONDARY HASH FUNCTION, THEY ARE ABSOLUTELY CORRECT
    2. INPUT is ALREADY HANDLED. Please DON'T TOUCH THE HEADER FILES.

INPUT
    1. This Is already handled for you. You DON'T NEED TO WORRY ABOUT THIS.

OUPUT
    1. A TABLE WITH THE FOLLOWING STRUCTURE
            This is my Table:
        Decimal     Hexadecimal     Person Number   Status
        256         0x80            1               is a Witch!!
        ...         ...             ...             ...
    2. OUTPUT FORMAT:
        KEY: XXXXXXXXXXXXXXXX107


*/

#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"
int isWitchOrWizard[6];

void main()
{   
    char **arrofHex;
    arrofHex = getArray();
    printf("This is my Table: \n%-10s \t%-10s \t%-10s \t%-25s \n","Decimal","Hexadecimal","Person Number","Status");
    for(int i=0;arrofHex[i] != NULL;i++)                           
    {
        isWitchOrWizard[i]=(float)strtol(arrofHex[i],NULL,8)<<1;     
        printf("%-10d\t\t",((float)strtol(arrofHex[i],NULL,8))<<1);     
        printf("%-10s\t",arrofHex[i]);  
        printf("%-10d",i+1);
                                       
        if(isWitchOrWizard[i]>=0 && isWitchOrWizard[i]<=4000)
        {
            printf("is a Witch!!\n");
        }
        else if (isWitchOrWizard[i]>4000 && isWitchOrWizard[i]<=10000)
        {
            printf("is a Wizard!!\n");
        }
        else
        {
            printf("Meh... A Useless Human\n");
        }
    }

    //////////////DO NOT MODIFY THE CODE BELOW THIS COMMENT//////////////////////
    printf("\nKEY: %d",atoi("99abc"));
    hash(isWitchOrWizard,6);
}
