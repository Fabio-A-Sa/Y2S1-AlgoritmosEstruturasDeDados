// Created on January, 2022
// @author: Fábio Araújo de Sá

#include <iostream>
#include <vector>
#include <list>
#include <map>
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

    int s = 1;
    int t = 2;
    int x = 3;
    int y = 4;
    int z = 5;

    graph.addEdge(s, t, 10);
    graph.addEdge(s, y, 5);
    graph.addEdge(t, y, 2);
    graph.addEdge(t, x, 1);
    graph.addEdge(x, z, 4);
    graph.addEdge(y, t, 3);
    graph.addEdge(y, x, 9);
    graph.addEdge(y, z, 2);
    graph.addEdge(z, s, 7);
    graph.addEdge(z, x, 6);
}

void resetNodes(Graph &graph) {

    for (Node &node : graph.getNodes()) {
        node.distance = -1;
        node.parent = -1;
    }
}

map<int, char> getKeys() {

    map<int, char> keys = {};
    keys.insert(make_pair('s', 1));
    keys.insert(make_pair('t', 2));
    keys.insert(make_pair('x', 3));
    keys.insert(make_pair('y', 4));
    keys.insert(make_pair('z', 5));
    return keys;
}

int main () {

    cout << "Algorithm" << endl << endl;
    Graph graph(5, true);
    fillGraph(graph);
    map<int, char> keys = getKeys();

    for (int i = 1 ; i <= graph.getNodes().size() ; i++) {
        Node currentNode = graph.getNodes()[i];
        cout << "Node " << keys[i] << ": " << endl;
        for (Edge edge : currentNode.adjacents) {
           8 cout << "Node " << keys[i] << " to Node " << keys[edge.destination] << " weight = " << edge.weight << endl;
        }
        cout << endl;
    }

    return 0;
}
