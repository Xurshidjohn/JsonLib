#ifndef JSON_LEXER_H
#define JSON_LEXER_H

typedef enum {
    JSON_KEY = 0,
    JSON_VALUE = 1,
    JSON_COLON = 2,
    JSON_COMMA = 3,
    JSON_LBRAC = 4,
    JSON_RBRAC = 5,
    JSON_UNKNOWN = 6,
    JSON_QUOTE=  7
} TOKEN_TYPE;

typedef struct {
    TOKEN_TYPE type;
    char value;
} TOKEN;

void init_json(char *JSON_DATA);
char* get_token_type(TOKEN_TYPE token_type);

#endif
