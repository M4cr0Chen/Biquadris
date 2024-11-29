#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

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
    int down = linesToDrop(game->getCurrentPlayer()->getIntLevel());
    int downHeavy = game->getCurrentPlayer()->getBoard().getHeavyInt();
    std::cout << "curplayer level: " << game->getCurrentPlayer()->getIntLevel() << "curplayer down: " << down 
    << "curplayer downHeavy: " << downHeavy << std::endl;

    // First do all horizontal movements
    for (int i = 0; i < prefix; i++) {
        if (!currentBlock->moveLeft()) {
            break;
        }
    }

    // Then apply level-based drops
    for (int i = 0; i < down; i++) {
        if (!currentBlock->moveDown()) {
            //do nothing
        }
    }

    // Finally apply heavy drops
    for (int i = 0; i < downHeavy; i++) {
        if (!currentBlock->moveDown()) {
            game->getCurrentPlayer()->dropBlock();
            game->switchTurn();
            return;
        }
    }
}

void Interpreter::runRightCommand(int prefix) {
    Block * currentBlock = game->getCurrentPlayer()->getBoard().getCurrentBlock();
    int down = linesToDrop(game->getCurrentPlayer()->getIntLevel());
    int downHeavy = game->getCurrentPlayer()->getBoard().getHeavyInt();
    std::cout << "curplayer level: " << game->getCurrentPlayer()->getIntLevel() << "curplayer down: " << down 
    << "curplayer downHeavy: " << downHeavy << std::endl;
    
    // First do all horizontal movements
    for (int i = 0; i < prefix; i++) {
        if (!currentBlock->moveRight()) {
            break;
        }
    }

    // Then apply level-based drops
    for (int i = 0; i < down; i++) {
        if (!currentBlock->moveDown()) {
            // do nothing
        }
    }

    // Finally apply heavy drops
    for (int i = 0; i < downHeavy; i++) {
        std::cout << "into heavy drop loop" << std::endl;
        if (!currentBlock->moveDown()) {
            std::cout << "dropping heavily" << std::endl;
            game->getCurrentPlayer()->dropBlock();
            game->switchTurn();
            return;
        }
    }
}

void Interpreter::runDownCommand(int prefix) {
    Block * currentBlock = game->getCurrentPlayer()->getBoard().getCurrentBlock();
    int down = linesToDrop(game->getCurrentPlayer()->getIntLevel());
    for (int i = 0; i < down; i++) {
        currentBlock->moveDown();
    }
    for (int i = 0; i < prefix; i++) {
        currentBlock->moveDown();
    }
}

void Interpreter::runClockwiseCommand(int prefix) {
    Block * currentBlock = game->getCurrentPlayer()->getBoard().getCurrentBlock();
    int down = linesToDrop(game->getCurrentPlayer()->getIntLevel());
    for (int i = 0; i < prefix; i++) {
        if (!currentBlock->rotateClockwise()){
            return;
        }
    }
    for (int i = 0; i < down; i++) {
        currentBlock->moveDown();
    }
}

void Interpreter::runCounterClockwiseCommand(int prefix) {
    Block * currentBlock = game->getCurrentPlayer()->getBoard().getCurrentBlock();
    int down = linesToDrop(game->getCurrentPlayer()->getIntLevel());
    for (int i = 0; i < prefix; i++) {
        if (!currentBlock->rotateCounterClockwise()){
            return;
        }
    }
    for (int i = 0; i < down; i++) {
        currentBlock->moveDown();
    }
}

void Interpreter::runDropCommand(int prefix) {
    //check if without dropping, the game is over
    for (int i = 0; i < prefix; i++) {
        if (game->getIsGameOver()){
            return;
        }
        int linesCleared = game->getCurrentPlayer()->dropBlock();
        if (linesCleared >= 2) {
            requestSpecialAction();
        }
        std::cout << "should drop star: " << game->getCurrentPlayer()->shouldDroplvl4Block() << std::endl;
        std::cout << "isheavy: " << game->getCurrentPlayer()->getBoard().getIsHeavy() << std::endl;
        if (game->getCurrentPlayer()->shouldDroplvl4Block()) { // level4 extra block
            game->getCurrentPlayer()->insertStarBlock();
            game->getCurrentPlayer()->dropBlock();
        }
        game->switchTurn();
    }
}

void Interpreter::runLevelUpCommand(int prefix) {
    if (prefix + game->getCurrentPlayer()->getIntLevel() > 4) {
        game->getCurrentPlayer()->setLevel(4);
        return;
    }
    game->getCurrentPlayer()->setLevel(game->getCurrentPlayer()->getIntLevel() + prefix);
    int level = game->getCurrentPlayer()->getIntLevel();
    char blockType = game->getCurrentPlayer()->getBoard().getCurrentBlock()->getBlockType();
    game->getCurrentPlayer()->getBoard().changeCurrentAndNextBlock(game->getCurrentPlayer()->getPtrLevel()->giveMeABlock(blockType, level), game->getCurrentPlayer()->getPtrLevel()->generateBlock());
}

void Interpreter::runLevelDownCommand(int prefix) {
    if (game->getCurrentPlayer()->getIntLevel() - prefix < 0) {
        game->getCurrentPlayer()->setLevel(0);
        return;
    }
   game->getCurrentPlayer()->setLevel(game->getCurrentPlayer()->getIntLevel() - prefix);
}

