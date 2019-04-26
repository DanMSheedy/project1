#include <stdio.h>
#include <math.h>
#include <string.h>
#define MOD(a,b) ((((a)%(b))+(b))%(b));	 //Useful because the % operator in C doesn't behave correctly with negative integers.


//FUNCTION PROTOTYPES

void List(char *a, int pn);                             // Used to list elements in an array: a is the array, pn is the number of elements to print (from [0]).
void EncryptRotation(char *m,int key,char *em);         // Used to encrypt via rotation method, with a key: m is the message array, key is the encryption key, em is the output encrypted array.
void DecryptRotation(char *m, int key,char *dm);        // Used to decrypt via rotation method, with a key: m is the message array, key is the encryption key. dm is the output decrypted array.
void LetterFrequencyDistribution( char *m, int *lfdm);	// Used to list the frequencies of letters in message in a single string, lfdm. Array m is the message input, array lfdm is the destination output for the letter frequency distribution of the message.
char MostOccurringLetter(int *lfdm);                    // Array lfdm is the letterFrequencyDistribution input, and function will output the char which has the highest frequency.
char SecondMostOccurringLetter(int *lfdm);              // Array lfdm is the letterFrequencyDistribution input, and function will output the char which has the 2nd highest frequency.
char ThirdMostOccurringLetter(int *lfdm);               // Array lfdm is the letterFrequencyDistribution input, and function will output the char which has the 3rd highest frequency.

//OTHER DECLARATIONS (move to a #define statement?)

static char alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


//MAIN PRORGAM

