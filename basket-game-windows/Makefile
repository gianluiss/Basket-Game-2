TARGET = basket-game.exe

CXX = g++
CXXFLAGS = -Wall -std=c++17

SRCS := $(wildcard *.cpp)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	del $(TARGET)
