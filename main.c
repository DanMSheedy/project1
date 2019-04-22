#include <stdio.h>
#include <math.h>
#include <string.h>
#define MOD(a,b) ((((a)%(b))+(b))%(b));	 //Useful because the % operator in C doesn't behave correctly with negative integers.

//FUNCTION PROTOTYPES

void List( char *a, int pn);                        // a is the array, pn is the number of elements to print (from [0])
void EncryptRotation(char *m,int key);              // m is the array to encrypt, key is the encryption key
void DecryptRotation(char *m, int key);             // m is the array to decrypt, key is the encryption key

//MAIN PRORGAM

int main()
{
    menu:   //Loop back to main menu
    printf("|    Welcome to Daniel Sheedy's Cyptographic Cipher Collection!    |\n");
    printf("|        ~ Submitted as an ENG1003 Programming Assignment ~        |\n\n");
    printf("                               MENU:                               \n\n");
    printf("                 \u2023 1.   Rotation Cipher                        \n");
    printf("                 \u2023 2.   Substitution Cipher                    \n");
    
    char enterKey, menuInput[20], m[300], EncryptionOrDecryption, EncryptionOrDecryption_Input[20], KeyOrNoKey, KeyOrNoKey_Input[20];
	int menuOption=0, continue_BelowMenu_Prompt=1, continue_EncryptionOrDecryption_Prompt=1, continue_KeyOrNoKey_Prompt=1, continue_Key_Prompt=1, key;
	
	BelowMenu_Prompt:
	
	while(continue_BelowMenu_Prompt == 1) {
		printf("\nEnter an option: ");
		fgets(menuInput, sizeof(menuInput), stdin);
		sscanf(menuInput,"%d%c", &menuOption, &enterKey);
		if ((menuOption==1 || menuOption==2) && (enterKey = '\n')) {
			continue_BelowMenu_Prompt = 0;
		}
		else {
			printf("\n*** Warning: Please enter an integer 1 or 2***\n");
			goto BelowMenu_Prompt;
			break;
		}
	}
	
	
	switch(menuOption) {
	    
	    //Rotation Cipher
		case 1:
			printf("\n\n|                      ~ ROTATION CIPHER ~                         |\n\n");
			
			RotationCipher_EncryptingOrDecrypting_prompt:
			
			while(continue_EncryptionOrDecryption_Prompt == 1) {
                printf("Are you encrypting or decrypting? <E,D>: \n");
                fgets(EncryptionOrDecryption_Input, sizeof(EncryptionOrDecryption_Input), stdin);
                sscanf(EncryptionOrDecryption_Input,"%c%c", &EncryptionOrDecryption, &enterKey);
                
                if ((EncryptionOrDecryption =='E' || EncryptionOrDecryption == 'D') && (enterKey = '\n')) {
                    continue_EncryptionOrDecryption_Prompt = 0;
                }
                else {
                    printf("\n*** Warning: Please enter a character E or D***\n");
                    goto RotationCipher_EncryptingOrDecrypting_prompt;
                    break;
                }
            }
			
			RotationCipher_KeyOrNoKey_prompt:
			
			while(continue_KeyOrNoKey_Prompt == 1) {
                printf("Are you using a rotation cipher key? <Y,N>: \n");
                fgets(KeyOrNoKey_Input, sizeof(KeyOrNoKey_Input), stdin);
                sscanf(KeyOrNoKey_Input,"%c%c", &KeyOrNoKey, &enterKey);
                
                if (EncryptionOrDecryption =='E' && KeyOrNoKey == 'N') {
                    printf("\n*** Warning: you are encrypting, you will need a cipher key!\n");
                    goto RotationCipher_KeyOrNoKey_prompt;
                }
                else if ((KeyOrNoKey =='Y' || KeyOrNoKey == 'N') && (enterKey = '\n')) {
                    continue_KeyOrNoKey_Prompt = 0;
                }
                else {
                    printf("\n*** Warning: Please enter a character Y or N***\n");
                    goto RotationCipher_KeyOrNoKey_prompt;
                    break;
                }
            }
            
            if (KeyOrNoKey == 'Y') {
                RotationCipher_Key_Prompt:
                while(continue_Key_Prompt == 1) {
                    if (EncryptionOrDecryption =='D') {
                        printf("             ### IMPORTANT!!! ###\n This cipher key needs to be the ORIGINAL KEY which was used to rotate the UNENCRYPTED message into the ENCRYPTED message!\n");
                        printf(" Otherwise use this formula to find the complementary cipher key:  Original Key = 25 - Key \n");
                    }
                        printf("Enter cipher key: \n");
                
                    if (scanf("%d%c", &key, &enterKey) !=2) {
                        printf("\n*** Warning: Please enter an integer***\n");
                        goto RotationCipher_Key_Prompt;
                        }
                    else {
                        continue_Key_Prompt = 0;
                    }
                }
            }
			
			printf("Enter a message to encrypt (UPPERCASE-only): \n");
            gets(m);
			
			
			if (EncryptionOrDecryption =='E') {                      //Encryption
			    EncryptRotation(m, key);
                printf("Rotation Encrypted message: %s \n", m);
			}
			
			else {                                                   //Decryption
			    if (KeyOrNoKey == 'Y') {
                    DecryptRotation(m, key);                         //IMPORTANT!!! This cipher key is the orignial cipher key which was used to rotate the uncoded message into the coded message.
                    printf("Rotation Decrypted message: %s \n", m);
			    }
			    else {
			        // Output
			    }
			}
            
			break;


		//Substitution Cipher
		case 2:
			printf("\n\n|                    ~ SUBSTITUTION CIPHER ~                       |\n\n");
			break;
		default:
            break;


	}
		
    
    return 0;
}


