#ifndef FIELD_H_
#define FIELD_H_

#include <stdbool.h>

#define PLAYER_1 1
#define PLAYER_2 2

#define PLAYER_1_STRING "X"
#define PLAYER_2_STRING "O"

#define sizeof_array(x) sizeof(x) / sizeof(array[0])

typedef struct size {
    int size_x;
    int size_y;
} size;

typedef struct position {
    int x;
    int y;
} position;

typedef struct field {
    size sz;
    int **field;
} field;

bool is_out_of_bounds(position pos, size sz);
void free_field(field f);
field init_field(size sz);
bool is_correct_move(field f, position pos);
bool has_won(field f, int player);
bool check_horizontal(field f, int player);
bool check_vertical(field f, int player);
bool check_diagonal(field f, int player);
bool check(field f, int player);
bool make_turn(field f, int player, position pos);
void show_field(field f);
int invert_player(int player);


#endif