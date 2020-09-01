#include <stdio.h>

unsigned int hash(const char *str)
{
   unsigned int length = strlen(str);
   unsigned int b = 378551;
   unsigned int a = 63689;
   unsigned int hash_ = 0;
   unsigned int i = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash_ = hash_ * a + (*str);
      a = a * b;
   }

   return hash_;
}