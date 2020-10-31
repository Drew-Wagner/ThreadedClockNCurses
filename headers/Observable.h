#pragma once
#include "Observer.h"
#include <list>
#include <mutex>

class Observable {
  public:
    virtual void attach(Observer* o);
    virtual void detach(Observer* o);
    virtual void notify();
    Observable();
    ~Observable();
  private:
    std::list<Observer*> *_observers;
    std::mutex mtx;
};