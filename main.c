#include <stdio.h>
#include <math.h>
#include <string.h>
#define MOD(a,b) ((((a)%(b))+(b))%(b));	 //Useful because the % operator in C doesn't behave correctly with negative integers.

void List( char *a, int pn);             // a is the array, pl is the number of elements to print (from [0])

void EncryptCaesar(char *m, int key);    // a is the array to encrypt, n is the encryption key

int main()
{
    printf("|    Welcome to Daniel Sheedy's Cyptographic Cipher Collection!    |\n");
    printf("|        ~ Submitted as an ENG1003 Programming Assignment ~        |\n\n");
    printf("                               MENU:                               \n\n");
    printf("                 \u2023 1.   Rotation Cipher                        \n");
    printf("                 \u2023 2.   Substitution Cipher                    \n");
    char enterKey, menuInput[200], m[200];
	int continueMenuScreen=1, menuOption=0, key;
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
			
			printf("Enter a message to encrypt (UPPERCASE-only): \n");
            gets(m);
            printf("Enter cipher key: \n");
            scanf("%d", &key);
            EncryptCaesar(m, key);
            
            printf("Caesar Encrypted message: %s \n", m);
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
        printf("%c", *a);
        a++;
    }
	printf("\n");
}

void EncryptCaesar(char *m, int key)
{
    key = MOD(key,26);								//Used instead of key%26 to allow negative keys.
	for(int i = 0; m[i] != '\0'; ++i){
        char letter = m[i];
        
		if(letter >= 'A' && letter <= 'Z'){			//This if statement means that if a user enters a non-CAPITAL
		  letter = letter + key;					//character then this function does nothing to the array element.
		}											//I.e doesn't 'break' it and produce a bizzare output. 
		
		if(letter > 'Z'){                           //This brings back, ASCII character's beyond 'Z', into the bounds
			letter = letter -('Z' - 'A' + 1);       //of 'A' to 'Z'.
		}
			
		m[i] = letter;
		}
	}