#include "field.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    size field_size = {.size_x = 3, .size_y = 3};
    field f = init_field(field_size);
    bool has_somebody_won = false;
    int player = PLAYER_1;
    while (!has_somebody_won) {
        show_field(f);
        int x, y;
        printf("? ");
        scanf("%d %d", &x, &y);
        position chosen_position = {.x = x, .y = y};
        if (!is_correct_move(f, chosen_position)) {
            while (true) {
                printf("bad field.\n");
                printf("? ");
                scanf("%d %d", &x, &y);
                chosen_position = (position) {.x = x, .y = y};
                if (is_correct_move(f, chosen_position)) {
                    break;
                }
            }
        }
        make_turn(f, player, chosen_position);
        has_somebody_won = has_won(f, player);
        player = invert_player(player);
    }
    show_field(f);
    printf("player %d has won!\n", invert_player(player));

    free_field(f);
    return 0;
}