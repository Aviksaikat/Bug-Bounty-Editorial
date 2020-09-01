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

ANSWER

    Expected Output:
    This is my Table: 
    Decimal         Hexadecimal     Person Number   Status 
    57310           0x6FEF          1               Meh... A Useless Human
    256             0x80            2               is a Witch!!
    510             0xFF            3               is a Witch!!
    87962           0xABCD          4               Meh... A Useless Human
    10000           0x1388          5               is a Wizard!!
    9278            0x121F          6               is a Wizard!!

    This is your password: 9999106101102105107
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
        isWitchOrWizard[i]=(int)strtol(arrofHex[i],NULL,16)<<1;     //BUG CORRECTED - Incorrect Code has typecast as (float) instead of (int) and 3rd argument as 8 instead of 16
        printf("%-10d\t\t",((int)strtol(arrofHex[i],NULL,16))<<1);     //BUG CORRECTED- Incorrect Code has typecast as (float) instead of (int) and 3rd argument as 8 instead of 16
        printf("%-10s\t",arrofHex[i]);                                 
        printf("%-10d",i+1);
        if(isWitchOrWizard[i]>=0 && isWitchOrWizard[i]<=4000)
        {
            printf("is a Witch!\n");
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
    // Start of Correct Part of Code - The part of the code between this comment and the last comment is correct. Do not modify it.
    printf("\nKEY: %d",atoi("99abc"));
    hash(isWitchOrWizard,6);
}

