//
//  main.cpp
//  TSP Problem
//  By: Dominic Phan, Jared Breedlove, Grace Feigh
//
//

#include "tsp_io.hpp"
#include "tsp_distance.hpp"
#include "tsp_greedy.hpp"
#include <iomanip>
using namespace std;


int main(int argc, char* argv[]) {

    // Printing to ensure that reading works.
    if (argc < 2){
        cerr << "Please enter file name.";
        return 1;
    }
    char* filename = argv[1];
    vector< vector<int> > tableGrid;
    tableGrid = parseTextFile(filename);
    /*
    for (int i = 0; i < tableGrid.size()-1; i++) {
        cout << "City: " << i << setw(10)<< " x: " << tableGrid[i][0] << setw(10) << " y: " << tableGrid[i][1] << endl;
    }
     */
    vector< vector<int> > distanceGrid;
    distanceGrid = distance(tableGrid);

    /*
    for (int i = 0; i < tableGrid.size()-1; i++) {
        for (int j = 0; j <tableGrid.size()-1; j++){
            cout << "City1: " << i << setw(10)<< " City2: " << j << setw(10) << " Distance: " << distanceGrid[i][j] << endl;
        }
    }
     */
    ofstream outfile;
    string outfilename;
    outfilename = filename;
    outfilename += ".tour";
    outfile.open (outfilename);
    
		int numberOfCities = tableGrid.size()-1;
		int visited[numberOfCities-1];
        vector<int> path;
		for (int i = 0; i < numberOfCities; i++) {
			visited[i] = 0;
		}
		int totalCost = 0;

		nearestNeighbor(15, distanceGrid, visited, numberOfCities, totalCost, path);
        outfile<<totalCost<<endl;
        for (int i = 0; i < path.size()-1; i++) {
            outfile<<path[i]<<endl;
        }
    outfile.close();

    return 0;
}