int main()
{
//    menu:   //Loop back to main menu
    printf("|    Welcome to Daniel Sheedy's Cyptographic Cipher Collection!    |\n");
    printf("|        ~ Submitted as an ENG1003 Programming Assignment ~        |\n\n");
    printf("                               MENU:                               \n\n");
    printf("                 \u2023 1.   Rotation Cipher                        \n");
    printf("                 \u2023 2.   Substitution Cipher                    \n");
    
    // VARIABLES
    char enterKey, menuInput[20], m[600], em[600], dm[600], EncryptionOrDecryption, EncryptionOrDecryption_Input[20], KeyOrNoKey, KeyOrNoKey_Input[20];
	int menuOption=0, continue_BelowMenu_Prompt=1, continue_EncryptionOrDecryption_Prompt=1, continue_KeyOrNoKey_Prompt=1, continue_Key_Prompt=1, key, lfdm[26] = {0};
	// Note to self: Explain each variable?
	
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
	    
	    case 1:
            printf("\n\n|                      ~ ROTATION CIPHER ~                         |\n\n");
            break;

	    case 2:
            printf("\n\n|                    ~ SUBSTITUTION CIPHER ~                       |\n\n");
            break;

		default:
            break;
       }
    
    EncryptingOrDecrypting_prompt:
			
		while(continue_EncryptionOrDecryption_Prompt == 1) {
            printf("Are you encrypting or decrypting? <E,D>: \n");
            fgets(EncryptionOrDecryption_Input, sizeof(EncryptionOrDecryption_Input), stdin);
            sscanf(EncryptionOrDecryption_Input,"%c%c", &EncryptionOrDecryption, &enterKey);
                
            if ((EncryptionOrDecryption =='E' || EncryptionOrDecryption == 'D') && (enterKey = '\n')) {
                 continue_EncryptionOrDecryption_Prompt = 0;
            }
            else {
                printf("\n*** Warning: Please enter a character E or D***\n");
                goto EncryptingOrDecrypting_prompt;
                break;
            }
        }
        
    switch(menuOption) {
	    
	    case 1:
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
            break;

	    case 2:
                                                                     // This space is for the substitution key.
            break;

		default:
            break;
    }
	
	printf("Enter a message to ");
	if(EncryptionOrDecryption=='E') {
	    printf("encrypt: \n");
	}
	else {
	    printf("decrypt: \n");
	}
    fgets(m, sizeof(m)/sizeof(char), stdin);
		for(int i = 0; m[i] != '\0'; ++i){
            char letter = m[i];
    
            if(letter >='a' && letter <= 'z') {
                letter = letter - 32;                                // Converts lowercase to uppercase.
            }
            m[i] = letter;
        }
	
	switch(menuOption) {
	    
	    //Rotation Cipher
		case 1:
			
			if (EncryptionOrDecryption =='E') {                      // Encryption (using a key)
			    EncryptRotation(m, key, em);
                printf("Rotation Encrypted message: %s \n", em);
                printf("\nFrom the orginal message: \n %s \n", m);
			}
			
			else {                                                   // Decryption (using a key)
			    if (KeyOrNoKey == 'Y') {
                    DecryptRotation(m, key, dm);                     // IMPORTANT!!! This cipher key is the orignial cipher key which was used to rotate the uncoded message into the coded message.
                    printf("Rotation Decrypted message: \n %s \n", dm);
                    printf("\nFrom the orginal message: \n %s \n", m);
			    }
			    else {                                               // Decryption (without a key)
			        LetterFrequencyDistribution(m, lfdm);
			        key = MOD((MostOccurringLetter(lfdm)-'E'), 26);  // Assumes that the most occurring letter in the (translated) message will be 'E', and whereby the key is found. Not sure why this calculation works - but it does ^_^.
			        printf("\nThe most occuring letter in the entered message is: %c \n", MostOccurringLetter(lfdm));
			        printf("The second Most occuring letter in the entered message is: %c \n", SecondMostOccurringLetter(lfdm));
			        printf("The third most occuring letter in the entered message is: %c \n", ThirdMostOccurringLetter(lfdm));
			        printf("\nBased on the letter 'E' occuring most in the English language; we presume that \nthe letter 'E' was encrypted to '%c'. ", MostOccurringLetter(lfdm));
			        printf("This implies an original encryptipon key of %d.\n\n", key);
			        DecryptRotation(m, key, dm);
			        printf("Rotation Decrypted message: \n %s \n", dm);
			        printf("\nFrom the orginal message: \n %s \n", m);
			        
			        // Question asking if this text is recognizable, if not, then assume 'E' is congruent to 2nd most occuring leter. 
			        // Question to printf all possible combinations
			        
			        
			        
			    }
			}
            
			break;
			
			
        //Substitution Cipher
		case 2:
			
			
			
			break;
			
		default:
            break;


	}
	
	// Temporary
	printf("\n");
    LetterFrequencyDistribution(m, lfdm);                            // m - input: message.
                                                                     // lfdm - output: letter frequency distribution of message.
   
	for (int i=0; i<26; i++) {                                       // Temporary ***
			printf("%c : %d \n", alphabet[i], lfdm[i]);
		}
		
	printf("\nMost occuring letter: %c", MostOccurringLetter(lfdm));  // Temporary ***
	printf("\nSecond most occuring letter: %c", SecondMostOccurringLetter(lfdm));  // Temporary ***
	printf("\nThird most occuring letter: %c", ThirdMostOccurringLetter(lfdm));  // Temporary ***
    
    return 0;
}


//FUNCTION DEFINITIONS

void List( char *a, int pn)                         // Used to list arrays out as readable text.
{
    for(int x=0; x<pn; x++)
    {
        printf("%c", *a);
        a++;
    }
	printf("\n");
}

void EncryptRotation(char *m, int key, char *em)    // Used to encrypt an array using the rotation cipher method with a key.
{
    key = MOD(key,26);								// Used instead of key%26 to allow negative keys.
	for(int i = 0; m[i] != '\0'; ++i){
        char letter = m[i];
        
		if(letter >= 'A' && letter <= 'Z'){			// This if statement means that if a user enters a non-CAPITAL
		  letter = letter + key;					// character then this function does nothing to the array element.
													// I.e doesn't 'break' it and produce a bizzare output.
		  if(letter > 'Z'){                         // This brings back, ASCII character's beyond 'Z', into the bounds
			letter = letter -('Z' - 'A' + 1);       // of 'A' to 'Z'.
		  }
    	}
			
		em[i] = letter;
	}
}
	
