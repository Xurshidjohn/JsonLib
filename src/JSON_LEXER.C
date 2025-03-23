#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../include/JSON_LEXER.H"
#include "../include/SWS.H"
#define MAX_KEY_LENGTH 100  // Key_buffer ning maksimal o'lchami


TOKEN tokens[100] = {};
int token_i = 0, key_buffer_count = 0, in_key=0;
char *key_buffer = (char*)malloc(200 * sizeof(char*));


char* key_filter(TOKEN tokens[]) {
    // {"username": "Xurshid", "age": 16}
    int i = 0, flag = 0;
    while (i < 120 && tokens[i].value != '\0') { 
        if(tokens[i].value == '"') {
            if(in_key == 0) {
                in_key = 1;
                key_buffer_count = 0;

            } else if(in_key == 1) {
                in_key = 0;
                if(tokens[i+1].value == ':') {
                    printf("bu key: %s\n", key_buffer);
                    key_buffer_count = 0;
                    key_buffer[0] = '\0';
                }
            } 
        } else if(in_key == 1 && key_buffer_count < MAX_KEY_LENGTH - 1) {
            key_buffer[key_buffer_count] = tokens[i].value;
            key_buffer_count++;
        }
        i++;
    }
    return "salom";
}

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
                token.type = JSON_LBRAC;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            case '}':
                token.type = JSON_RBRAC;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            case '"':
                token.type = JSON_QUOTE;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            case ':':
                token.type = JSON_COLON;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            case ',':
                token.type = JSON_COMMA;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
            default:
                token.type = JSON_UNKNOWN;
                token.value = JSON_DATA[i];
                tokens[token_i] = token;
                token_i++;
                break;
        }
        i++;
    }
}

int main() {
    init_json("{\"username\": \"Xurshid\", \"age\": \"16\", \"isMarried\": \"false\"}");

    key_filter(tokens);
}

// {"username": "Xurshid", "age": 16}
