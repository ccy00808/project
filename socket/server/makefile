INCLUDE_DIR = ./include
main : main.cpp ./src/epoll.cpp ./src/socket.cpp
	g++ -std=c++11 -pthread -I${INCLUDE_DIR} -g -o $@ $^