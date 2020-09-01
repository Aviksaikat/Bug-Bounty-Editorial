// THIS FILE DOES NOT HAVE ANY BUGS. DO NOT ALTER THIS.
#include <stdio.h>
#define Q 99999

void hash(int r)
{
    if (r / 9 == 48591)
    {
        printf("Key: ");
        int p = (r / 1000) % 26;
        for (int i = 0; i < 5; i++)
        {
            printf("%c", p + 97);
            p -= 2;
        }
        printf("\n");
    }
    else
    {
        printf("Key locked! there are more bugs to squash!\n");
    }
}