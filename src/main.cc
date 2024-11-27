#include "game.h"
#include "textobserver.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string s1 = "sequence1.txt", s2 = "sequence2.txt";
    Game game(false, s1, s2);

    Observer *o = new TextObserver(game);

    game.runGame();
}
