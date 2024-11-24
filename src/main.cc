#include "game.h"
#include "textobserver.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    Game game;

    Observer *o = new TextObserver(game);

    std::string command;

    game.getPlayerOne()->getBoard().addBlock(game.getPlayerOne()->getPtrLevel()->generateBlock('I', 0));
    game.getPlayerTwo()->getBoard().addBlock(game.getPlayerOne()->getPtrLevel()->generateBlock('J', 0));
    game.updateGameDisplay();

    while (std::cin >> command) {
        int player;
        std::cin >> player;
        if (player == 1) {
            if (command == "l") {
                game.getPlayerOne()->getBoard().activeBlocks[0]->moveLeft();
            } else if (command == "r") {
                game.getPlayerOne()->getBoard().activeBlocks[0]->moveRight();
            } else if (command == "cw") {
                game.getPlayerOne()->getBoard().activeBlocks[0]->rotateClockwise();
            } else if (command == "ccw") {
                game.getPlayerOne()->getBoard().activeBlocks[0]->rotateCounterClockwise();
            } else if (command == "d") {
                game.getPlayerOne()->getBoard().activeBlocks[0]->moveDown();
            } else if (command == "dr") {
                game.getPlayerOne()->getBoard().activeBlocks[0]->drop();
            } else if (command == "pX") {
                std::cout << game.getPlayerOne()->getBoard().activeBlocks[0]->getBottomLeftCell()->getX() << std::endl;
            } else if (command == "pY") {
                std::cout << game.getPlayerOne()->getBoard().activeBlocks[0]->getBottomLeftCell()->getY() << std::endl;
            }
        } else if (player == 2) {
            if (command == "l") {
                game.getPlayerTwo()->getBoard().activeBlocks[0]->moveLeft();
            } else if (command == "r") {
                game.getPlayerTwo()->getBoard().activeBlocks[0]->moveRight();
            } else if (command == "cw") {
                game.getPlayerTwo()->getBoard().activeBlocks[0]->rotateClockwise();
            } else if (command == "ccw") {
                game.getPlayerTwo()->getBoard().activeBlocks[0]->rotateCounterClockwise();
            } else if (command == "d") {
                game.getPlayerTwo()->getBoard().activeBlocks[0]->moveDown();
            } else if (command == "dr") {
                game.getPlayerTwo()->getBoard().activeBlocks[0]->drop();
            } else if (command == "pX") {
                std::cout << game.getPlayerOne()->getBoard().activeBlocks[0]->getBottomLeftCell()->getX() << std::endl;
            } else if (command == "pY") {
                std::cout << game.getPlayerOne()->getBoard().activeBlocks[0]->getBottomLeftCell()->getY() << std::endl;
            }
        }
        game.updateGameDisplay();
    }
}
