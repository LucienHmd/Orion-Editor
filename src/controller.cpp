#include <iostream>
#include <ncurses.h>
#include <string>
using namespace std;
#include "display.cpp"
#include "userInput.cpp"
#include "editor.cpp"

int main() {
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    WINDOW *tedit = newwin(LINES - 2, COLS - 5, 2, 4);

    display *dis = new display;
    userInput *usr = new userInput;
    editor *edit = new editor(tedit, 5, 5);

    
    dis->lines();
    refresh();

    //ch = getch();
    while(true) {
        
        wborder(tedit,'|', '|', '-', ' ', '+', '+', '+', '+');
        char b = usr->queryInput();
        if (b == 'w') {
            edit->cursorUp();
        } else if (b == 'a') {
            edit->cursorLeft();
        } else if (b == 's') {
            edit->cursorDown();
        } else if (b == 'd') {
            edit->cursorRight();
        }
        wrefresh(tedit);
    }
    //endwin();
    return 1;

}

