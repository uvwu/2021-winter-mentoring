#include "view.h"
#include "model.h"
#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>

int main() {
    int key;
    tetris *model = tetris_alloc();
    int board[BOARD_HEIGHT][BOARD_WIDTH];
    int block[BLOCK_LEN][BLOCK_LEN];
    int next_block[BLOCK_LEN][BLOCK_LEN];
    int hold_block[BLOCK_LEN][BLOCK_LEN];
    bool new_block_needed = false;

    initscr();
    keypad(stdscr, true);
    noecho();
    timeout(1000);
    curs_set(false);
    
    while (1) {
        tetris_get_board(model, board);
        tetris_get_block(model, block);
        tetris_get_next_block(model, next_block);
        tetris_get_hold_block(model, hold_block);
        
        key = getch();
        // printf("%d\n", key);
        switch (key)
        {
        case KEY_UP:
            render_msg("up  ");
            break;
        case KEY_DOWN:
            render_msg("down ");
            break;
        case KEY_LEFT:
            render_msg("left ");
            break;
        case KEY_RIGHT:
            render_msg("right");
            break;
        default:
            break;
        }
        refresh();
        tetris_update_board(model, board);
        render_board(model->board);
        render_next_block(model->block);

        if (new_block_needed)
            tetris_needs_new_block(model);
    }

    endwin();

    tetris_free(model);
}
