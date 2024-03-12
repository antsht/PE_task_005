#ifndef MORSE_H
#define MORSE_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "common/errors.h"
#include "common/files.h"

#define MAX_STRING_LENGTH 1024
#define MAX_MORSE_SYMBOL_LENGTH 5
typedef enum { TEXT_TO_MORSE = 1, MORSE_TO_TEXT } encoder_mode_t;

static char *morse_latin_letters_table[26] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                                              "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                                              "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                                              "...-", ".--",  "-..-", "-.--", "--.."};  // [0] == 'a'  [25] ==
                                                                                        // 'z'
static char *morse_digits_table[10] = {"-----", ".----", "..---", "...--", "....-", ".....",
                                       "-....", "--...", "---..", "----."};  // [0] == '0' - [9] == '9'

ErrorCode get_mode(int *mode);
ErrorCode get_string(char *str);
ErrorCode encode_symbol_to_morse(char c, char *morse_symbol);
ErrorCode encode_string_to_morse(char *str, char *morse_string);
ErrorCode decode_symbol_from_morse(char *morse_symbol, char *c);
ErrorCode decode_string_from_morse(const char *morse_string, char *str);
#endif