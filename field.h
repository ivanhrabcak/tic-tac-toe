#ifndef FIELD_H_
#define FIELD_H_

#include <stdbool.h>
#include "util.h"

#define PLAYER_1 1
#define PLAYER_2 2

#define PLAYER_1_STRING "X"
#define PLAYER_2_STRING "O"

#define EMPTY 0

typedef struct field {
    size sz;
    int **field;
} field;

field init_field(size sz);
bool has_won(field f);
bool check_horizontal(field f, position pos);
bool check_vertical(field f, position pos);
bool check_diagonal(field f, position pos);
bool check(field f, position pos);
bool make_turn(field f, int player, position pos);
void show_field(field f);

#endif