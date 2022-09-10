#include <iostream>
#include <ncurses.h>
#include <string>
using namespace std;

class display {
    public:

        void lines() {
            for(int i = 1; i < LINES; i++) {
                move(i - 1, 1);
                const char *str = to_string(i).c_str();
                if(i < 10) {
                    addch(' ');
                }
                addstr(str);
            }
        }

        


    private:



};