#include "keyboard.h"
#include <stdio.h>

typedef enum {
    WHITE = 0, BLACK, BLUE, RED, GREEN,
} color;

const color blocks[][4][4] = {
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
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
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

typedef struct {
    color board[10][10];
} tetris;

int main() {
    char k;

    while (1) {
        k = get_key(0);
        putchar(k);
    }  
}
