#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory>
#include "observer.h"

class Observer;

class Subject
{
private:
    std::vector<std::unique_ptr<Observer>> observers;

public:
    void attach(std::unique_ptr<Observer> o);
    void detach(std::unique_ptr<Observer> o);
    void notifyObservers();
    virtual ~Subject() = default;
};

#endif
