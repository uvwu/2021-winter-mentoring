#include "view.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int padding_top;
    int padding_left;
    int board[14][10];
} window;

const char view_blocks[][4] = {
    " ",
    "█",
    "░",
    "▓",
};

static void move_cursor(int y, int x) {
    printf("\033[%dd\033[%dG", y, x);
}

window *window_alloc(int padding_top, int padding_left) {
    window *this = malloc(sizeof(window));
    this->padding_top = padding_top;
    this->padding_left = padding_left;

    return this;
}

void window_render(window *this) {
    int by = this->padding_top;
    int bx = this->padding_left;
    int block;
    
    for (int y = 0; y < 14; y++) {
        for (int x = 0; x < 10; x++) {
            move_cursor(by + y, bx + x);
            block = this->board[y][x];
            printf("%s", view_blocks[block]);
        }
    }
}
