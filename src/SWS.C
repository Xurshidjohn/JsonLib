#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../include/SWS.H"

char* SKIP_WHITE_SPACE(char *TEXT) {
	if(TEXT[0] == '\0') {
		return ERROR_NULL_TEXT;
	} else if(TEXT[0] != '\0') {
		char *TEXT_BASE = (char*)malloc(strlen(TEXT) +1);
		int i = 0, TEXT_ID = 0;

		while(TEXT[i] != '\0') {
			if(!isspace(TEXT[i])){
				TEXT_BASE[TEXT_ID] = TEXT[i];
				TEXT_ID++;
				i++;
			} else {
				i++;
			}
		}

		return TEXT_BASE;
	}

}
