#ifndef UTIL_H_
#define UTIL_H_

#include <stdbool.h>
#include "field.h"

#define sizeof_array(x) sizeof(x) / sizeof(array[0])

typedef struct size {
    int size_x;
    int size_y;
} size;

typedef struct position {
    int x;
    int y;
} position;

bool is_out_of_bounds(position pos, size sz);
void free_field(field f);
#endif