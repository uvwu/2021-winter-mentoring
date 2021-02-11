#ifndef VIEW_H
#define VIEW_H

typedef struct {
    int padding_top;
    int padding_left;
    int board[14][10];
} window;

window *window_alloc(int padding_top, int padding_left);

void window_update_board(window *this, int board[14][10]);

void window_render(window *this);

#endif /* VIEW_H */
