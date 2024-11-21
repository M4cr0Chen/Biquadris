#include "game.h"
#include "textobserver.h"
#include "graphicsobserver.h"

void Game::initGame() {}

Game::Game() : isGameOver{false}, isPlayerOneTurn{true},
               playerOne{std::make_unique<Player>()},
               playerTwo{std::make_unique<Player>()}
// , textObserver{std::make_unique<TextObserver>(*this)}, graphicsObserver{std::make_unique<GraphicsObserver>(*this)}
{
    initGame();
}

void Game::updateGameDisplay()
{
    notifyObservers();
}

Player * Game::getPlayerOne() {
    return playerOne.get();
}

Player * Game::getPlayerTwo() {
    return playerTwo.get();
}
