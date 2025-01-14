#include "errors.h"

#include <stdio.h>
#include <stdlib.h>

void try(ErrorCode error) {
    if (error == OK) return;
    if (error == IO_ERROR) {
        log_message("IO ERROR");
        puckxit();
    }
    if (error == NO_DATA) {
        log_message("NO DATA");
        print_no_data_message();
        return;
    }
    if (error == INVALID_DATA) {
        log_message("INVALID DATA");
        puckxit();
    }
    if (error == INVALID_INPUT) {
        log_message("INVALID INPUT");
        puckxit();
    }
    if (error == IMPOSSIBLE_ROUTE) {
        log_message("IMPOSSIBLE ROUTE");
        print_no_impossible_route_message();
        exit(EXIT_SUCCESS);
    }
    if (error == BUFFER_OVERFLOW) {
        log_message("BUFFER OVERFLOW");
        puckxit();
    }
}

void puckxit() {
    fprintf(stderr, "Puck you, Verter!");
    close_logger();
    exit(EXIT_FAILURE);
}

void print_no_data_message() { printf("NO DATA\n"); }

void print_no_impossible_route_message() { printf("Travel is impossible!"); }