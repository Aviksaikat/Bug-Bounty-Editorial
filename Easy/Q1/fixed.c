/*

Problem Statement: 
    1. Paris Hilton is trying out coding. She wants to write a code in c that calculates the SUM.
    2. She defines SUM as the sum of all even numbers upto given input if input is EVEN and/or sum of all odd numbers upto given input if input is ODD.
    3. Unfortunately paris is learning all about C by herself so her program has a few bugs.
    4. Help her correct the bugs and Paris Hilton may give you her autograph! Oh and a KEY (to her heart!) Nah it's a key that helps you proceed to the next level. 

INPUT:
    This is already handled for you. You don't need to do anything for the input.

OUTPUT:
    The output of the hash fnction after correcting the bugs is your key to enter into website.


     
    KEY: 4056898308 - This is the key to enter in website.

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "helpers.h"

int funct(int n)     //BUG CORRECTED - Data type for input is not defined!!
{
    if(n<=0)  //BUG CORRECTED - Handle edge case for less than zero.
    {
        return 0;
    }
    return n+funct(n-2);
}

int main()
{
    int num,ans; ///// BUG CORRECTED syntax error, missing ";"
    num=getNum();       
    ans=funct(num);
     //   DONT TOUCH BELOW CODE
    char arr[100];
    ouritoa(ans,arr,10);
    printf("KEY : %u",hash(arr));

}







