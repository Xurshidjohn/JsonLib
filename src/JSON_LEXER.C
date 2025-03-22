#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../include/JSON_LEXER.H"
#include "../include/SWS.H"

TOKEN tokens[100] = {};
int token_i = 0;
void init_json(char *JSON_DATA){
    JSON_DATA = SKIP_WHITE_SPACE(JSON_DATA);
    int i = 0;
    while(JSON_DATA[i] != '\0') {
        TOKEN token;
        switch(JSON_DATA[i]){
            case '{':
                token.type = 4;
                token.value = JSON_DATA[i];
                break;
            case '}':
                token.type = 5;
                token.value = JSON_DATA[i];
                break;
            default:
                printf("%c", JSON_DATA[i]);
                break;
        }
        i++;
    }
}

int main() {
    init_json("{\"username\": \"Xurshid\", \"age\": 16}");
}