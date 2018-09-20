#include <stdlib.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  int count = 0;

  for(int i = 0; i < strlen(str); i++) {
  	if(str[i] != isVowel(str[i]) {
		count++;
	} 
  }

  return (char*) "";
}

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
