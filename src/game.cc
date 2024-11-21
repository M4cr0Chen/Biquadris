#include "game.h"
#include "textObserver.h"
#include "graphicsObserver.h"

void Game::initGame() {}

Game::Game() : isGameOver{false}, isPlayerOneTurn{true},
               playerOne{std::make_unique<Player>()},
               playerTwo{std::make_unique<Player>()},
               textObserver{std::make_unique<TextObserver>(*this)},
               graphicsObserver{std::make_unique<GraphicsObserver>(*this)}
{
    initGame();
}
