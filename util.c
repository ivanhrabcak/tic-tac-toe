#ifndef UTIL_C_
#define UTIL_C_

#include <stdbool.h>
#include "util.h"
#include "field.h"
#include <stdlib.h>

bool is_out_of_bounds(position pos, size sz) {
    return pos.x > 0 && 
        pos.y > 0 &&
        pos.x < sz.size_x &&
        pos.y < sz.size_y;

}

void free_field(field f) {
    free(f.field);
}
#endif