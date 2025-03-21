#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../include/JSON_LEXER.H"
#include "../include/SWS.H"

TOKEN tokens[] = {};
int token_i = 0;
TOKEN* init_json(char *JSON_DATA){
    int i = 0;
    JSON_DATA = SKIP_WHITE_SPACE(JSON_DATA);
    while(JSON_DATA[i] != '\0') {
        // shetta qoldin Xurshid! prosta endi tokenlarni ajratib chiqish kere jalla!
    }
    TOKEN *token = (TOKEN*)malloc(sizeof(TOKEN));
}