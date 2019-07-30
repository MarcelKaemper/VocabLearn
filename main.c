#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char ** argv) {

    initscr();

    int h,w;
    getmaxyx(stdscr, h, w);
    
    WINDOW *win = newwin(h,w,0,0);

    noecho();
    keypad(stdscr, TRUE);

	getch();

    endwin();

    return 0;
}
