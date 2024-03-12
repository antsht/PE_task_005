#ifndef ERRORS_H
#define ERRORS_H

#include "logger.h"
typedef enum {
    OK,
    IO_ERROR,
    NO_DATA,
    INVALID_DATA,
    INVALID_INPUT,
    IMPOSSIBLE_ROUTE,
    BUFFER_OVERFLOW
} ErrorCode;

void try(ErrorCode error);
void puckxit();
void print_no_data_message();
void print_no_impossible_route_message();
#endif