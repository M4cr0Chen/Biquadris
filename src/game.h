#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
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

public:
    Game(bool graphicsOn, std::string s1, std::string s2);
    ~Game() = default;
    void runGame();
    void restartGame();
    void switchTurn();
    void updateGameDisplay();

    // Getters & Setters
    bool getIsGameOver() const;
    Player *getPlayerOne();
    Player *getPlayerTwo();
    Player *getCurrentPlayer();
};

#endif
