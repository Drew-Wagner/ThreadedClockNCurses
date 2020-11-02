#include "ClockTimer.h"

ClockTimer::ClockTimer(): hour(0), minute(0), second(0), running(false) {
}

ClockTimer::~ClockTimer() {
  if (clock_thread) {
    running = false;
    delete clock_thread;
  }
}

void ClockTimer::setTime(int newH, int newM, int newS) {
  std::unique_lock<std::mutex> lock (mtx);
  hour = newH;
  minute = newM;
  second = newS;
  notify();
}

void ClockTimer::start() {
  running = true;
  clock_thread = new std::thread(&ClockTimer::run, this);
}

void ClockTimer::stop() {
  running = false;
  clock_thread->join();
  delete clock_thread;
  clock_thread = nullptr;
}

void ClockTimer::run() {
  while (running) {
    tick();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void ClockTimer::reset() {
  setTime(0, 0, 0);
}

void ClockTimer::tick() {
  std::unique_lock<std::mutex> lock(mtx);
  second++;
  if (second >= 60) {
    minute++;
    second = 0;
    if (minute >= 60) {
      hour++; minute = 0;
      if (hour >= 24) {
        hour = 0;
      }
    }
  }
  notify();
}