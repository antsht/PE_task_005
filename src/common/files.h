#ifndef FILES_H
#define FILES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "errors.h"

#define MAX_FILE_PATH_LEN 255

ErrorCode get_file_path(char *file_path);

FILE *open_file(const char *db_path, const char *mode);

#endif