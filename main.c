#include <stdio.h>
#include <math.h>

void List( char *a, char b);


//Simple ASCI A-Z Alphabet
int main()
{
     char AlphabetASCII[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
                      78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
                      // A - Z
     List(AlphabetASCII, 26);
     return 0;
}

void List( char *a, char b)
{
    for(int x=0; x<b; x++)
    {
        printf("Value of index [%d] is: %c \n", x, *a);
        a++;
    }
}