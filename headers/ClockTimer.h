#pragma once
#include "Observable.h"
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

class ClockTimer : public Observable {
  public:
    ClockTimer();
    int getHour() { return hour; };
    int getMinute() { return minute; };
    int getSecond() { return second; };
    bool isRunning() { return running; };
    void start();
    void stop();
    void reset();
    void setTime(int newH, int newM, int newS);
    void tick();
    ~ClockTimer();
  private:
    void run();
    std::thread *clock_thread{nullptr};
    std::atomic<bool> running;
    std::mutex mtx;
    int hour, minute, second;
};
