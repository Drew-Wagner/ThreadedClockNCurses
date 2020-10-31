g++ -c -I./headers -c ./source/*.cpp
g++ -I./headers -o main main.cpp *.o -lncurses -pthread
rm *.o
