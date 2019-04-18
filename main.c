#include <stdio.h>
#include <math.h>
#include <string.h>

void List( char *a, int pn); // a is the array, pl is the number of elements to print (from [0])

void EncryptCaesar(char a*, int key); // a is the array to encrypt, n is the encryption key

int main()
{
    printf("|    Welcome to Daniel Sheedy's Cyptographic Cipher Collection!    |\n");
    printf("|        ~ Submitted as an ENG1003 Programming Assignment ~        |\n\n");
    printf("                               MENU:                               \n\n");
    printf("                 \u2023 1.   Rotation Cipher                        \n");
    printf("                 \u2023 2.   Substitution Cipher                    \n");
    int menuOption=0; char enterKey; char menuInput[200];
	int continueMenuScreen=1;
	Menu:
	while(continueMenuScreen == 1) {
		printf("\nEnter an option: ");
		fgets(menuInput, sizeof(menuInput), stdin);
		sscanf(menuInput,"%d%c", &menuOption, &enterKey);
		if ((menuOption==1 || menuOption==2) && (enterKey = '\n')) {
			continueMenuScreen = 0;
		}
		else {
			printf("\n*** Warning: Please enter an integer 1 or 2***\n");
			goto Menu;
			break;
		}
	}
		
	switch(menuOption) {
		case 1:
			printf("\n\n --===ROTATION CIPHER===-- \n");
			
			char Input[200];
			printf("Enter an input (UPPERCASE only): ");
			scanf("%s", Input); //Seperate words with "_"
//    		char Input[] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
            //ASCI A-Z Alphabet
			int SizeC = strlen(Input); //sizeof(Input)/sizeof(Input[0]);
			List(Input, SizeC);
			break;
			
		case 2:
			printf("\n\n --===SUBSTITUTION CIPHER===-- \n");
			break;
		default:
            break;
	}
		
    
    return 0;
}

void List( char *a, int pn)
{
    for(int x=0; x<pn; x++)
    {
        printf("%c", *a); //         printf("%c", *a+KEY); Will Encrypt!!!
                          //         This has limitations and will not always work correctly,
                          //         especially when moving backwards in a rotation cipher.
        a++;
    }
	printf("\n");
}

void EncryptCaesar(char a*, int key)
{
    
}