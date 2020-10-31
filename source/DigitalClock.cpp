#include "DigitalClock.h"

DigitalClock::DigitalClock() {
}

DigitalClock::DigitalClock(ClockTimer *timer, WINDOW *view_window)
{
  _timer = timer;
  _timer->attach(this);
  this->view_window = view_window;
}

DigitalClock::~DigitalClock() {
  if (_timer)
    _timer->detach(this);
}

void DigitalClock::update() {
  display();
}

void DigitalClock::display() {
  int hour = _timer->getHour();
  int minute = _timer->getMinute();
  int second = _timer->getSecond();
  std::stringstream output;
  output << hour << ":" << minute << ":" << second;

  wclear(view_window);
  wprintw(view_window, output.str().c_str());
  wrefresh(view_window);
}