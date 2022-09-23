#include <iostream>
#include <ncurses.h>
#include <string>
using namespace std;
#include "display.cpp" 
#include "userInput.cpp"
#include "editor.cpp"
#include "page.cpp"

// cmake -H. -B build

/* Classes

    - Cursor
    - userInput
    - Syntax Highlighting
    - Page (for current file in RAM and save/load to/from file)
    - Display (for line numbers and menus) MAKE LINE NUMBERS IN ITS OWN WINDOW
    - Editor (for editor window)
    - Config Loading (JSON library)

*/

int main() {
    
    // Put these in class constructor
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    WINDOW *tedit = newwin(LINES - 2, COLS - 5, 0, 4); //  this is handled by editor

    display *dis = new display;
    userInput *usr = new userInput;
    editor *edit = new editor(tedit, 5, 5);
    page *file = new page;

    
    dis->lines(); // Editor calls this
    refresh();
    edit->setCursorPosition(1,1);
    
    //ch = getch();
    while(true) {
        
        
        wrefresh(tedit);

        int chinput = usr->queryInput();
        if (chinput == KEY_UP) {
            edit->cursorUp();
        } else if (chinput == KEY_LEFT) {
            edit->cursorLeft();
        } else if (chinput == KEY_DOWN) {
            edit->cursorDown();
        } else if (chinput == KEY_RIGHT) {
            edit->cursorRight();
        } else if (chinput == KEY_ENTER) {

        } else {
            edit->placeChar(chinput);
            file->addChar(chinput, 0, edit->getX());
        }
        //edit->setCursorPosition(1,1);
        
    }

    endwin();
    return 1;

}

