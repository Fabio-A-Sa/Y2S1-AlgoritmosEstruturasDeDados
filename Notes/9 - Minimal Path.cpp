// Created on January, 2022
// @author: Fábio Araújo de Sá

#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Edge {
    int destination;
    int weight;
};

struct Node {
    list<Edge> adjacents;
    bool visited;
    int distance;
    int parent;
};

class Graph {

private:

    int size;
    bool hasDirection;
    vector<Node> nodes;

public:

    Graph(int nodes, bool dir = false);
    void addEdge (int source, int destination, int weight = 1);
    vector<Node> getNodes();
    void setNodes(const vector<Node> &nodes);
    Node* getNode(int index);
};

Graph::Graph(int nodes, bool dir) : nodes(nodes+1) {
    this->size = nodes;
    this->hasDirection= dir;
}

void Graph::addEdge(int source, int destination, int weight) {
    if (source < 1 || source > size || destination < 1 || destination > size) return;
    Edge newEdge;
    newEdge.destination = destination;
    newEdge.weight = weight;
    nodes[source].adjacents.push_back(newEdge);
    if (!hasDirection) {
        Edge anotherEdge;
        anotherEdge.destination = source;
        anotherEdge.weight = weight;
        nodes[destination].adjacents.push_back(anotherEdge);
    }
}

vector<Node> Graph::getNodes() {
    return this->nodes;
}

int main () {


    return 0;
}