#include <ncurses.h>
#include "userInput.cpp"

class editor {

    private:
        int cursorX = 1;
        int cursorY = 1;
        WINDOW *window;
        userInput * user = new userInput();

    public:

        editor(WINDOW *win, int y, int x) {
            cursorX = x;
            cursorY = y;
            window = win;
        } 


        void loadCursorPosition() {
            wmove(window, cursorY, cursorX);
        }

        void setCursorPosition(int y, int x) {
            wmove(window, y,x);
            cursorX = x;
            cursorY = y;
        }

        void cursorUp() {
            cursorY = cursorY - 1;
            wmove(window, cursorY, cursorX);
        }

        void cursorDown() {
            cursorY = cursorY + 1;
            wmove(window,cursorY, cursorX);

        }

        void cursorRight() {
            cursorX = cursorX + 1;
            wmove(window,cursorY, cursorX);
        }

        void cursorLeft() {
            cursorX = cursorX - 1;
            wmove(window,cursorY, cursorX);
        }

        void placeChar(char ch) {
            waddch(window, ch);
            cursorRight();
        }

        int getX() {
            return cursorX;
        }

        int getY() {
            return cursorY;
        }


};