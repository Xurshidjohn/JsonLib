#ifndef JSON_LEXER_H
#define JSON_LEXER_H

typedef enum {
    JSON_KEY = 0,
    JSON_VALUE = 1,
    JSON_COLON = 2,
    JSON_COMMA = 3,
    JSON_LBRAC = 4,
    JSON_RBRAC = 5,
} TOKEN_TYPE;

typedef struct {
    int type;
    char *value;
    struct Token *next;
} TOKEN;

TOKEN* init_json(char *JSON_DATA);

#endif
