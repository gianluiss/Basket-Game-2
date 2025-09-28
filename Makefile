TARGET = basket-game

CXX = g++
CXXFLAGS = -Wall -std=c++17

SRCS := $(wildcard *.cpp)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) -lncurses

clean:
	rm -f $(TARGET)