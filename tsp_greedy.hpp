#ifndef GREEDYALGO_HPP
#define GREEDYALGO_HPP

#include <iostream>
#include <limits>
#include <vector>
#include <stack>

void nearestNeighbor(int city, std::vector< std::vector<int> > &cityList, int visitedCities[], int numberOfCities, int &totalCost, std::vector<int> &routeTaken);

#endif
