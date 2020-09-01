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
    
    KEY:  xxxxxxx369    enter this into website

    INSTRUCTIONS
        1. There are no bugs in the code which is below "DONT CHANGE BELOW CODE"
        2. You are supposed to modify the code between "CODE BELOW HAS BUGS" and "CODE ABOVE HAS BUGS"
    
    IMPORTANT: DO NOT MODIFY ANY OTHER FILES OTHER THAN THIS FILE 
    
    NOTE: There could be simple bugs in the main function unrelated to file operations, look out for them.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"

////// CODE BELOW HAS BUGS

struct contact
{
    char name[20];
    int phone;
};

void sort(struct contact *contactList)
{
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 999; j++)
        {
            if (contactList[i].phone > contactList[i + 1].phone)
            {
                t = contactList[i];
                contactList[i] = contactList[i + 1];
                contactList[i + 1] = t;
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
        while (pch !== NULL)
        {
            temp++;
            if (temp == 1)
            {
                strcopy(contactList[i].name, pch);
            }
            else
            {
                contactList[i].phone = atoll(pch);
            }

            pch = strtok(NULL, " \n");
        }
    }
    fclose(file);

    sort(contactList);

    ////// CODE ABOVE HAS BUGS

    //////   DONT CHANGE BELOW CODE

    printf("KEY: %u\n", hash(contactList[742].name));
}