#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "observer.h"
#include <memory>

class Game;

class TextObserver : public Observer
{
private:
    Game &game;

public:
    TextObserver(Game &game);

    void update() override;
    ~TextObserver() override;
};

#endif
