#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void drawBoard() = 0;
};

#endif
