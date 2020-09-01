/*
    PROBLEM STATEMENT:
        You are given 5 different strings with some alphabets(a-z only).
        Here are the sequence of steps we are doing:

        1. The program below intends to find the length of the longest palindromic substring (LPS) (APPROACH DEFINED BELOW) that can be
        formed from the given strings (a-z only). 
        2. Then length of the LPS that can be formed from each of the string given as input is stored in an array.
        3. The HASH function then finds the sum of all  the elemnts in the array and prints a string.
        4. The string printed is your key to get the password for next file. HURRAH!!

        Unfortunately, the program is not working well as deired, help me debug it.

        THE APPROACH TO GET THE MAX LENGTH OF  LPS IS AS FOLLOWS, HOPE IT HELPS YOU DEBUG THE CODE.....

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

                Therefore, Max LPS for string "ant"= 1

    INPUT:
        All the inputs are taken from helpers.h, you do not need to give any inputs from your side.

    OUTPUT:
        The max length of LPS for each string is stored in an array by default, you dont need to store it from your side.
    
    
    KEY: 3149751329

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// #include <lastlog.h>
// #include <stdc-predef.h>
#include <string.h>
#include <stdbool.h>
#include "helpers.h"

int main()
{
    char *str;
    char ans[10];
    int n = 5;
    while (n--) // line 100,101,102 should be enclosed in a loop to take 5 inputs.
    {
        str = (char *)malloc(2000 * sizeof(char));
        str = inputArray[n];
        setArray(str);
    }
    printf("Key : %u\n", hash2(hash(ans)));
    return 0;
}

//This function returns the length of the LPS
int lps(char *str)
{

    // get length of input string
    int n = strlen(str);

    // 2D boolean array of size n
    bool table[n][n]; // table[n-1][n-1] in bugs

    //Setting all the values in the table to false.In the code below, table[i][j] will be set to true
    //if substring str[i..j] is palindrome.

    memset(table, 0, sizeof(table)); //memset(table, 1, sizeof(table)); in bugs

    // All substrings of length 1 are palindromes
    int maxLength = 1; // maxLength is used as mL in bugs(not bug)

    // check for sub-string of length 2.
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
    for (int i = 0; i < n - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            table[i][i + 1] = true;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2. k is length of substring

    for (int k = 4; k <= n; ++k) 
    {

        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i)
        {

            // Get the ending index of substring from starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to jth index iff str[i+1] to str[j-1] is a palindrome .
            if (table[i + 1][j - 1] && str[i] == str[j]) // if (table[i - 1][j + 1] && str[i] == str[j]) in bugs
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
