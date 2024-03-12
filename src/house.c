#include "house.h"

int main(void) {
    house_t house = {.n = 0, .k = 0, .h = 0, .s = 0};
    try(input_data(&house));
    try(check_finances(house));
    return 0;
}

ErrorCode input_data(house_t *house) {
    if (!(scanf("%d %d %d %d", &house->n, &house->k, &house->h, &house->s) == 4)) return INVALID_INPUT;
    return OK;
}

ErrorCode validate_data(house_t house) {
    if (house.n <= 0 || house.k <= 0 || house.h <= 0 || house.s < 0) return INVALID_DATA;
    return OK;
}

int calculate_house_cost(house_t house) {
    try(validate_data(house));
    int build_cost = 0;
    build_cost += house.n * house.k * 1000;
    build_cost += house.n * house.h * 500 * 2;
    build_cost += house.k * house.h * 500 * 2;
    build_cost += (house.n * house.k * 700) + house.h * 100;
    return build_cost;
}

ErrorCode check_finances(house_t house) {
    int build_cost = calculate_house_cost(house);
    if (build_cost > house.s)
        printf("NO %d", build_cost - house.s);
    else
        printf("YES");
    return OK;
}