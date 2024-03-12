#ifndef HOUSE_H
#define HOUSE_H

#include <stdio.h>

#include "common/errors.h"

// n - ширина, k - длина, h - высота, s - сумма
typedef struct house_t {
    int n;
    int k;
    int h;
    int s;
} house_t;

ErrorCode input_data(house_t *house);
ErrorCode validate_data(house_t house);
int calculate_house_cost(house_t house);
ErrorCode check_finances(house_t house);
#endif