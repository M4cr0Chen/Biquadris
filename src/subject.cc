#include "subject.h"

void Subject::attach(std::unique_ptr<Observer> o)
{
    observers.emplace_back(std::move(o));
}

void Subject::detach(std::unique_ptr<Observer> o)
{
    for (auto it = observers.begin(); it != observers.end(); it++)
    {
        if (it->get() == o.get())
        {
            observers.erase(it);
            break;
        }
    }
}
