#ifndef GAME_H
#define GAME_H

#include <memory>
#include "subject.h"
#include "player.h"

// Forward declarations
class Player;
class Observer;

class Game : public Subject
{
private:
    bool isGameOver;
    bool isPlayerOneTurn;
    void initGame();

    std::unique_ptr<Player> playerOne;
    std::unique_ptr<Player> playerTwo;

    // std::unique_ptr<Observer> textObserver;
    // std::unique_ptr<Observer> graphicsObserver;

public:
    Game();
    ~Game() = default;
    void runGame();
    void restartGame();
    void switchTurn();
    void updateGameDisplay();

    // Getters & Setters
    bool getIsGameOver() const;
    Player *getPlayerOne();
    Player *getPlayerTwo();
};

#endif
