BUILD = g++
THREAD = -pthread

DIR_INC = ./include
DIR_OBJ = ./lib

OBJS = $(SRCS:.c=.o)

main : ./lib/main.o ./lib/FlyBehavior.o ./lib/QuackBehavior.o ./lib/Duck.o ./lib/DuckSchedule.o
	$(BUILD) -g -o $@ $^

./lib/main.o : main.cpp
	$(BUILD) -std=c++11 -I${DIR_INC} -g -c $^ -o ./lib/main.o

./lib/Duck.o : ./src/Duck.cpp
	$(BUILD) -std=c++11 -I${DIR_INC} -g -c $^ -o ./lib/Duck.o

./lib/QuackBehavior.o : ./src/QuackBehavior.cpp
	$(BUILD) -std=c++11 -I${DIR_INC} -g -c $^ -o ./lib/QuackBehavior.o

./lib/DuckSchedule.o : ./src/DuckSchedule.cpp
	$(BUILD) -std=c++11 -I${DIR_INC} -g -c $^ -o ./lib/DuckSchedule.o

./lib/FlyBehavior.o : ./src/FlyBehavior.cpp
	$(BUILD) -std=c++11 -I${DIR_INC} -g -c $^ -o ./lib/FlyBehavior.o