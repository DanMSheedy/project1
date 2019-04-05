#include <stdio.h>
#include <math.h>
#include <string.h>

void List( char *a, int pn); // a is the array, pl is the number of elements to print (from [0])


int main()
{
    printf("|    Welcome to Daniel Sheedy's Cyptographic Cipher Collection!    |\n");
    printf("|        ~ Submitted as an ENG1003 Programming Assignment ~        |\n\n");
    printf("                               MENU:                               \n\n");
    printf("                 \u2023 0.   Rotation Cipher                        \n");
    printf("                 \u2023 1.   Substitution Cipher                    \n");
    
    char Input[200];
	printf("Enter an input (UPPERCASE only): ");
	scanf("%s", Input); //Seperate words with "_"
//    char Input[] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
                //ASCI A-Z Alphabet
	int SizeC = strlen(Input); //sizeof(Input)/sizeof(Input[0]);
    List(Input, SizeC);
    return 0;
}

void List( char *a, int pn)
{
    for(int x=0; x<pn; x++)
    {
        printf("%c", *a+2); //         printf("%c", *a+KEY); Will Encrypt!!!
        a++;
    }
	printf("\n");
}