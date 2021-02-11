#ifndef MODEL_H
#define MODEL_H

typedef struct {
    int board[14][10];
    int block[4][4];
    
    // queue *next_block_queue;
} tetris;

tetris *tetris_alloc(void);

void tetris_free(tetris *this);

void tetris_put_block(tetris *this, int block[4][4], int y, int x);

void tetris_get_block(tetris *this, int **block);

#endif /* MODEL_H */
