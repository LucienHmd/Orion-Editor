#include <vector>

class page {
    private:
        std::vector<std::vector<char>> file = {{}};

    public:
    
        void newLine(int loc) {
            file.insert(file.begin() + loc, {});
        }

        void delLine(int loc) {
            // this needs to check if the line is EMPTY
            file.erase(file.begin() + loc);
        }

        void addChar(char ch, int lLoc, int cLoc) {
            //file[lLoc].insert(file[lLoc].begin() + cLoc, ch);
            file[0].push_back(ch);
        }

        void delChar(int lLoc, int cLoc) {
            file[lLoc].erase(file[lLoc].begin() + cLoc);

        }
};