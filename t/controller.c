#include "view.h"
#include "model.h"
#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>

int main() {
    int key;
    tetris *model = tetris_alloc();
    bool new_block_needed = false;
    tetris_set_needs_new_block(model);
    
    initscr();
    keypad(stdscr, true);
    noecho();
    timeout(1000);
    curs_set(false);
    int xx=4;int yy=0;
    
    while (1) {
        
        key = getch();
        switch (key)
        {
        case KEY_UP:
            render_msg("up   ");
            if( 0<yy)
                yy--;
            break;
        case KEY_DOWN:
            render_msg("down ");
            if( yy<14)
                 yy++;
            break;
        case KEY_LEFT:
            render_msg("left ");
            if(0<xx)
                xx-=2;
            break;
        case KEY_RIGHT:
            render_msg("right");
            if(xx<10)
                xx+=2;
            break;
        case 'q':
        case 'Q':
            goto FIN;
        default:
            break;
        }
        render_board(model->board);
        if(yy==14){
            tetris_set_needs_new_block(model);
            yy=0,xx=4;
        }
        render_hold_block(model->block,yy,xx);
        render_next_block(model->next_block);
        refresh();

        // if (new_block_needed) {
         //   tetris_set_needs_new_block(model);
        // }
    }

FIN:
    endwin();

    tetris_free(model);
    return 0;
}
