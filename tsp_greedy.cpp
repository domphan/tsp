#include <iostream>
#include <limits>
#include "tsp_greedy.hpp"
#include <vector>


void nearestNeighbor(int city, std::vector< std::vector<int> > &cityList, int visitedCities[], int numberOfCities, int &totalCost, std::vector<int> &routeTaken) {
    int newCity;
    int minimum;
    int originatingCity = city;
    
    // Add starting city to list of visited
    visitedCities[city] = 1;
    routeTaken.push_back(city);
    
    // Nearest neighbor algorithm
    // Will take the shortest distance neighbor and visit it.
    while (routeTaken.size() < numberOfCities ) {
        // Infinity values
        minimum = std::numeric_limits<int>::max();
        newCity = std::numeric_limits<int>::max();
        // For each neighbor, find minimum
        for (int i = 0; i < numberOfCities; i++) {
            // If distance is less than min and hasn't been visited
            if (cityList[city][i] < minimum && visitedCities[i] == 0 && i != city) {
                minimum = cityList[city][i];
                newCity = i;
            }
        }
        
        //std::cout << "adding this city: " << newCity << std::endl;
        // Add that city to visited list
        visitedCities[newCity] = 1;
        routeTaken.push_back(newCity);
        // Set as next city to explore.
        city = newCity;
        //std::cout << "ADding this to total: " << minimum << std::endl;
        // Add cost
        totalCost += minimum;
    }
    // Add final step in route back to originating city.
    totalCost += cityList[newCity][originatingCity];
    routeTaken.push_back(originatingCity);
}