void Interpreter::runNoRandomCommand(int prefix) {
    Player* player = game->getCurrentPlayer();
    string filename;
    if (player->getIntLevel() == 3 || player->getIntLevel() == 4) {
        if (std::cin >> filename) {
            try {
                player->getPtrLevel()->setGenerationNotRandom(filename);
            }
            catch (std::exception& e) {
                cerr << "bad file name" << endl;
            }

            int level = game->getCurrentPlayer()->getIntLevel();
            char blockType = game->getCurrentPlayer()->getBoard().getCurrentBlock()->getBlockType();
            game->getCurrentPlayer()->getBoard().changeCurrentAndNextBlock(game->getCurrentPlayer()->getPtrLevel()->giveMeABlock(blockType, level), game->getCurrentPlayer()->getPtrLevel()->generateBlock());
        }
    }
   
}

void Interpreter::runRandomCommand(int prefix) {
    Player* player = game->getCurrentPlayer();
    player->getPtrLevel()->setGenerationRandom();
}

void Interpreter::runSequenceCommand(int prefix) {
    string filename;
    if (std::cin >> filename) {
        ifstream file{filename};
        std::string fileCommand;
        while (file >> fileCommand) {
            interpret(fileCommand);
        } 
    }
}

void Interpreter::runRenameCommand() {
    string oldName;
    string newName;
    if (cin >> oldName >> newName) {
        if (commandMap.count(oldName) == 1) {
            Interpreter::CommandType iCommand = commandMap[oldName];
            commandMap.insert(pair<string, Interpreter::CommandType>(newName, iCommand));
            commandMap.erase(oldName);
        }
    }
}

void Interpreter::requestSpecialAction(){
    cout << "Enter a special action" << endl;
    string specialAction;
    Player* opponent = game->getNonCurrentPlayer();
    while (cin >> specialAction) {
        if (specialAction == "blind") {
            opponent->getBoard().setBoardBlind();
            break;
        } else if (specialAction == "heavy") {
            opponent->getBoard().setBoardHeavy();
            break;
        } else if (specialAction == "force") {
            char block;
            if (cin >> block){
                if(block == 'I' || block == 'J' || block == 'L'|| block == 'O' || block == 'S' || block == 'T' || block == 'Z') {
                    opponent->replaceUndroppedBlock(block);
                }
                cout << "bad letter" << endl;
            }
            break;
        } else {
            cout << "bad special action" << endl;
        }
    }
}

void Interpreter::interpret(std::string command) {
    int prefix = getPrefix(command);
    Interpreter::CommandType theCommand = DEFAULT;
    bool commandFound = false;

    for (auto& x : commandMap) { 
        if (command == x.first.substr(0, command.length())) {
            theCommand = x.second;
            if (commandFound) {
                cerr << "not unique command" << endl;
                return;
            }
            commandFound = true;
        }
    }

    if (game->getIsGameOver()) {
        if (theCommand == RESTART) {
            game->restartGame();
            return;
        }else if (theCommand == RENAME) {
            runRenameCommand();
            return;
        }
        cerr << "game over" << endl;
        return;
    }

    switch(theCommand){
        case Interpreter::LEFT:
            runLeftCommand(prefix);
            break;
        case Interpreter::RIGHT:
            runRightCommand(prefix);
            break;
        case Interpreter::DOWN:
            runDownCommand(prefix);
            break;
        case Interpreter::CLOCKWISE:
            runClockwiseCommand(prefix);
            break;
        case Interpreter::COUNTERCLOCKWISE:
            runCounterClockwiseCommand(prefix);
            break;
        case Interpreter::DROP:
            runDropCommand(prefix);
            break;
        case Interpreter::LEVELUP:
            runLevelUpCommand(prefix);
            break;
        case Interpreter::LEVELDOWN:
            runLevelDownCommand(prefix);
            break;
        case Interpreter::NORANDOM:
            runNoRandomCommand(prefix);
            break;
        case Interpreter::RANDOM:
            runRandomCommand(prefix);
            break;
        case Interpreter::SEQUENCE:
            runSequenceCommand(prefix);
            break;
         case Interpreter::I:
            game->getCurrentPlayer()->replaceUndroppedBlock('I');
            break;
        case Interpreter::J:
            game->getCurrentPlayer()->replaceUndroppedBlock('J');
            break;
        case Interpreter::L:
            game->getCurrentPlayer()->replaceUndroppedBlock('L');
            break;
        case Interpreter::O:
            game->getCurrentPlayer()->replaceUndroppedBlock('O');
            break;
        case Interpreter::S:
            game->getCurrentPlayer()->replaceUndroppedBlock('S');
            break;
        case Interpreter::T:
            game->getCurrentPlayer()->replaceUndroppedBlock('T');
            break;
        case Interpreter::Z:
            game->getCurrentPlayer()->replaceUndroppedBlock('Z');
            break;
        case Interpreter::RESTART:
            game->restartGame();
            break;
        case Interpreter::RENAME:
            runRenameCommand();
            break;
        default:
            cerr << "bad command" << endl;
            break;
    }

}


