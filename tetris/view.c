#include "view.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char view_blocks[][4] = {
    " ",
    "□",
    "░",
    "▓",
};

static void move_cursor(int y, int x) {
    printf("\033[%dd\033[%dG", y, x);
}

const int board_by = 4;
const int board_bx = 8;


/**
 * board를 화면에 출력해준다.
 */
void render_board(int board[20][10], int height, int width) {
    int block;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            move_cursor(board_by + y, board_bx + x * 2);
            block = board[y][x];
            printf("%s", view_blocks[block]);
        }
    }
}
