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

Game::Game(bool graphicsOn, std::string s1, std::string s2) : 
               isGameOver{false}, isPlayerOneTurn{true},
               playerOne{std::make_unique<Player>(true, s1, s2)},
               playerTwo{std::make_unique<Player>(false, s1, s2)}
// , textObserver{std::make_unique<TextObserver>(*this)}, graphicsObserver{std::make_unique<GraphicsObserver>(*this)}
{
    initGame();
}

void Game::updateGameDisplay()
{
    notifyObservers();
}

void Game::switchTurn()
{
    std::unique_ptr<Block> block = getCurrentPlayer()->getPtrLevel()->generateBlock();
    getCurrentPlayer()->getBoard().addBlock(std::move(block));
    isPlayerOneTurn = !isPlayerOneTurn;
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
