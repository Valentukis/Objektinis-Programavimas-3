CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17

.DEFAULT_GOAL := main

main: class/*.cpp
	$(CXX) $(CXXFLAGS) -o main class/*.cpp

test: class/studentas.cpp test_studentas.cpp
	$(CXX) -o test_studentas test_studentas.cpp class/studentas.cpp 

custom: vector/*.cpp
	$(CXX) $(CXXFLAGS) -o custom vector/main.cpp vector/studentas.cpp vector/failu_funkcijos.cpp -Lvector -lspausdinimo

clean:
	rm -f main test_studentas custom
