/*
    (NOTE: DON'T GET INTIMIDATED BY THE HUGE COMMENTS. THEY ARE ONLY HERE TO HELP YOU. SPEND SOME TIME READING THROUGH THEM AND YOU'LL QUICKLY UNDERSTAND HOW THE SOLUTION WORKS AND HENCE, HOW TO DEBUG THE CODE)


    PROBLEM STATEMENT:
        You are given 5 different strings with some alphabets(a-z only).
        
        Here are the sequence of steps we are doing:
            1. The program below intends to find the length of the longest palindromic substring (LPS) (APPROACH DEFINED BELOW) that can be
            formed from the given strings (a-z only). 
            2. Then length of the LPS that can be formed from each of the string given as input is stored in an array.
            3. The HASH function then finds the sum of all  the elemnts in the array and prints a string.
            4. The string printed is your key to get the password for next file. HURRAH!!

        Unfortunately, the program is not working well as desired, help me debug it.

        THE APPROACH TO GET THE MAX LENGTH OF LPS IS AS FOLLOWS, HOPE IT HELPS YOU DEBUG THE CODE.....
            1. Maintain a boolean square matrix "table" of size equal to the length of the string given and fill it in bottom up manner.
            2. The value of table[i][j] is true, if the substring is palindrome, otherwise false.
            3. To calculate table[i][j], check the value of table[i+1][j-1], if the value is true and str[i] is same as str[j], then we make table[i][j] true.
            4. Otherwise, the value of table[i][j] is made false.

                Let str = ant
                table[3][3] would look something like this after completion:
                
                                0       1       2 
                                a       n       t

                    0   a       1       0       0

                    1   n       0       1       0

                    2   t       0       0       1

                Therefore, Max LPS for string "ant" = 1

    INPUT:
        All the inputs are taken from helpers.h, you do not need to give any inputs from your side.
    
    OUTPUT:
        The max length of LPS for each string is stored in an array by default, you dont need to store it from your side.
    
    
    KEY FORMAT: XXXXXXXX29
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <lastlog.h>
#include <stdc-predef.h>
#include <string.h>
#include <stdbool.h>
#include "helpers.h"

int main()
{
    const ans[10];
    int inputArraySize = 5;
    char *str;

    str = malloc(2000 * sizeof(char));
    str = inputArray[inputArraySize];
    setArray(str);

    printf("Key : %u\n", hash2(hash(ans)));

    return 0;
}

int lps(char *str)
{
    int length = strlen(str);
    bool table[length - 1][length - 1]; // 2D boolean array of size 'length'
    memset(table, 1, sizeof(table));    //In the code below, table[i][j] will be set to true if substring str[i..j] is palindrome.
    int maxLength = 1;                  //Every string of length is palindrome

    // check for sub-string of length 2.
    for (int i = 0; i < length; i += 1)
        table[i][i] = true;

     for (int i = 0; i < length - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            table[i][i + 1] = true;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2. 'k' is the length of substring
    for (int k = 4; k <= length; ++k)
    {
        for (int i = 0; i < length - k + 1; ++i)
        {
            int j = i + k - 1;

            // checking for sub-string from ith index to jth index if str[i+1] to str[j-1] is a palindrome
            if (table[i - 1][j + 1] && str[i] == str[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                    maxLength = k;
            }
        }
    }

    //Return max length of LPS
    return maxLength;
}
