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

void fillGraph(Graph &graph) {

    /**
     * Slide 5, Shortest Path
     */
    graph.addEdge(1, 2, 4);
    graph.addEdge(1, 8, 8);
    graph.addEdge(2, 8, 11);
    graph.addEdge(2, 3, 8);
    graph.addEdge(8, 9, 7);
    graph.addEdge(7, 8, 1);
    graph.addEdge(7, 9, 6);
    graph.addEdge(3, 9, 2);
    graph.addEdge(3, 6, 4);
    graph.addEdge(3, 4, 7);
    graph.addEdge(4, 6, 14);
    graph.addEdge(6, 7, 2);
    graph.addEdge(4, 5, 9);
    graph.addEdge(5, 6, 10);
}

void resetNodes(Graph &graph) {

    for (Node &node : graph.getNodes()) {
        node.distance = -1;
        node.parent = -1;
    }
}

int main () {

    Graph graph(5, true);
    fillGraph(graph);

    return 0;
}