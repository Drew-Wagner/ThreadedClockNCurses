# Threaded Clock Timer
A simple threaded UI implementing a digital stop watch with the NCurses library.

## Installation

### Linux / WSL
```
sudo apt-get install libncurses5-dev libncursesw5-dev
```

## Compiling

### G++
```
g++ -c -I./headers -c ./source/*.cpp
g++ -I./headers -o main main.cpp *.o -lncurses -pthread
```

### Build script
```
chmod +x build.sh
./build.sh
```

## Running

Execute the main executable with:
```
./main
```

Press space bar to pause the timer.
Press down arrow to reset the timer.
Press up arrow to increment timer by 1 hour.
Press Q to exit.

## References
- COMP 345 with Nora Houari at Concordia University
- https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/windows.html
- http://www.cplusplus.com/reference/thread/thread/
