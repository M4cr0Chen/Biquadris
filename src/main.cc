#include "game.h"
#include "textobserver.h"

int main(int argc, char *argv[])
{
    Game game;

    Observer *o = new TextObserver(game);

    game.updateGameDisplay();
    game.getPlayerOne()->getBoard().addBlock(game.getPlayerOne()->getPtrLevel()->generateBlock('I', 0));
    game.updateGameDisplay();
    game.getPlayerOne()->getBoard().activeBlocks[0]->moveDown();
    game.updateGameDisplay();
    game.getPlayerOne()->getBoard().activeBlocks[0]->moveRight();
    game.updateGameDisplay();
    for (int i = 0; i < 6; i++)
    {
        game.getPlayerOne()->getBoard().activeBlocks[0]->moveRight();
        game.updateGameDisplay();
    }
    
    game.getPlayerOne()->getBoard().activeBlocks[0]->moveRight();
    game.updateGameDisplay();

    game.getPlayerOne()->getBoard().activeBlocks[0]->rotateClockwise();
    game.updateGameDisplay();

    game.getPlayerOne()->getBoard().activeBlocks[0]->rotateClockwise();
    game.updateGameDisplay();

    game.getPlayerOne()->getBoard().activeBlocks[0]->rotateClockwise();
    game.updateGameDisplay();

    game.getPlayerOne()->getBoard().activeBlocks[0]->rotateClockwise();
    game.updateGameDisplay();
}
