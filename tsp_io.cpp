#include "tsp_io.hpp"

vector< vector<int> > parseTextFile(string fileName) {
	int intToBeSkipped; // Integer used to hold first column (do nothing with it)
	vector< vector<int> > storageTable; // Vector to be returned. Stores the table.
	vector<int> row(2); // Row used for storageTAble
	string buffer;

	ifstream ifs;
	ifs.open(fileName);
	if (!(ifs.is_open())) {
		cout << "Failed to open file" << endl;
		exit(1);
	}
	// Get each row, store the first column into intToBeSkipped, do nothing with that
	// Store 2nd and 3rd column into vector and push it into storageTable
	while(!ifs.eof()) {
		ifs >> intToBeSkipped >> row[0] >> row[1];
		storageTable.push_back(row);
	}
	ifs.close();
	return storageTable;
}
