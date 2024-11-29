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

Game::Game(bool graphicsOn, std::string s1, std::string s2, int seed, int startLevel) : isGameOver{false}, isPlayerOneTurn{true},
                                                              playerOne{std::make_unique<Player>(true, s1, s2, seed, startLevel)},
                                                              playerTwo{std::make_unique<Player>(false, s1, s2, seed, startLevel)},
                                                              interpreter{Interpreter(this)},
                                                              startLevel{startLevel}
{
    std::unique_ptr<Observer> textObserver = std::make_unique<TextObserver>(*this);
    attach(std::move(textObserver));
    if (graphicsOn)
    {
        std::unique_ptr<Observer> graphicsObserver = std::make_unique<GraphicsObserver>(*this);
        attach(std::move(graphicsObserver));
    }
    // initGame();
}

void Game::runGame()
{
    playerOne->setLevel(startLevel);
    playerTwo->setLevel(startLevel);
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
    
    try
    {
        std::unique_ptr<Block> block = getCurrentPlayer()->getPtrLevel()->generateBlock();
        getCurrentPlayer()->getBoard().addBlock(std::move(block));
        std::cout << "isplayerone before switch: " << isPlayerOneTurn << std::endl;
        getCurrentPlayer()->decideSwitchSpecialAction();
        isPlayerOneTurn = !isPlayerOneTurn;
        std::cout << "isplayerone after switch: " << isPlayerOneTurn << std::endl;
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
