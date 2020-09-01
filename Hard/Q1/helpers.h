// THIS FILE DOES NOT HAVE ANY BUGS. DO NOT ALTER THIS. INPUT IS HANDLED THROUGH THIS FILE

#include <stdlib.h>

char *inputArray[5] = {
    "qwertyuioasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjkl",
    "asdfghjkluiopoiumnbvcxzasdfghjklqwertyuiopasdfghjklqwertyuiop",
    "zxcvbnmqwertyuiophjkjhqwertyuiopqazxsedcvfrtgbhujmkioklp",
    "asdfghjklmnbvcxzqwertyuiopmnbvcxzasdfghjklrrreteasdfghjklzaswsxdefgthnu",
    "mnbvcxzlkjhgfdsazxdfyuhgvhjioxcvbnmkjhgfds"
    };

typedef struct
{
    int d;
} longPalin;

longPalin arr[5] = {0};

int pos = 0;

int lps(char *);

void setArray(char *s) //INITIALISING THE ARRAY WITH MAX LENGTH OF LPS FOR EACH STRING GIVEN IN INPUT.
{
    arr[pos].d = lps(s);
    pos++;
}

char* hash(char * res)
{
    int sum = 0;
    int counter = 0;
    while (pos--)
        sum += arr[pos].d;
    if (sum / 3 == 5)
    {
        while (pos < 4)
        {
            res[counter++] = (pos + (sum / 3)) % 26 + 97;
            pos++;
        }
    }
    res[counter] = '\0';
    return res;
}

unsigned int hash2(const char* str)
{
   unsigned int length = strlen(str), a = 63689, b = 378551, i = 0, hash_ = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash_ = hash_ * a + (*str);
      a *= b;
   }

   return hash_;
}