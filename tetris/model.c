#include "model.h"
#include <stdlib.h>
#include <string.h>

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

    for (int y = 0; y < BOARD_HEIGHT; y++) {
        this->board[y][0] = 1;
        this->board[y][BOARD_WIDTH - 1] = 1;
    }

    for (int x = 0; x < BOARD_WIDTH; x++) {
        this->board[0][x] = 1;
        this->board[BOARD_HEIGHT - 1][x] = 1;
    }
    
    return this;
}

void tetris_free(tetris *this) {
    free(this);
}

void tetris_put_block(tetris *this, int block[4][4], int y, int x) {
    for (int i = 0; i < 4; i++)
        memcpy(&this->board[y + i][x], block[i], sizeof(int) * 4);
}

void tetris_get_board(tetris *this, int board[BOARD_HEIGHT][BOARD_WIDTH]) {
    memcpy(board, this->board, sizeof(int) * BOARD_HEIGHT * BOARD_WIDTH);
}

void tetris_get_block(tetris *this, int block[4][4]) {
    // int block_idx = queue_front(this->next_block_queue);
    // memcpy(this->block, blocks[block_idx], sizeof(int) * 16)
}
