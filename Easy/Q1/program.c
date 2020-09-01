/*

Problem Statement: 
    1. Paris Hilton is trying out coding. She wants to write a code in c that calculates the SUM.
    2. She defines SUM as the sum of all even numbers upto given input if input is EVEN and/or sum of all odd numbers upto given input if input is ODD.
    3. Unfortunately paris is learning all about C by herself so her program has a few bugs.
    4. Help her correct the bugs and Paris Hilton may give you her autograph! Oh and a KEY (to her heart!) Nah it's a key that helps you proceed to the next level. 

INPUT:
    This is already handled for you. You don't need to do anything for the input.

OUTPUT:
    The output of the hash function after correcting the bugs is your key to enter into website.
    
FORMAT: xxxxxxxx08


GOOD LUCK! 
MAY THE BUG BE WITH YOU
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "helpers.h"


int funct(n)
{
    if(n==0) 
    {
        return 0;
    }
    return n+funct(n-2);
}

int main()
{
    int num,ans
    num=getNum();       
    ans=funct(num);

    
    ////////////   DONT TOUCH BELOW CODE, ITS CORRECT ///////////////////
    
    char arr[100];
    ouritoa(ans,arr,10);
    printf("KEY : %u",hash(arr));
}





