#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "observer.h"
#include "subject.h"
#include <memory>

class Game;

class TextObserver : public Observer
{
private:
    // Subject &subject;

    void printLevel();
    void printCurrentScore() {}
    void printHighScore() {}
    void printPlayersBoard() {}
    void printDividerLine() {}
    void printNextBlock() {}

protected:
    Game &game;

public:
    TextObserver(Game &game);
    ~TextObserver() override;
    void drawBoard() override;
};

#endif
