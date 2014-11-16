

#include <math.h>
#include "Graph.h"


Graph::Graph(int numberOfNodes, string disttype) {
    this->numberOfNodes = numberOfNodes;
    numberOfEdges = 0;
    this->type = disttype;
    adjList = new vector<Edge> [numberOfNodes+1];
    vector<Node> nodList;
}

void Graph::addNode(unsigned int n1, float x, float y) {
    
    if (n1 > numberOfNodes)
        return;
    
    Node n12 = {n1, x, y};
    nodList.push_back(n12);
    
}

void Graph::addEdge(unsigned int n1, unsigned int n2, double weight, bool directed) {
    
    if (n1 > numberOfNodes || n2 > numberOfNodes)
        return;
    
    // add two-way edge between n1 and n2
    Edge e12 = {n1, n2, weight};
    adjList[n1].push_back(e12);
    
    numberOfEdges++;
    
    if (!directed) {
        Edge e21 = {n2, n1, weight};
        adjList[n2].push_back(e21);
        numberOfEdges++;
    }
   
}

void Graph::makeEdges() {
	for (int n1 = 0; n1 < numberOfNodes; n1++) {
		Node node1 = nodList[n1];
		for (int n2 = n1+1; n2 < numberOfNodes; n2++) {
			Node node2 = nodList[n2];
			float dist = distance(node1.x,node1.y,node2.x,node2.y);
			addEdge(n1+1,n2+1,dist);
		}
	}
}

float Graph::distance(float x1, float y1, float x2, float y2){
	if (type == "EUC_2D") {
		float dist = pow(pow(x1-x2,2)+pow(y1-y2,2),0.5);
		return dist;
	}
	if (type == "GEO"){
		float pi=3.14159265358979323846;

		double theta;
		theta = y1 - y2;
		float dist = sin((pi/180)*(x1)) * sin((pi/180)*(x2)) + cos((pi/180)*(x1)) * cos((pi/180)*(x2)) * cos((pi/180)*(theta));
		dist = acos(dist);
		dist = dist*180/pi;
		dist = dist * 60 * 1.1515;
		return (dist);
	}
}


int Graph::getEdgeWeight(unsigned int n1, unsigned int n2) {
    if (n1 >= numberOfNodes || n2 >= numberOfNodes) {
        cout << "Error: node indeces out of range" << endl;
        return 0;
    }
    
    for (vector<Edge>::iterator it = adjList[n1].begin(); it != adjList[n1].end(); it++) {
        if (it->to == n2)
            return it->weight;
    }
    
    return 0;
}

int Graph::getNumberOfNodes() {
    return numberOfNodes;
}

int Graph::getNumberOfEdges() {
    return numberOfEdges;
}

void Graph::print() {
    cout << "Number of nodes: " << numberOfNodes << endl << endl;
    cout << "From\tTo\tWeight" << endl;
    for (int n = 1; n <= numberOfNodes; n++) {
        for (vector<Edge>::iterator it = adjList[n].begin(); it != adjList[n].end(); it++) {
            cout << it->from << "\t\t" << it->to << "\t" << it->weight << endl;
        }
    }
}

Graph::~Graph() {
    delete [] adjList;
}
