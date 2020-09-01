/*
PROBLEM STATEMENT:
    1. Lisa is a girl in 5th grade. She wants you to solve a problem that her maths teacher gave 
        her as homework. 
    2. She is given an array of integers from which she has to find the MAXIMUM possible 
        product from a pair of integers (i.e taking any two integers from the array).
    3. You start to write the program for her but it has bugs. Resolve the bugs in it or else Lisa
        won't be able to submit her homework!

INSTRUCTIONS
    1. There are no bugs in the main function, PLEASE DO NOT MODIFY IT.
    2. You are supposed to modify the SOLVE function such that it returns the CORRECT RESULT.

INPUT
    This is already handled for you. An array of integers with the given constraints
    (-1000<=arr[i]<=1000 for 0<=i<1000). 
    YOU DON'T NEED TO WORRY ABOUT THE INPUT

OUTPUT
    The output printed by the hash function is the KEY TO ENTER INTO WEBSITE.

CORRECT ANSWER
    Number 1 = -998
    Number 2 = -996
    Product = 994008

KEY: 3592703004     enter this into website.

*/

#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"


int solve(int arr[])
{
    int n=1000;
   
    int i,j,temp;
    //sorted  in ascending order.
    for (i = 0; i < n-1; i++) //BUG CORRECTED:  Semi colon instead of comma
    {
       for (j = 0; j < n-i-1; j++)   // BUG CORRECTED - "j < n-i-1" & Semi colon instead of comma
       {
           if (arr[j] > arr[j+1])
            {
                temp=arr[j+1];       //BUG CORRECTED - arr[j+1] should be assigned to temp instead of arr[j]
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
       }
    }
    //BUG CORRECTED - Need to take care when there are negative numbers, 
    //CAN'T just return the product of last two
    if(arr[0]*arr[1]>arr[n-1]*arr[n-2]) 
    {
        return arr[0]*arr[1]; 
    }
    else
        return arr[n-1]*arr[n-2];   

}


//////////////////////// CODE BELOW IS CORRECT, DON'T CHANGE. IF ANY ERROR WITH READING INPUT FILE, CONTACT US ///////////////////////

int main()
{

    int *numberArray;
    int a[1000];
    numberArray = getArray(a,1000);
    int ans=solve(numberArray);
    //printf("%d",ans);
     //   DONT TOUCH BELOW CODE
    char arr[100];
    ouritoa(ans,arr,10);
    printf("KEY : %u",hash(arr));
}

