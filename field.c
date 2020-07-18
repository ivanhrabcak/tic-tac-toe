#ifndef FIELD_C_
#define FIELD_C_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "field.h"
#include "util.h"



field init_field(struct size sz) {
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

bool check_horizontal(field f, position pos) {
    int player = f.field[pos.x][pos.y];
    for (int i = -1; i <= 1; i++) {
        position current_position = {.x = pos.x, .y = pos.y + i};
        if (!is_out_of_bounds(current_position, f.sz)) {
            int current_field = f.field[current_position.x][current_position.y];
            if (current_field != player) {
                return false;
            } 
        }
    }
    return true;
}

bool check_vertical(field f, position pos) {
    int player = f.field[pos.x][pos.y];
    for (int i = -1; i <= 1; i++) {
        position current_position = {.x = pos.x + i, .y = pos.y};
        if (!is_out_of_bounds(current_position, f.sz)) {
            int current_field = f.field[current_position.x][current_position.y];
            if (current_field != player) {
                return false;
            } 
        }
    }
    return true;
}

bool check_diagonal(field f, position pos) {
    int player = f.field[pos.x][pos.y];
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; i <= 1; i++) {
            position current_position = {.x = pos.x + i, .y = pos.y + j};
            if (!is_out_of_bounds(current_position, f.sz)) {
                int current_field = f.field[current_position.x][current_position.y];
                if (current_field != player) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool check(field f, position pos) {
    return check_diagonal(f, pos) || check_vertical(f, pos) || check_horizontal(f, pos);
}

bool has_won(field f) {
    for (int i = 0; i < f.sz.size_x; i++) {
        for (int j = 0; j < f.sz.size_y; j++) {
            int current_field = f.field[i][j];
            position current_position = {.x = i, .y = j};
            if (current_field != 0) {
                if (check(f, current_position)) {
                    return true;
                }
            }
        }
    }
    return false;
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
            if (i != 1) {
                printf("|   %s   |", s);
            }
            else {
                printf("   %s   ", s);
            }
        }
        printf("\n|       |       |       |\n"); 
        printf("-------------------------\n"); 
    }
}
#endif