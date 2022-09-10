#include <ncurses.h>


class editor {

    private:
        int cursorX;
        int cursorY;
        WINDOW *window;

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


};