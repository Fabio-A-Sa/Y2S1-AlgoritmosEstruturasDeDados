// Created on January, 2022
// @author: Fábio Araújo de Sá

#include <iostream>
#include <vector>
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

void Graph::setNodes(const vector<Node> &nodes) {
    this->nodes = nodes;
}

void fillGraph(Graph &graph) {

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

    for (Node node : graph.getNodes()) {
        node.distance = INT_MAX;
        node.parent = NULL;
    }
}

Node extractMinimum(vector<Node> &nodes) {

    int minimumDistance = INT_MAX;
    Node minimumNode;

    // Find Node with minimum distance
    for (int i = 0 ; i < nodes.size() ; i++) {
        if (nodes[i].distance < minimumDistance) {
            minimumDistance = nodes[i].distance;
        }
    }

    // Extract and remove minimum
    for (vector<Node>::iterator it = nodes.begin() ; it != nodes.end() ; it++) {
        if (it->distance == minimumDistance) {
            minimumNode = *it;
            nodes.erase(it);
            break;
        }
    }

    return minimumNode;
}

void PrimAlgorithm(Graph &graph, int node = 0) {

    vector<Node> graphNodes = graph.getNodes();

    Node root = !node && !graphNodes.empty() ?
                               graphNodes[1] : graphNodes[node];


    while (!graphNodes.empty()) {
        Node u = extractMinimum(graphNodes);
        
    }

}

int main() {

    Graph graph = Graph(9, false);
    fillGraph(graph);
    resetNodes(graph);
    PrimAlgorithm(graph);

    return 0;
}