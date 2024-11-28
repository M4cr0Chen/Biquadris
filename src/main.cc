#include "game.h"
#include "textobserver.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string s1 = "sequence1.txt", s2 = "sequence2.txt";
    int seed = 123;
    bool graphicsOn;
    int startLevel = 0;

    for (int i = 0; i < argc; i++) {
        std::string word = argv[i];
        if (word == "-text") {
            graphicsOn = false;
        } else if (word == "-seed") {
            seed = std::stoi(argv[i + 1]);
        } else if (word == "-scriptfile1") {
            s1 = argv[i + 1];
        } else if (word == "-scriptfile2") {
            s2 = argv[i + 1];
        } else if (word == "-startlevel") {
            startLevel = std::stoi(argv[i + 1]);
        }
    }

    if (startLevel > 4) {
        startLevel = 4;
    } else if (startLevel < 0) {
        startLevel = 0;
    }

    Game game(graphicsOn, s1, s2, seed, startLevel);

    game.runGame();
}
