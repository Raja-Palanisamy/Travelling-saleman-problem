
#ifndef __MST__Graph__
#define __MST__Graph__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Edge {
    unsigned int from, to;
    double weight;
} Edge;


typedef struct Node {
    unsigned int node;
    float x,y;
} Node;

class Graph {
    
    int numberOfEdges;      // number of (one-way) edges
    int numberOfNodes;      // number of nodes
    
public:
    
    string type;
    
    // Declare the adjacency list
    typedef vector<Edge> *AdjacencyList;
    
    AdjacencyList adjList;
    
    //typedef vector<Node> *NodeList;

    vector<Node> nodList;
    /*
     * Constructor: create a graph with a fixed number of nodes.
     *
     * @param numberOfNodes the number of nodes
     */
    Graph(int numberOfNodes, string type);
    
    /*
     * Destructor: Deallocate graph variables.
     */
    ~Graph();
    
    
    /*
     * Add an edge from node n1 to n2.
     *
     * @param n1 index of first node
     * @param n2 index of second node
     * @param weight the weight of the edge
     * @param directed specifies if edge is only directed from n1 to n2.
     *
     * @preq n1 between 0 and <numberOfNodes> (inclusive)
     * @preq n2 between 0 and <numberOfNodes> (inclusive)
     */
    void addNode(unsigned int n1, float x, float y);
    void addEdge(unsigned int n1, unsigned int n2, double weight, bool directed=false);
    void makeEdges();
    float distance(float x1, float y1, float x2, float y2);
    
    /*
     * Get the weight of the edge from n1 to n2
     *
     * @param n1 index of first node
     * @param n2 index of second node
     *
     * @preq n1 between 0 and <numberOfNodes> (inclusive)
     * @preq n2 between 0 and <numberOfNodes> (inclusive)
     * 
     * @return weight of the edge
     */
    int getEdgeWeight(unsigned int n1, unsigned int n2);
    
    /*
     * Get the number of nodes in the graph.
     */
    int getNumberOfNodes();
    
    /*
     * Get the number of edges in the graph.
     */
    int getNumberOfEdges();
    
    /*
     * Print out the graph
     */
    void print();
    
};

#endif /* defined(__MST__Graph__) */
