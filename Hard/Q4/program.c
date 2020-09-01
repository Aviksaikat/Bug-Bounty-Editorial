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


    KEY FORMAT: XXXXXXXX29
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
    char s[MAX], finalMinimumLength[5]; // s[] is the input string. finalMinimumLength[] stores the minimum length of the substring that we need to compute
    FILE *file = fopen("input.txt", "r");
    fgets(s, MAX, file); // The input string is read from the input file
    int n = strlen(s);   // Length of the given input string

    /*
        Let's checkout how the logic works to solve the problem.

        1st thing to notice: The minimum length that we want varies from 3 to n. It can only start from length = 3 since we want 
        1, 2 and 3 to occur at least once in the substring. Length can only go upto n since that's the entire length of the string 
        itself. You can't go beyond that.
        
        2nd thing to notice: Let x be our required minimum length of the substring (again, it lies from 3 to n only). Then even (x+1), 
        (x+2), ......, n also works (just not the minimum length). For the above sample input, the output is 3 which is the minimum 
        length of the substring, but even 4 and 5 works (i.e., you can have a substring of length 4 and 5 too that works) just that 
        it wouldn't be the minimum length. That's why we output 3 instead of 4 or 5.

        So to summarize, you have possible lengths from 3 to n (which is in increasing order) and you want to search for that minimum
        length x such that (x+1), (x+2), ....., n also works (just that it's not the minimum length) and (x-1), (x-2), ....., 3 does not work at all.
        Does that remind you of some famous algorithm that you may have studied before....... Its Binary Search!! This is exactly the type
        of problem where you can apply Binary Search since the possible lengths are sorted and you have to search for x.  
    */
    int l = 3, r = n, currentMinimumLength = INFINITY; // l and r are the lower and upper bounds here for Binary Search. currentMinimumLength stores the length you have found so far that works
    while (l <= r)
    {
        int mid = l + r / 2; // mid stores the mid point between l and r which is the length under investigation

        /*
            To check if mid works (i.e., mid = x or (x+1) or (x+2) ...... n) or not (i.e., mid = (x-1) or (x-2) ...... 3), we are
            making use of a helper method called isValid(). If it returns true, then that mid value works in which case we move to the
            left (by making r = mid-1) to find the minimim length x. If it returns false, then that mid value doesn't work and we move
            to the right (by making l = mid+1) to find the minimum length x.
        */
        if (isValid(s, mid))
        {
            /*
                If our mid value is lesser than the length we have found so far, then we make currentMinimumLength=mid since we want to minimize
                the length.
            */
            if (mid > currentMinimumLength)
                currentMinimumLength = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    // Some hashing stuff which again you don't have to worry about. Just ensure that the correct output is sent to the hash function.
    sprintf(finalMinimumLength, "%d", currentMinimumLength);
    printf("Key : %lu\n", hash(finalMinimumLength));

    // The input file is closed.
    fclose(file);

    return 0;
}

/*
    It's a helper method to check if a substring of this given length 'k' contains 1, 2 and 3 at least once. To accomplish that, we have 
    used a famous technique called the Sliding Window technique. Don't panic if you have never heard of it, it's really easy to understand 
    and use. You may check out GeeksForGeeks or other online resources for a better understanding (Googling stuff you don't understand 
    is an important (and an underrated) skill to have as someone who wants to make a career out of coding)
*/
bool isValid(char s[], int k)
{
    int frequency[3] = {0}; // frequency[] array stores the frequency of the characters 1, 2 and 3 in the substring

    /*
        To begin with this technique, we take the first k characters of the given input string as the substring and find the 
        frequency of each of the characters in that substring
    */
    for (int i = 0; i < k; ++i)
        ++frequency[s[i] - '0'];

    /*
        We now move on to the next k characters (i.e., the next substring) in the given input string and compute the frequency of 
        the characters in it as well. If you observe, to move to the next substring, you just have to remove the leftmost character of the
        current substring and add the next character after the substring to its rightmost. Every other character in between remains 
        the same in both the substrings.
    */
    for (int i = k; i < strlen(s); ++i)
    {
        /*
            If the frequency of the characters 1, 2 and 3 are all atleast equal to 1, then we basically have found a substring with 
            all the 3 characters occurring atleast once. So we can just break from the loop and return true. If we never find such a 
            substring, then we just return false. 
        */
        if (frequency[1] > 0 && frequency[2] > 0 && frequency[3] > 0)
            return true;

        --frequency[s[i] - '0'];
        ++frequency[s[i - k] - '0'];
    }

    if (frequency[1] > 0 && frequency[2] > 0 && frequency[3] > 0)
        return true;

    return false;
}