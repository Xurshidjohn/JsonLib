#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../include/JSON_LEXER.H"
#include "../include/SWS.H"

TOKEN tokens[100] = {};
int token_i = 0;

char* get_token_type(TOKEN_TYPE token_type) {
    switch(token_type) {
        case JSON_COLON:
            return "JSON_COLON";
            break;
        case JSON_COMMA:
            return "JSON_COMMA";
            break;
        case JSON_LBRAC:
            return "JSON_LBRAC";
            break;
        case JSON_RBRAC:
            return "JSON_RBRAC";
            break;
        case JSON_QUOTE:
            return "JSON_QUOTE";
        default:
            return "JSON_UNKNOWN";
            break;
    }
}

void init_json(char *JSON_DATA){
    JSON_DATA = SKIP_WHITE_SPACE(JSON_DATA);
    int i = 0;
    while(JSON_DATA[i] != '\0') {
        TOKEN token;
        switch(JSON_DATA[i]){
            case '{':
            printf("%c", JSON_DATA[i]);
                token.type = JSON_LBRAC;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            case '}':
            printf("%c", JSON_DATA[i]);
                token.type = JSON_RBRAC;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            case '"':
            printf("%c", JSON_DATA[i]);
                token.type = JSON_QUOTE;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            case ':':
            printf("%c", JSON_DATA[i]);

                token.type = JSON_COLON;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            case ',':
            printf("%c", JSON_DATA[i]);
                token.type = JSON_COMMA;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            default:
                // token.type = JSON_UNKNOWN;
                // token.value = JSON_DATA[i];
                // tokens[token_i] = token;
                // token_i++;
                break;
        }
        i++;
    }
}

int main() {
    init_json("{\"username\": \"Xurshid\", \"age\": \"16\", \"isMarried\": \"false\"}");
    for(int i = 0;i < 100;i++) {
        if(tokens[i].value) {
            printf("\n<Token value='%c' type='%s'>\n", tokens[i].value, get_token_type(tokens[i].type));
        }
    }
    // printf("%d", get_token_type(3));
}

// {"username": "Xurshid", "age": 16}