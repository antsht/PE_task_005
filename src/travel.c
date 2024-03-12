#include "travel.h"

int main(void) {
    char file_path[MAX_FILE_PATH_LEN + 1] = {0};
    try(get_file_path(file_path));
    point_t cities[MAX_CITY_COUNT];
    int city_count = 0;
    try(read_cities_from_file(file_path, cities, &city_count));
    try(fill_travel_time_between_cities(cities, city_count));
    fill_rest_points(cities, city_count);
    print_cities(cities, city_count);
    printf("%d", total_travel_time(cities, city_count));

    return 0;
}

ErrorCode read_cities_from_file(char *file_path, point_t *cities, int *city_count) {
    FILE *pfile = open_file(file_path, "r");
    char line[MAX_LINE_LEN + 1] = {0};
    while (fgets(line, MAX_LINE_LEN, pfile) != NULL) {
        if (sscanf(line, "%255s %d %d", cities[*city_count].name, &cities[*city_count].x,
                   &cities[*city_count].y) != 3)
            return INVALID_DATA;
        cities[*city_count].need_to_rest = false;
        cities[*city_count].travel_time_from_previous_city = 0;
        (*city_count)++;
        if (*city_count == MAX_CITY_COUNT) {
            fclose(pfile);
            return BUFFER_OVERFLOW;
        }
    }
    fclose(pfile);
    if (*city_count < 2) return INVALID_DATA;
    return OK;
}

int travel_time_between_cities(point_t city1, point_t city2) {
    int distance = abs(city2.x - city1.x) + abs(city2.y - city1.y);
    int travel_time = (int)(ceil((double)distance / SPEED_KM_HRS));
    return travel_time;
}

ErrorCode fill_travel_time_between_cities(point_t *cities, int city_count) {
    for (int i = 1; i < city_count; i++) {
        cities[i].travel_time_from_previous_city = travel_time_between_cities(cities[i - 1], cities[i]);
        if (cities[i].travel_time_from_previous_city > 8) return IMPOSSIBLE_ROUTE;
    }
    return OK;
}

void fill_rest_points(point_t *cities, int city_count) {
    int travel_time = 0;
    for (int i = 1; i < city_count; i++) {
        travel_time += cities[i].travel_time_from_previous_city;
        if (travel_time > MAX_TRAVEL_TIME_HRS) {
            cities[i - 1].need_to_rest = true;
            travel_time = cities[i].travel_time_from_previous_city;
        }
    }
}

void print_cities(point_t *cities, int city_count) {
    for (int i = 0; i < city_count; i++) {
        if (i == 0 || i == city_count - 1 || cities[i].need_to_rest) printf("%s\n", cities[i].name);
    }
}

int total_travel_time(point_t *cities, int city_count) {
    int total_travel_time = 0;
    for (int i = 1; i < city_count; i++) {
        total_travel_time += cities[i].travel_time_from_previous_city;
        if (cities[i].need_to_rest) total_travel_time += REST_TIME_HRS;
    }
    return total_travel_time;
}