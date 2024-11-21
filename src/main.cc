#include "game.h"
#include "textobserver.h"

int main(int argc, char *argv[])
{
    Subject subject;
    Game game;
    Observer *o = new TextObserver(game);
    subject.attach(std::unique_ptr<Observer>(o));
    subject.notifyObservers();
    return 0;
}