//FUNCTION DEFINITIONS

void List( char *a, int pn)                         //Used to list arrays out as readable text.
{
    for(int x=0; x<pn; x++)
    {
        printf("%c", *a);
        a++;
    }
	printf("\n");
}

void EncryptRotation(char *m, int key)              //Used to encrypt an array using the rotation cipher method with a key.
{
    key = MOD(key,26);								//Used instead of key%26 to allow negative keys.
	for(int i = 0; m[i] != '\0'; ++i){
        char letter = m[i];
        
        if(letter >='a' && letter <= 'z') {
            letter = letter - ' ';                  //Converts lowercase to uppercase.
        }
        
		if(letter >= 'A' && letter <= 'Z'){			//This if statement means that if a user enters a non-CAPITAL
		  letter = letter + key;					//character then this function does nothing to the array element.
													//I.e doesn't 'break' it and produce a bizzare output.
		  if(letter > 'Z'){                         //This brings back, ASCII character's beyond 'Z', into the bounds
			letter = letter -('Z' - 'A' + 1);       //of 'A' to 'Z'.
		  }
    	}
			
		m[i] = letter;
	}
}
	
void DecryptRotation(char *m, int key)              //Used to decrypt an array using the rotation cipher method with a key.
{
    key = 26-MOD(key,26);							//Used instead of key%26 to allow negative keys.
	for(int i = 0; m[i] != '\0'; ++i){
        char letter = m[i];
        
        if(letter >='a' && letter <= 'z') {
            letter = letter - ' ';                  //Converts lowercase to uppercase.
        }
        
		if(letter >= 'A' && letter <= 'Z'){			//This if statement means that if a user enters a non-CAPITAL
		  letter = letter + key;					//character then this function does nothing to the array element.
													//I.e doesn't 'break' it and produce a bizzare output. 
		  if(letter > 'Z'){                         //This brings back, ASCII character's beyond 'Z', into the bounds
			letter = letter -('Z' - 'A' + 1);       //of 'A' to 'Z'.
		  }
	    }
			
		m[i] = letter;
	}
}