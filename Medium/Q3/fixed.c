/*
    PROBLEM STATEMENT:
        During the COVID pandemic some people are so bored that they are going through their phone contacts and sorting all the contacts by mobile numbers.
        You are given a phonebook with 1000 entries and each entry contains a user's name and his mobile number(Regular number length).
        You need to sort the entries in the phonebook by the mobile number.
        Being a smart coder you decided to write a C program to do the same. But as usual every programmer has to face some bugs in their lives and so do you.
        Fix whatever bugs you have in your phone and you will finally have a worthwhile activity to pass time with as well as a KEY that move on to the next level.

    INPUT:
        1000 phonebook entires from input.csv. The input from the file has been handled for you. 
    
    WHAT DOES THE CODE ACHIEVE: All entries are sorted in assending order of mobile numbers.
    
    OUTPUT: (this is displayed in the output window)

    KEY:  3069815369

    INSTRUCTIONS
        1. There are no bugs in the code which is below "DONT CHANGE BELOW CODE"
        2. You are supposed to modify the code between "CODE BELOW HAS BUGS" and "CODE ABOVE HAS BUGS"
    
    IMPORTANT: DO NOT MODIFY ANY OTHER FILES OTHER THAN THIS
    
    NOTE: There could be simple bugs in the main function unrelated to file operations, look out for them.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"

struct contact
{
    char name[20];
    long long phone; //// BUG CORRECTED- Mobile numbers can't be expressed in INT
};

void sort(struct contact *contactList)
{
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 999; j++)
        {
            if (contactList[j].phone > contactList[j + 1].phone) ///// BUG CORRECTED - replace i by j in whole swapping process
            {
                struct contact t = contactList[j]; ///// BUG CORRECTED- t not intialized
                contactList[j] = contactList[j + 1];
                contactList[j + 1] = t;
            }
        }
    }
}

void main()
{
    long long p;
    int bufferLength = 255;
    char buffer[255];
    FILE *file;
    char *pch;

    struct contact contactList[1000];

    file = fopen("data.txt", "r");

    int i = 0;

    while (fgets(buffer, bufferLength, file))
    {
        pch = strtok(buffer, " \n");

        int temp = 0;
        while (pch != NULL) ///////////////// SYNTAX BUG HERE `!==` instead of `!=`
        {
            temp++;
            if (temp == 1)
            {
                strcpy(contactList[i].name, pch); ///////////////////// SYNTAX BUG HERE strcopy instead of strcpy
            }
            else
            {
                contactList[i].phone = atoll(pch);
            }

            pch = strtok(NULL, " \n");
        }
        i++; //// BUG CORRECTED - i should be incremented
    }
    fclose(file);

    sort(contactList);

    //////   DONT CHANGE BELOW CODE

    printf("Key: %u\n", hash(contactList[742].name));
}

