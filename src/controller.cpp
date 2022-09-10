#include <iostream>
#include <ncurses.h>
#include <string>
using namespace std;
#include "display.cpp"
#include "userInput.cpp"


int main() {
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    display *dis = new display;
    userInput *usr = new userInput;
    WINDOW *tedit = newwin(LINES - 2, COLS - 5, 2, 4);
    dis->lines();
    refresh();

    //ch = getch();
    while(true) {
        
        wborder(tedit,'|', '|', '-', '-', '+', '+', '+', '+');
        //usr->queryInput();
        wrefresh(tedit);
    }
    //endwin();
    return 1;

}

