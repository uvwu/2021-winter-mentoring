#include "keyboard.h"
#include "view.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    int k;
    window *win = window_alloc(2, 4);

    while (1) {
        window_render(win);
        k = get_key();
        printf("%d", k);
    }
}