void DecryptRotation(char *m, int key, char *dm)    // Used to decrypt an array using the rotation cipher method with a key.
{
    key = 26-MOD(key,26);							// Used instead of key%26 to allow negative keys.
	for(int i = 0; m[i] != '\0'; ++i){
        char letter = m[i];
        
		if(letter >= 'A' && letter <= 'Z'){			// This if statement means that if a user enters a non-CAPITAL
		  letter = letter + key;					// character then this function does nothing to the array element.
													// I.e doesn't 'break' it and produce a bizzare output. 
		  if(letter > 'Z'){                         // This brings back, ASCII character's beyond 'Z', into the bounds
			letter = letter -('Z' - 'A' + 1);       // of 'A' to 'Z'.
		  }
	    }
			
		dm[i] = letter;
	}
}

void LetterFrequencyDistribution( char *m, int *lfdm) {
    int n = 0;                                      // Initialize message character counter.
	int i =0;                                       // Initialize alphabet letter counter.
	
	while (m[n] != '\0') {                          // To count to the end of the message.
		for (i=0; i<26; i++) {                      // To count through alphabet.
			if(m[n]==alphabet[i]) {                 // If at a position in the message, the character is equal to some letter in the alphabet, 
				lfdm[i]++;                          // then add 1 to the frequency of that letter.
			}
		}
		n++;                                        // Move along to the next character in the message.
	}
}

char MostOccurringLetter(int *lfdm) {
    int n = 0;                                      // Initialize counter to run through lfdm.
	int HF = 0;		                                // Highest Frequency (of all letters).
	int L = 0;	                                    // Position (in the alphabet) value of the letter with the HF.
	
	for(n=0; n<26; n++) {
		if (lfdm[n] > HF) {
			HF = lfdm[n];
			L = n;                                  // Set current letter to be the most occurring (so far).
		}
	}
	
	return alphabet[L];
}

char SecondMostOccurringLetter(int *lfdm) {
    int n = 0;                                      // Initialize counter to run through lfdm.
    
    int HF = 0;		                                // Highest Frequency (of all letters).
	
	int SecondHF = 0;		                        // Second Highest Frequency (of all letters).
	int SecondL = 0;	                            // Position (in the alphabet) value of the letter with the 2nd HF.
	
	//Finds most occurring letter's location point.
	for(n=0; n<26; n++) {                          
		if (lfdm[n] > HF) {
			HF = lfdm[n];
		}
	}
	
	//Finds second most occurring letter's location point.
	for(n=0; n<26; n++) {
		if ((lfdm[n] > SecondHF) && !(lfdm[n] >= HF)) {
			SecondHF = lfdm[n];
			SecondL = n;                            // Set current letter to be the most occurring (so far) - which is not the most occurring.
		}
	}
	
	return alphabet[SecondL];
}

char ThirdMostOccurringLetter(int *lfdm) {
    int n = 0;                                      // Initialize counter to run through lfdm.
    
    int HF = 0;		                                // Highest Frequency (of all letters).
	
    int SecondHF = 0;		                        // Second Highest Frequency (of all letters).
	    
	int ThirdHF = 0;		                        // Third Highest Frequency (of all letters).
	int ThirdL = 0;	                                // Position (in the alphabet) value of the letter with the 3rd HF.
	
	//Finds most occurring letter's location point.
	for(n=0; n<26; n++) {                          
		if (lfdm[n] > HF) {
			HF = lfdm[n];
		}
	}
	
	//Finds second most occurring letter's location point.
	for(n=0; n<26; n++) {
		if ((lfdm[n] > SecondHF) && !(lfdm[n] >= HF)) {
			SecondHF = lfdm[n];
		}
	}
	
	//Finds Third Most Occurring letter's location point.
	for(n=0; n<26; n++) {
		if ((lfdm[n] > ThirdHF) && !(lfdm[n] >= SecondHF)) {
			ThirdHF = lfdm[n];
			ThirdL = n;                             // Set current letter to be the most occurring (so far) - which is not the most, or second most, occurring.
		}
	}
	
	return alphabet[ThirdL];
}