#include "morse.h"

int main(void) {
    int mode = 0;
    try(get_mode(&mode));
    char str[MAX_STRING_LENGTH + 1] = {0};
    try(get_string(str));
    switch (mode) {
        case 1:
            char morse_string[MAX_STRING_LENGTH * MAX_MORSE_SYMBOL_LENGTH + 1] = {0};
            try(encode_string_to_morse(str, morse_string));
            printf("%s", morse_string);
            break;
        case 2:

            char symbol_string[MAX_STRING_LENGTH + 1] = {0};
            try(decode_string_from_morse(str, symbol_string));
            printf("%s", symbol_string);
            break;
        default:
            return INVALID_INPUT;
    }
    return 0;
}

ErrorCode get_mode(int *mode) {
    if (scanf("%d", mode) != 1 || *mode < 1 || *mode > 2) return INVALID_INPUT;
    char c;
    while ((c = getchar()) != '\n') {
        ;
    }
    return OK;
}

ErrorCode get_string(char *str) {
    fgets(str, MAX_STRING_LENGTH, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    if (strlen(str) < 1) return INVALID_INPUT;
    return OK;
}

ErrorCode encode_symbol_to_morse(char c, char *morse_symbol) {
    if (!isalnum(c)) return INVALID_INPUT;
    if (isalpha(c)) {
        int index = tolower(c) - 'a';

        strcpy(morse_symbol, morse_latin_letters_table[index]);
    }
    if (isdigit(c)) {
        int index = c - '0';
        strcpy(morse_symbol, morse_digits_table[index]);
    }
    return OK;
}

ErrorCode encode_string_to_morse(char *str, char *morse_string) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            morse_string[strlen(morse_string) - 1] = '\0';
            strcat(morse_string, "\t");
            i++;
            continue;
        }
        char morse_symbol[MAX_MORSE_SYMBOL_LENGTH + 1] = {0};
        try(encode_symbol_to_morse(str[i], morse_symbol));
        strcat(morse_string, morse_symbol);
        strcat(morse_string, " ");
        i++;
        if (i > MAX_STRING_LENGTH) return INVALID_INPUT;
    }
    if (morse_string[strlen(morse_string) - 1] == ' ') morse_string[strlen(morse_string) - 1] = '\0';
    return OK;
}

ErrorCode decode_symbol_from_morse(char *morse_symbol, char *c) {
    for (int i = 0; i < 26; i++)
        if (strcmp(morse_latin_letters_table[i], morse_symbol) == 0) {
            c[0] = i + 'A';
            return OK;
        }
    for (int i = 0; i < 10; i++)
        if (strcmp(morse_digits_table[i], morse_symbol) == 0) {
            c[0] = i + '0';
            return OK;
        }
    return INVALID_INPUT;
}

ErrorCode decode_string_from_morse(const char *morse_string, char *str) {
    int i = 0;
    while (morse_string[i] != '\0') {
        char morse_symbol[MAX_MORSE_SYMBOL_LENGTH + 1] = {0};
        int j = 0;
        while (morse_string[i] != ' ' && morse_string[i] != '\t' && morse_string[i] != '\0') {
            morse_symbol[j] = morse_string[i];

            i++;
            j++;
        }
        char c[2] = {0};
        try(decode_symbol_from_morse(morse_symbol, c));
        strcat(str, c);
        if (morse_string[i] == '\t') {
            strcat(str, " ");
        }
        i++;
    }
    return OK;
}