#ifndef HOUSE_H
#define HOUSE_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "common/errors.h"
#include "common/files.h"

#define MAX_LINE_LEN 255
#define MAX_CITY_NAME_LEN 50
#define MAX_CITY_COUNT 100
#define SPEED_KM_HRS 60
#define REST_TIME_HRS 8
#define MAX_TRAVEL_TIME_HRS 8

typedef struct point_t {
    char name[MAX_CITY_NAME_LEN];
    int x;
    int y;
    int travel_time_from_previous_city;
    bool need_to_rest;
} point_t;

ErrorCode read_cities_from_file(char *file_path, point_t *cities, int *city_count);
void print_cities(point_t *cities, int city_count);
int travel_time_between_cities(point_t city1, point_t city2);
ErrorCode fill_travel_time_between_cities(point_t *cities, int city_count);
void fill_rest_points(point_t *cities, int city_count);
int total_travel_time(point_t *cities, int city_count);
#endif