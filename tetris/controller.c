#include "keyboard.h"
#include "view.h"
#include "model.h"
#include <stdio.h>

int main() {
    int k;
    window *win = window_alloc(2, 4);
    tetris *model = tetris_alloc();

    while (1) {
        window_update_board(win, model->board);
        k = get_key();
        window_render(win);
    }
}
