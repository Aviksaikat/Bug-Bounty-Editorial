/*
    (NOTE: DON'T GET INTIMIDATED BY THE HUGE COMMENTS. THEY ARE ONLY HERE TO HELP YOU. SPEND SOME TIME READING THROUGH THEM AND YOU'LL QUICKLY UNDERSTAND HOW THE SOLUTION WORKS AND HENCE, HOW TO DEBUG THE CODE)


    PROBLEM STATEMENT:
        Given a string consisting of only 1's, 2's and 3's, this program finds the length of the minimum substring of the given string 
        which has all the 3 characters occurring at least once

    INPUT FORMAT:   A single string consisting of only 1's, 2's and 3's
    SAMPLE INPUT:   12133
    SAMPLE OUTPUT:  3
    EXPLANATION:    "213" starting from index 1 to index 3 in the given string is the smallest substring with 1, 2 and 3 atleast once
    
    NOTE:   
        The output obtained is then automatically passed to a hash function and that hashed output is what's displayed as final 
        output on your screen. It's this hashed final output that you should enter in the website to get the password for the zip 
        file. Don't worry about how the hashing is done, just focus on getting the correct output for the given input.

    
    KEY: 3088598729

    {
        TEST RESULTS:   1) OS - Windows(WSL), Ubuntu
                        2) Editor - VS Code
                        3) Key - As expected
    }
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "helpers.h"

#define MAX 10000
#define INFINITY 1e9

bool isValid(char[], int);

int main()
{
    char s[MAX], finalMinimumLength[5];
    FILE *file = fopen("input.txt", "r");
    fgets(s, MAX, file);
    int l = 3, r = strlen(s), currentMinimumLength = INFINITY;

    while (l <= r)
    {
        int mid = (l + r) / 2; ////BUG CORRECTED - Should be '(l + r) / 2' instead of 'l + r / 2'

        if (isValid(s, mid))
        {
            if (mid < currentMinimumLength) ////BUG CORRECTED - Should be 'mid < currentMinimumLength' instead of 'mid > currentMinimumLength'
                currentMinimumLength = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    sprintf(finalMinimumLength, "%d", currentMinimumLength);
    printf("Key: %lu\n", hash(finalMinimumLength));

    fclose(file);

    return 0;
}

bool isValid(char s[], int k)
{
    int frequency[4] = {0}; ////BUG CORRECTED - Should be 'frequency[4]' instead of 'frequency[3]'

    for (int i = 0; i < k; ++i)
        ++frequency[s[i] - '0'];
    for (int i = k; i < strlen(s); ++i)
    {
        if (frequency[1] > 0 && frequency[2] > 0 && frequency[3] > 0)
            return true;
        ++frequency[s[i] - '0'];     ////BUG CORRECTED - Should be '++frequency' instead of '--frequency'
        --frequency[s[i - k] - '0']; ////BUG CORRECTED - Should be '--frequency' instead of '++frequency'
    }

    if (frequency[1] > 0 && frequency[2] > 0 && frequency[3] > 0)
        return true;

    return false;
}
