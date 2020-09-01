/**
    THIS FILE IS ABSOLUTELY CORRECT AND HAS NO ERRORS WHATSOEVER
    PLEASE DO NOT TOUCH THIS FILE
*/

#include<stdio.h>
#include<string.h>
int getNum(){
    return 55981;
}

unsigned int hash(const char* str)
{
   unsigned int length = strlen(str);
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash_ = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash_ = hash_ * a + (*str);
      a    = a * b;
   }

   return hash_;
}

void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    while (start < end) 
    { 
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++; 
        end--; 
    } 
} 
char* ouritoa(int num, char* str, int base) 
{ 
    int i = 0; 
    int isNegative = 0; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    if (num < 0 && base == 10) 
    { 
        isNegative = 1; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
} 
