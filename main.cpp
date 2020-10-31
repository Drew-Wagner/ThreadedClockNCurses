#include <ncurses.h>
#include <string>

#include "DigitalClock.h"

#include <iostream>

WINDOW* create_newwin(int height, int width, int starty, int startx);

int main() {
  WINDOW* view_window;
  int startx, starty, width, height;
  int ch;

  initscr();
  cbreak();

  keypad(stdscr, TRUE);

  height = 3;
  width = 10;
  starty = (LINES - height) / 2;
  startx = (COLS - width) / 2;
  printw("Press Q to exit");
  refresh();

  view_window = create_newwin(height, width, starty, startx);
  ClockTimer *timer = new ClockTimer();
  DigitalClock *clock = new DigitalClock(timer, view_window);

  timer->start();
  while ((ch = getch()) != 'q') {
    switch (ch) {
      case ' ':
        if (timer->isRunning())
          timer->stop();
        else
          timer->start();
        break;
      case KEY_UP:
        timer->setTime(timer->getHour() + 1, 0, 0);
        break;
      case KEY_DOWN:
        timer->reset();
        break;
    }
  }
  timer->stop();
  delete clock;
  delete timer;
  wclear(view_window);
  delwin(view_window);
  clear();
  endwin();
  std::cout << "Done.";
  return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx) {
  WINDOW *local_win;

  local_win = newwin(height, width, starty, startx);
  box(local_win, 0, 0);
  wrefresh(local_win);

  return local_win;
}
