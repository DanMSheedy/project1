#include <stdio.h>
#include <math.h>

void List( char *a, char b);



int main()
{
    printf("|    Welcome to Daniel Sheedy's Cyptographic Cipher Collection!    |\n");
    printf("|        ~ Submitted as an ENG1003 Programming Assignment ~        |\n\n");
    printf("                               MENU:                               \n\n");
    printf("                 \u2023 0.   Rotation Cipher                        \n");
    printf("                 \u2023 1.   Substitution Cipher                    \n");
    
    
     char AlphabetASCII[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
                                78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
                            //ASCI A-Z Alphabet
     List(AlphabetASCII, 0);
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