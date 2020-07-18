#include "field.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    size field_size = {.size_x = 3, .size_y = 3};
    field f = init_field(field_size);
    position pos = {.x = 1, .y = 1};
    make_turn(f, 1, pos);
    show_field(f);
    return 0;
}