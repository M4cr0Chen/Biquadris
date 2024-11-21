#ifndef GAME_H
#define GAME_H

#include <memory>
#include "subject.h"

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

    std::unique_ptr<Observer> textObserver;
    std::unique_ptr<Observer> graphicsObserver;

public:
    Game();
    ~Game();
    void runGame();
    void restartGame();
    void switchTurn();

    // Getters & Setters
    bool getIsGameOver() const;
    std::unique_ptr<Player> &getPlayerOne();
    std::unique_ptr<Player> &getPlayerTwo();
};

#endif