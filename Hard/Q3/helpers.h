/*
	THIS FILE IS ABSOLUTELY BUG FREE. PLEASE DO NOT CHANGE ANYTHING IN THIS FILE.
*/

#include <stdio.h>
#include <string.h>

char simpleHash(int ans) {
    return ans % 26 + 96;
}

unsigned int complexHash(const char* str)
{
   unsigned int length = strlen(str), a = 63689, b = 378551, i = 0, hash_ = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash_ = hash_ * a + (*str);
      a *= b;
   }

   return hash_;
}