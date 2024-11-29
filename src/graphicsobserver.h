#ifndef GRAPHICSOBSERVER_H
#define GRAPHICSOBSERVER_H

#include "observer.h"
#include <memory>
#include "window.h"
#include "player.h"

class Game;

class GraphicsObserver : public Observer
{
private:
    Game &game;
    std::unique_ptr<Xwindow> xw;
    // Player * playerOne = game.getPlayerOne();
    // Player * playerTwo = game.getPlayerTwo();
    

public:
    GraphicsObserver(Game &game);

    void drawLevel(Player *player, int xOffset, int yOffset);
    void drawScore(Player *player, int xOffset, int yOffset);
    void drawHighScore(Player *player, int xOffset, int yOffset);
    void drawPlayerBoard(Player *player, int xOffset, int yOffset);
    void drawNextBlock(Player *player, int xOffset, int yOffset);
    int getColor(char cellType);

    void drawBoard() override;
    ~GraphicsObserver() override;
};

#endif
