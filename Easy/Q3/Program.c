/*
PROBLEM STATEMENT:
    1. Lisa is a girl in 5th grade. She wants you to solve a problem that her maths teacher gave 
        her as homework. 
    2. She is given an array of integers from which she has to find the MAXIMUM possible 
        product from a pair of integers (i.e taking any two integers from the array).
    3. You start to write the program for her but it has bugs. Resolve the bugs in it or else Lisa
        won't be able to submit her homework!


INSTRUCTIONS
    1. There are no bugs in the MAIN function, PLEASE DO NOT MODIFY IT.
    2. You are supposed to modify the SOLVE function such that it returns the CORRECT RESULT.

INPUT
    This is already handled for you. An array of integers with the given constraints
    (-1000<=arr[i]<=1000 for 0<=i<1000). 
    YOU DON'T NEED TO WORRY ABOUT THE INPUT

OUTPUT
    The output printed by the hash function is the KEY to enter into website.

FORMAT : xxxxxxxx04              enter this into website.


*/

#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"
// REMOVE THE BUG IN THIS FUNCTION
int solve(int arr[])
{
    int n=1000;
   
    int i,j,temp;
    //sorted  in ascending order.
    for (i = 0, i < n-1, i++)
    {
       for (j = 0, j < n-1, j++)  
       {
           if (arr[j] > arr[j+1]) 
            {
                temp=arr[j];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
       }
    }
    return arr[n]*arr[n-1];         /// Last two numbers
}

//////////////////////// THE CODE BELOW THIS IS CORRECT, DON'T CHANGE IT. IF ANY ERROR OCCURS WHILE READING INPUT FILE, CONTACT US ///////////////////////
int main()
{

    int *numberArray;
    int a[1000];
    numberArray = getArray(a,1000);
    int ans=solve(numberArray);
     //   DONT TOUCH BELOW CODE
    char arr[100];
    ouritoa(ans,arr,10);
    printf("KEY : %u",hash(arr));
}