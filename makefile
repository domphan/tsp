all:
	g++ -std=c++11 tsp_greedy.cpp tsp_distance.cpp tsp_io.cpp main.cpp -o testfile -Wall
