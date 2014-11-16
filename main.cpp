// This file reads the DATA folder and generates the graph objects for each tsp problem.
// The distance functions are inbuilt in the Graph.cpp file

#include <iostream>
#include <limits>
#include <unistd.h>
#include <assert.h>

#include <stdlib.h>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <dirent.h>

#include "Graph.cpp"


using namespace std;

#define MAX_PRIORITY numeric_limits<int>::max()

// Create a new graph object based on the information from the file
Graph* parseEdges(string filename) {
    
    Graph *g = NULL;
    int numNodes;
    string type;
    string line;
    ifstream f (filename.c_str());
    if (f.is_open()) {
	getline(f, line);
	getline(f, line);
	f >> line;
	f >> numNodes;		// read num of nodes

	getline(f, line);
	f >> line;
	f >> type;			// read coord type
	getline(f, line);
	getline(f, line);
	getline(f, line);		// ignore all other lines
   
	g = new Graph(numNodes, type);

	int counter = 0;
	while ( counter < numNodes) {
	    float x, y;
	    int node;
	    f >> node;             // read node
	    f >> x;                // read x-coord
	    f >> y;                // read y-coord
	    g->addNode(node, x, y);
	    
	    counter++;
	}
	f.close();

    }
	else
		cout << "Could not open file \"" << filename << "\"" << endl;

	return g;
}

int main(int argc, char *argv[]){

    	string path = "DATA/";
	DIR *dir;
	struct dirent *ent;
	
	// Reads all .tsp files and creates the graph object
	if ((dir=opendir(path.c_str())) != NULL) {
		while ((ent = readdir (dir)) != NULL) {
			string x = ent->d_name;
			if (x.length() >2){
				Graph *g = parseEdges(path+ent->d_name);
				g->makeEdges();
				
				// All algorithms should be called here

			}
		}
		closedir (dir);
	}
	return 0;
}

