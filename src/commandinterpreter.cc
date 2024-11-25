#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

#include "commandinterpreter.h"
#include "game.h"
#include "subject.h"

Interpreter::Interpreter(Game* game): game{game} {
    commandMap["left"] = LEFT;
    commandMap["right"] = RIGHT;
    commandMap["down"] = DOWN;
    commandMap["clockwise"] = CLOCKWISE;
    commandMap["counterclockwise"] = COUNTERCLOCKWISE;
    commandMap["drop"] = DROP;
    commandMap["levelup"] = LEVELUP;
    commandMap["leveldown"] = LEVELDOWN;
    commandMap["norandom"] = NORANDOM;
    commandMap["random"] = RANDOM;
    commandMap["sequence"] = SEQUENCE;
    commandMap["I"] = I;
    commandMap["J"] = J;
    commandMap["L"] = L;
    commandMap["O"] = O;
    commandMap["S"] = S;
    commandMap["Z"] = Z;
    commandMap["T"] = T;
    commandMap["restart"] = RESTART;
    commandMap["rename"] = RENAME;
}

int getPrefix(std::string& command) {
    std::string prefix;
    for (int i = 0; i < command.length(); i++) {
        if (command[i] >= '0' && command[i] <= '9') {
            prefix += command[i];
        }else{
            command = command.substr(i, command.length() - i);
            break;
        }
    }
    if (prefix.empty()) {
        return 1;
    }
    return stoi(prefix);
}

int linesToDrop(int level) {
     if (level == 3 || level == 4) {
        return 1;
    } else {
        return 0;
    }
}

void Interpreter::runLeftCommand(int prefix) {
    Block * currentBlock = game->getCurrentPlayer()->getBoard().getCurrentBlock();
    int down = linesToDrop(game->getCurrentPlayer()->getIntLevel())
               + game->getCurrentPlayer()->getBoard().getHeavyInt();
    for (int i = 0; i < prefix; i++) {
        currentBlock->moveLeft();
    }
}

