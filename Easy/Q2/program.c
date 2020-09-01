/*

PROBLEM STATEMENT
    The DSC RIT team wanted to make a very complex question for the participants on the Bug Bounty Challenge. They tried very hard but their program for the competition still had some bugs.
    Now they want your help to implement the following logic:

    You are given a string with some alphabets(a-z or A-Z) and digits(0-9).
    Here are the sequence of steps we are doing

    1. Calculating the FREQUENCY of each digit that appeared in the string.
    2. The count of each digit is stored in an array.
    3. That array is passed to a function called HASH and that prints a string.
    4. The string printed is your KEY for the NEXT QUESTION.

    Fix any bugs in this code and the DSC RIT team will give you the KEY for you to continue your journey and win the Bug Bounty Contest!

INSTRUCTIONS
    1. The hash function is correct and doing its job, please DO NOT MODIFY IT
    2. THE INPUT is already handled for you.
    3. You are supposed to fix the logic for counting the frequency of characters correctly 
        and fix the bugs present.

INPUT: 
    Already Handled, Please don't touch the HEADER FILES.

OUTPUT: 
    1. The OUTPUT Printed on your console is key to enter into website.
    2. The OUTPUT is of the format: XXXXXXXohw
        
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "helpers.h"

int main() {
    
    char s;
    s = getString();
    int arr[10],a;
    for (int i=0; i< strlen(s); i++) 
    {
        if(isdigit(s[i]))
            {
                a=(int)s[i]-'O';
                arr[a]++;
            }
    }
    hash(arr);  
    return 0;
}

