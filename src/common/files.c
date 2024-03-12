#include "files.h"

ErrorCode get_file_path(char *file_path) {
    fgets(file_path, MAX_FILE_PATH_LEN, stdin);
    if (strlen(file_path) < 1) {
        return INVALID_INPUT;
    }
    if (file_path[strlen(file_path) - 1] == '\n') {
        file_path[strlen(file_path) - 1] = '\0';
    }
    return OK;
}

FILE *open_file(const char *file_path, const char *mode) {
    FILE *pfile = fopen(file_path, mode);
    if (pfile == NULL) {
        puckxit();
    }
    return pfile;
}