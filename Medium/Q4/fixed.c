/*
    A genius student at RIT wanted to get a STAR package and so she wrote a code that would sound complicated in her Resume and hence would help her get placed in the on-campus interview.
    She hands you her code and expects you to understand it and fix any bugs before its time for her interview. If you help her she will give you the KEY to proceed to the next level.

    Following code should give the sum of Ullaru Numbers (Defined below) in the range 1 to q(both inclusive), answer to which is passed to hash()
    to get the password to next zip file. BINGO! But the code written below is not working properly,
    it would be great if you help crack this down.

    So,Ullaru Number can be defined as:
    Consider a k-digit number n. Square it. Now, add the right k digits to the left k or k-1 digits(and none of the right k and left k-1
    digits should have the value 0).
    If the resultant sum is n (the original number we started with), then n is called an Ullaru number. 

    For example, 

    297 is a Ullaru number since,
    297*297=88209 ; 88+209=297

    13 is not a Ullaru number since,
    13*13 = 169   ; Niether 16+9 equals 13 nor 1+69 equals 13 

    10 is not a Ullaru number since,
    10*10 = 100 ; 
    It is not a Ullaru number even if sum of 10+0=10. This is because of the condition that none of the parts should have value 0.


In this program, we check for all the ullaru numbers from 1 to 99,999. The flow goes as follows:
1. Find square of n and count number of digits in square, let this be k.
2. Split this result as, the rightmost k digits, and the leftmost k or k-1 digits.
3. Sum these 2 set of digits that you just obtained, of they add up to n, WOLLAH.
4. Sum all these Ullaru numbers, send it through the hash function to get your password.

INPUT:
    All the inputs are taken from helpers.h, you do not need to give any inputs from your side.

OUTPUT:
    Output is the sum of all Ullaru numbers between 1 to 99,999.

    A KEY, WHICH TAKES YOU TO THE NEXT LEVEL.
        KEY: XXXpn

CORRECT OUTPUT: vtrpn
*/

#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}

void ullaruNum(int q)
{
    long long a = 0;
    for (long long n = 1; n <= q; n++) //// bug here i is int instead of long long
    {
        //int n=q;

        long long sqr_n = n * n; // int in bugs
                                 //   if(n == 1)              Line 38 and 39 to be removed in bugs otherwise '1' will be added to the sum whereas the program itself checks for 1 and adds it to sum
                                 //      a+=n;

        // Count number of digits in square

        long long ctr_digits = 0; // ctr_digit = 0 in bugs
        while (sqr_n)
        {
            ctr_digits++; ///////// SYNTAX BUG HERE `+` instead of `++` ///////////
            sqr_n /= 10;
        }

        // Recompute square as it was changed

        sqr_n = n * n;

        // Split the square at different poitns and see if sum of any pair of splitted numbers is equal to n.
        long long r_digits = (ctr_digits + 1) / 2;
        long long eq_parts = power(10, r_digits); ////////////////// SYNTAX BUG HERE `;` instead of `,` /////////////
        // To avoid numbers like 10, 100, 1000 (These are not ullaru numbers).
        long long sum = (sqr_n / eq_parts) + (sqr_n % eq_parts);

        // Find sum of current parts and compare with n; if equal the nits a ullaru number and is added to the sum.
        if (sum == n)
        {
            //printf("%d ",sum);
            a += sum;
        }
    }
    //printf("\n %lld ",a); /// 81773
    hash(a);
}

int main()
{
    ullaruNum(Q);
    return 0;
}

