CXX = g++
CXXFLAGS = -Wall -std=c++17
LIBS = -lncurses

all: tetris

tetris: src/main.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp $(LIBS) -o tetris

clean:
	rm -f tetris