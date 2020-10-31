#include "Observable.h"

Observable::Observable() {
  _observers = new std::list<Observer*>;
}

Observable::~Observable() {
  delete _observers;
}

void Observable::attach(Observer* ob) {
  std::unique_lock<std::mutex> lock(mtx);
  _observers->push_back(ob);
}

void Observable::detach(Observer* ob) {
  std::unique_lock<std::mutex> lock(mtx);
  _observers->remove(ob);
}

void Observable::notify() {
  std::unique_lock<std::mutex> lock (mtx);
  for (auto ob : *_observers) {
    ob->update();
  }
}