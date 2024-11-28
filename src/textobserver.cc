#include "textobserver.h"
#include "game.h"
#include "player.h"
#include <iostream>

void TextObserver::printLevel()
{
    int playerOneLevel = game.getPlayerOne()->getIntLevel();
    int playerTwoLevel = game.getPlayerTwo()->getIntLevel();

    std::cout << "Level:    " << playerOneLevel << "       ";
    std::cout << "Level:    " << playerTwoLevel << std::endl;
}

void TextObserver::printCurrentScore()
{
    int playerOneCurrentScore = game.getPlayerOne()->getScore().getCurrentScore();
    int playerTwoCurrentScore = game.getPlayerTwo()->getScore().getCurrentScore();

    std::cout << "Score:    " << playerOneCurrentScore << "       ";
    std::cout << "Score:    " << playerTwoCurrentScore << std::endl;
}

void TextObserver::printHighScore()
{
    int playerOneHighScore = game.getPlayerOne()->getScore().getHighScore();
    int playerTwoHighScore = game.getPlayerTwo()->getScore().getHighScore();

    std::cout << "Hi Score: " << playerOneHighScore << "       ";
    std::cout << "Hi Score: " << playerTwoHighScore << std::endl;
}

void TextObserver::printPlayersBoard()
{
    Board &playerOneBoard = game.getPlayerOne()->getBoard();
    Board &playerTwoBoard = game.getPlayerTwo()->getBoard();

    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (playerOneBoard.getIsBlind() && i >= 2 && i <= 11 && j >= 2 && j <= 8)
            {
                std::cout << "?";
                continue;
            }
            std::cout << playerOneBoard.getCellAt(i, j)->getCellType();
        }
        std::cout << "       ";
        for (int j = 0; j < 11; j++)
        {
            if (playerTwoBoard.getIsBlind() && i >= 2 && i <= 11 && j >= 2 && j <= 8)
            {
                std::cout << "?";
                continue;
            }   
            std::cout << playerTwoBoard.getCellAt(i, j)->getCellType();
        }
        std::cout << std::endl;
    }
}

void TextObserver::printDividerLine()
{
    std::cout << "-----------" << "       " << "-----------" << std::endl;
}

void TextObserver::printNextBlock()
{
    char playerOneNextBlockType = game.getPlayerOne()->getBoard().getNextBlockType();
    char playerTwoNextBlockType = game.getPlayerTwo()->getBoard().getNextBlockType();

    switch (playerOneNextBlockType)
    {
    case 'I':
        std::cout << "           ";
        break;
    case 'J':
        std::cout << "J          ";
        break;
    case 'L':
        std::cout << "   L       ";
        break;
    case 'O':
        std::cout << "OO         ";
        break;
    case 'S':
        std::cout << " SS        ";
        break;
    case 'Z':
        std::cout << "ZZ         ";
        break;
    case 'T':
        std::cout << "TTT        ";
        break;
    }

    std::cout << "       ";

    switch (playerTwoNextBlockType)
    {
    case 'I':
        std::cout << "           ";
        break;
    case 'J':
        std::cout << "J          ";
        break;
    case 'L':
        std::cout << "   L       ";
        break;
    case 'O':
        std::cout << "OO         ";
        break;
    case 'S':
        std::cout << " SS        ";
        break;
    case 'Z':
        std::cout << "ZZ         ";
        break;
    case 'T':
        std::cout << "TTT        ";
        break;
    }
    std::cout << std::endl;

    switch (playerOneNextBlockType)
    {
    case 'I':
        std::cout << "IIII       ";
        break;
    case 'J':
        std::cout << "JJJ        ";
        break;
    case 'L':
        std::cout << "LLL        ";
        break;
    case 'O':
        std::cout << "OO         ";
        break;
    case 'S':
        std::cout << "SS         ";
        break;
    case 'Z':
        std::cout << " ZZ        ";
        break;
    case 'T':
        std::cout << " T         ";
        break;
    }
}

void TextObserver::drawBoard()
{
    printLevel();
    printCurrentScore();
    printHighScore();

    printDividerLine();

    printPlayersBoard();

    printDividerLine();

    printNextBlock();
}

TextObserver::TextObserver(Game &game) : game(game)
{
    // game.attach(std::unique_ptr<Observer>(this));
}

TextObserver::~TextObserver() = default;
