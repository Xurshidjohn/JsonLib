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
                tokens[token_i] = token;
                token_i++;
                break;
            case '}':
                token.type = 5;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            case '"':
                token.type = 7;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            case ':':
                token.type = 2;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            case ',':
                token.type = 3;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            default:
                // printf("%c", JSON_DATA[i]);
                break;
        }
        i++;
    }
}

int main() {
    init_json("{\"username\": \"Xurshid\", \"age\": \"16\", \"isMarried\": \"false\"}");
    for(int i = 0;i < 100;i++) {
        if(tokens[i].value) {
            printf("%c", tokens[i].value);
        }
    }
}

// {"username": "Xurshid", "age": 16}