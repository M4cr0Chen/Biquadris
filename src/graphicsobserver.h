#ifndef GRAPHICSOBSERVER_H
#define GRAPHICSOBSERVER_H

#include "observer.h"
#include <memory>

class Game;

class GraphicsObserver : public Observer
{
private:
    Game &game;
    // Xwindow &xw;

public:
    GraphicsObserver(Game &game);

    void drawBoard() override;
    ~GraphicsObserver() override;
};

#endif
