#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "disemvowel.h"

// Takes a character and converts it to lowercase.
// If it is a vowel returns true, otherwise false
bool isVowel(char letter) {
        letter = tolower(letter);
        switch(letter) {
                case 'a':
                        return true;
                case 'e':
                        return true;
                case 'i':
                        return true;
                case 'o':
                        return true;
                case 'u':
                        return true;
                default :
                        return false;

        }
}

// Takes a character array, counts the number of non-vowels inside and returns
// this number. This provides the size needed for the returned disemvoweled string
int determineLength(char *str) {
int count = 0;

for(unsigned int i = 0; i < strlen(str); i++) {
	if (str[i] != isVowel(str[i])) {
		count++;
		}
	}
	return count;
}

// Takes the size of the disemvoweled string and the original string
// Allocates memory for the new string, and copies each non-vowel
// into the new string, and increments the index for the position
// in the new string. Returns the disemvoweled string
char *copyNonVowels(int size, char *str) {
	char* disemvoweledStr;
	int j = 0;
	disemvoweledStr = (char*)calloc(size+1, sizeof(char));

	for(int i = 0; i < size; i++) {
	if (!(isVowel(str[i]))) {
		disemvoweledStr[j] = str[i];
		j++;
		}
	}
	disemvoweledStr[j] = '\0';

	return disemvoweledStr;
}


// Upper level function that takes a string to be disemvowled.
// Calls determineLength on the string to find its length and
// uses this value as an argument for its call to copyNonVowels
// which also takes the given string. Returns the disemvowled string
char *disemvowel(char *str) {
	int strlen = 0;
	char* disemvoweledStr;

	strlen = determineLength(str);
	disemvoweledStr = copyNonVowels(strlen, str);

  return disemvoweledStr;
}

