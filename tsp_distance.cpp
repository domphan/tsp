//
//  tsp_distance.cpp
//  distances
//
//  Created by Grace Feigh on 3/14/18.
//  Copyright © 2018 Grace Feigh. All rights reserved.
//

#include "tsp_distance.hpp"

vector< vector<int> > distance(vector <vector <int> > cityGrid){
    int size = cityGrid.size();
    vector <vector <int> >  distanceGrid(size, vector<int>(size));
    for (int i = 0; i < size - 1; i++) {
        int city1 = i;
        int city1x = cityGrid[i][0];
        int city1y = cityGrid[i][1];
        for (int j = 0; j < size-1; j++){
            int city2 = j;
            int city2x = cityGrid[j][0];
            int city2y = cityGrid[j][1];
            double xsquared = pow((city2x-city1x), 2);
            double ysquared = pow((city2y-city1y), 2);
            int distance = round(sqrt(xsquared + ysquared));
            distanceGrid[city1][city2] = distance;
        }
    }
    return distanceGrid;
}
