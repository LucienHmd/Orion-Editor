#include <ncurses.h>


class editor {

    private:
        int cursorX;
        int cursorY;

    public:

        editor(int y, int x) {
            cursorX = x;
            cursorY = y;
        } 


        void loadCursorPosition() {
            move(cursorY, cursorX);
        }

        void setCursorPosition(int y, int x) {
            move(y,x);
            cursorX = x;
            cursorY = y;
        }

        void cursorUp() {
            cursorY = cursorY - 1;
            move(cursorY, cursorX);
        }

        void cursorDown() {
            cursorY = cursorY + 1;
            move(cursorY, cursorX);

        }

        void cursorRight() {
            cursorX = cursorX + 1;
            move(cursorY, cursorX);
        }

        void cursorLeft() {
            cursorX = cursorX - 1;
            move(cursorY, cursorX);
        }


};