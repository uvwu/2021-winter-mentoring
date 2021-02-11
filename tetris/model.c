#include "model.h"
#include <stdlib.h>

const int blocks[][4][4] = {
    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
    },
    {
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
    },
    {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
    },
    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    },
};

tetris *tetris_alloc(void) {
    tetris *this = malloc(sizeof(tetris));

    for (int y = 0; y < 14; y++) {
        this->board[y][0] = 1;
        this->board[y][9] = 1;
    }

    for (int x = 0; x < 10; x++) {
        this->board[0][x] = 1;
        this->board[13][x] = 1;
    }
}

void tetris_free(tetris *this) {
    free(this);
}

void tetris_put_block(tetris *this, int block[4][4], int y, int x) {

}

void tetris_get_block(tetris *this, int **block) {

}
