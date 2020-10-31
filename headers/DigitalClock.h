#pragma once
#include "Observer.h"
#include "ClockTimer.h"
#include <ncurses.h>
#include <string>
#include <sstream>

class DigitalClock: public Observer {
  public:
    DigitalClock();
    DigitalClock(ClockTimer* timer, WINDOW* view_window);
    ~DigitalClock();
    void update();
    void display();
  private:
    ClockTimer *_timer;
    WINDOW *view_window;
};