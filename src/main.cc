#include "game.h"
#include "textobserver.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string s1 = "IJLSZOT", s2 = "TZOJILS";
    Game game(false, s1, s2);

    Observer *o = new TextObserver(game);

    std::string command;

    // game.getPlayerOne()->getBoard().addBlock(game.getPlayerOne()->getPtrLevel()->generateBlock());
    // game.updateGameDisplay();
    // game.getPlayerOne()->getBoard().getCurrentBlock()->drop();
    // game.updateGameDisplay();
    // game.switchTurn();
    // game.updateGameDisplay();
    // game.getPlayerTwo()->getBoard().getCurrentBlock()->drop();
    // game.updateGameDisplay();

    game.updateGameDisplay();
    while (std::cin >> command) {
        if (command == "l") {
            game.getCurrentPlayer()->getBoard().getCurrentBlock()->moveLeft();
        } else if (command == "r") {
            game.getCurrentPlayer()->getBoard().getCurrentBlock()->moveRight();
        } else if (command == "cw") {
            game.getCurrentPlayer()->getBoard().getCurrentBlock()->rotateClockwise();
        } else if (command == "ccw") {
            game.getCurrentPlayer()->getBoard().getCurrentBlock()->rotateCounterClockwise();
        } else if (command == "d") {
            game.getCurrentPlayer()->getBoard().getCurrentBlock()->moveDown();
        } else if (command == "dr") {
            game.getCurrentPlayer()->getBoard().getCurrentBlock()->drop();
            game.switchTurn();
        } else if (command == "pX") {
            std::cout << game.getCurrentPlayer()->getBoard().getCurrentBlock()->getBottomLeftCell()->getX() << std::endl;
        } else if (command == "pY") {
            std::cout << game.getCurrentPlayer()->getBoard().getCurrentBlock()->getBottomLeftCell()->getY() << std::endl;
        }
        game.updateGameDisplay();
    }
}

//  else if (command == "add") {
//                 std::cin >> command;
//                 if (command == "i") {
//                     game.getCurrentPlayer()->getBoard().addBlock(game.getPlayerOne()->getPtrLevel()->generateBlock('I', 0));
//                 } else if (command == "j") {
//                     game.getCurrentPlayer()->getBoard().addBlock(game.getPlayerOne()->getPtrLevel()->generateBlock('J', 0));
//                 } else if (command == "l") {
//                     game.getCurrentPlayer()->getBoard().addBlock(game.getPlayerOne()->getPtrLevel()->generateBlock('L', 0));
//                 } else if (command == "o") {
//                     game.getCurrentPlayer()->getBoard().addBlock(game.getPlayerOne()->getPtrLevel()->generateBlock('O', 0));
//                 } else if (command == "s") {
//                     game.getCurrentPlayer()->getBoard().addBlock(game.getPlayerOne()->getPtrLevel()->generateBlock('S', 0));
//                 } else if (command == "z") {
//                     game.getCurrentPlayer()->getBoard().addBlock(game.getPlayerOne()->getPtrLevel()->generateBlock('Z', 0));
//                 } else if (command == "t") {
//                     game.getCurrentPlayer()->getBoard().addBlock(game.getPlayerOne()->getPtrLevel()->generateBlock('T', 0));
//                 }
//             }

