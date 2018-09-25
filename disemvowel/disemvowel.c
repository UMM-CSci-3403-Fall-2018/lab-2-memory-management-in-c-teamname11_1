#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "disemvowel.h"

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


int determineLength(char *str) {
int count = 0;

for(unsigned int i = 0; i < strlen(str); i++) {
	if (str[i] != isVowel(str[i])) {
		count++;
		}
	}
	return count;
}

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
	disemvoweledStr[size] = '\0';

	return disemvoweledStr;
}



char *disemvowel(char *str) {
	int strlen = 0;
	char* disemvoweledStr;

	strlen = determineLength(str);
	disemvoweledStr = copyNonVowels(strlen, str);

  return disemvoweledStr;
}

