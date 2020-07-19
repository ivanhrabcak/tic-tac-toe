#ifndef FIELD_C_
#define FIELD_C_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "field.h"

bool is_out_of_bounds(position pos, size sz) {
    return pos.x < 0 || 
        pos.y < 0 ||
        pos.x > sz.size_x ||
        pos.y > sz.size_y;

}

void free_field(field f) {
    free(f.field);
}

bool is_correct_move(field f, position pos) {
    if (is_out_of_bounds(pos, f.sz)) {
        return false;
    }
    else if (!(f.field[pos.x][pos.y] == 0)) {
        return false;
    }
    return true;
}

field init_field(size sz) {
    int **f = (int**) malloc(sz.size_x * sizeof(int));
    for (int i = 0; i < sz.size_x; i++) {
        int *line = (int*) malloc(sz.size_y * sizeof(int));
        for (int j = 0; j < sz.size_y; j++) {
            line[j] = 0;
        }
        f[i] = line;
    }
    field fi = {.sz = sz, .field = f};
    return fi;
}

bool check_vertical(field f, int player) {
    int counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (f.field[j][i] != player) {
                counter = 0;
            }
            else {
                counter++;
            }
        }
        if (counter == 3) {
            return true;
        }
        counter = 0;
    }
    return false;
}

bool check_horizontal(field f, int player) {
    int counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (f.field[i][j] != player) {
                counter = 0;
            }
            else {
                counter++;
            }
        }
        if (counter == 3) {
            return true;
        }
        counter = 0;
    }
    return false;
}

bool check_diagonal(field f, int player) {
    bool in_a_row = true;
    for (int i = 0; i < 3; i++) {
        if (f.field[i][i] != player) {
            in_a_row = false;
        }
    }
    if (in_a_row) {
        return true;
    }
    int n = 0;
    for (int i = 2; i >= 0; i--) {
        if (f.field[n][i] != player) {
            return false;
        }
        n++;
    }
    return true;
}

bool check(field f, int player) {
    return check_diagonal(f, player) || check_vertical(f, player) || check_horizontal(f, player);
}

bool has_won(field f, int player) {
    return check(f, player);
}

bool make_turn(field f, int player, position pos) {
    if (!(f.field[pos.x][pos.y] == 0)) {
        return false;
    }
    f.field[pos.x][pos.y] = player;
    return true;
}

void badly_show_field(field f) {
    for (int i = 0; i < f.sz.size_x; i++) {
        for (int j = 0; j < f.sz.size_y; j++) {
            printf("%d ", f.field[i][j]);
        }
        printf("\n");
    }
}

void show_field(field f) {
    if (f.sz.size_x > 3 || f.sz.size_y > 3) {
        printf("Field bigger than 3x3!\n");
        badly_show_field(f);
        return;
    }
    int **array = f.field;
    
    for (int i = 0; i < 3; i++) {
        printf("-------------------------\n");
        printf("|       |       |       |\n");
        for (int j = 0; j < 3; j++) {
            int current_field = array[i][j];
            char *s = "";
            if (current_field == 1) s = PLAYER_1_STRING;
            else if (current_field == 2) s = PLAYER_2_STRING;
            else s = " "; 
            if (j != 1) {
                printf("|   %s   |", s);
            }
            else {
                printf("   %s   ", s);
            }
        }
        printf("\n|       |       |       |\n");
        if (i == 2) { 
            printf("-------------------------\n"); 
        }
    }
}

int invert_player(int player) {
    if (player == PLAYER_1) {
        return PLAYER_2;
    }
    else {
        return PLAYER_1;
    }
}
#endif