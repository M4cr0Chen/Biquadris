#include "game.h"
#include "textobserver.h"
#include "graphicsobserver.h"

void Game::initGame()
{
    playerOne->createBlock();
    playerTwo->createBlock();
    playerOne->createBlock();
    playerTwo->createBlock();
}

Game::Game(bool graphicsOn, std::string s1, std::string s2) : isGameOver{false}, isPlayerOneTurn{true},
                                                              playerOne{std::make_unique<Player>(true, s1, s2)},
                                                              playerTwo{std::make_unique<Player>(false, s1, s2)},
                                                              interpreter{Interpreter(this)}
// , textObserver{std::make_unique<TextObserver>(*this)}, graphicsObserver{std::make_unique<GraphicsObserver>(*this)}
{
    // initGame();
}

void Game::runGame()
{
    initGame();
    updateGameDisplay();

    std::string command;
    while (std::cin >> command)
    {
        interpreter.interpret(command);
        updateGameDisplay();
    }
}

void Game::restartGame()
{
    isPlayerOneTurn = true;
    isGameOver = false;

    playerOne->restartPlayer();
    playerTwo->restartPlayer();

    initGame();
}

void Game::updateGameDisplay()
{
    notifyObservers();
}

void Game::switchTurn()
{
    // bool playerGameOver = getCurrentPlayer()->getBoard().isGameOver();
    // std::cout << "isplayerone: " << isPlayerOneTurn << std::endl;
    // std::cout << "isGameover: " << std::boolalpha << playerGameOver << std::endl;
    // if (playerGameOver)
    // {
    //     isGameOver = true;
    //     return;
    // }
    try
    {
        std::unique_ptr<Block> block = getCurrentPlayer()->getPtrLevel()->generateBlock();
        getCurrentPlayer()->getBoard().addBlock(std::move(block));
        isPlayerOneTurn = !isPlayerOneTurn;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        isGameOver = true;
    }
}

bool Game::getIsGameOver() const
{
    return isGameOver;
}

Player *Game::getPlayerOne()
{
    return playerOne.get();
}

Player *Game::getPlayerTwo()
{
    return playerTwo.get();
}

Player *Game::getCurrentPlayer()
{
    if (isPlayerOneTurn)
    {
        return playerOne.get();
    }
    else
    {
        return playerTwo.get();
    }
}

Player *Game::getNonCurrentPlayer()
{
    if (isPlayerOneTurn)
    {
        return playerTwo.get();
    }
    else
    {
        return playerOne.get();
    }
}
