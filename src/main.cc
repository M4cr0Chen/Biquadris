#include "game.h"
#include "textobserver.h"

int main(int argc, char *argv[])
{
    Game game;

    Observer *o = new TextObserver(game);

    game.updateGameDisplay();
}
