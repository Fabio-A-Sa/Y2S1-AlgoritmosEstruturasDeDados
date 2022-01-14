// Created on January, 2022
// @author: Fábio Araújo de Sá

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
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

struct KruskalEdge {
    int u;
    int v;
    int weight;
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

void Graph::setNodes(const vector<Node> &nodes) {
    this->nodes = nodes;
}

Node* Graph::getNode(int index) {
    return &nodes[index];
}

void fillGraph(Graph &graph) {

    /**
     * Slide 9, MST Part 1
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

bool equals(const Node &n1, const Node *n2) {
    return n1.visited == n2->visited && n1.distance == n2->visited
           && n1.parent == n2->parent;
}

bool in(const vector<Node> &nodes, Node *searchNode) {

    for (Node node : nodes) {
        if (equals(node, searchNode)) return true;
    }
    return false;
}

int getIndex(Graph graph, const Node &n) {

    for (int i = 1 ; i < graph.getNodes().size() ; i++) {
        if (equals(n, graph.getNode(i))) return i;
    }
    return -1;
}

void PrimAlgorithm(Graph &graph, int node = 0) {

    vector<Node> graphNodes = graph.getNodes();

    Node root = !node && !graphNodes.empty() ?
                               graphNodes[1] : graphNodes[node];
    root.distance = 0;

    while (!graphNodes.empty()) {
        Node u = extractMinimum(graphNodes);
        for (Edge &e : u.adjacents) {
            int dest = e.destination;
            if (in(graphNodes, graph.getNode(dest)) && e.weight < graph.getNode(dest)->distance) {
                graph.getNode(dest)->parent = getIndex(graph, u);
                graph.getNode(dest)->distance = e.weight;
            }
        }
    }
}

void showResults(Graph graph, const string &algorithmName) {

    cout << "\nShowing " << algorithmName << " Algorithm results" << endl << endl;
    vector<Node> graphNodes = graph.getNodes();
    for (int i = 1 ; i < graphNodes.size() ; i++) {
        cout << "Node: " << i << endl;
        cout << "Distance: " << graphNodes[i].distance << endl;
        cout << "Parent: " << graphNodes[i].parent << endl << endl;
    }
}

void makeSet(Node &node) {

}

bool keySort(const KruskalEdge &e1, const KruskalEdge &e2) {
    return e1.weight < e2.weight;
}

bool in (const vector<KruskalEdge> &edges, const KruskalEdge &newEdge) {
    for (KruskalEdge edge : edges) {
        if ((edge.u == newEdge.u && edge.v == newEdge.v) ||
            (edge.u == newEdge.v && edge.v == newEdge.u)) return true;
    }
    return false;
}

vector<KruskalEdge> getSortedEdges(Graph graph) {

    vector<KruskalEdge> answer = {};
    for (int i = 1 ; i < graph.getNodes().size() ; i++) {
        Node node = graph.getNodes()[i];
        for (Edge edge : node.adjacents) {
            KruskalEdge newEdge = {i, edge.destination, edge.weight};
            if (!in(answer, newEdge)) answer.push_back(newEdge);
        }
    }
    sort(answer.begin(), answer.end(), keySort);
    return answer;
}

int findSet(int node) {
    return 1;
}

void unionSets(int u, int v) {

}

list<KruskalEdge>  KruskalAlgorithm(Graph graph) {

    list<KruskalEdge> minimalSpanningTree = {};

    for (Node node : graph.getNodes()) {
        makeSet(node);
    }

    vector<KruskalEdge> edges = getSortedEdges(graph);

    /*
     * Output de verificação
     * Nota: não haverá necessáriamente um número de E = V - 1 pois o grafo inicial contém ciclos
     */
    for (KruskalEdge edge : edges) {
        cout << "Nodes " << edge.u << " and " << edge.v << " have an edge with weight = " << edge.weight << endl;
    }

    /**
     * Para já, como o findSet não está implementado, sou obrigado a retornar sempre o mesmo valor. Numa situação
     * normal, o conjunto dos edges têm de ser diferentes para não existirem ciclos na Spanning Tree
     */
    for (KruskalEdge edge : edges) {
        if (findSet(edge.u) == findSet(edge.v)) {
            minimalSpanningTree.push_back(edge);
            unionSets(edge.u, edge.v);
        }
    }

    return minimalSpanningTree;
}

void showKruskalsResults(const list<KruskalEdge> &edges) {

    cout << "\n\nResults of Kruskal's Algortithm\n" << endl;
    for (list<KruskalEdge>::const_iterator it = edges.begin() ; it != edges.end() ; it++) {
        cout << "Nodes u = " << it->u << " and v = " << it->v << " have weight = " << it->weight << endl;
    }
    return;
}

int main() {

    cout << "\n\nNota: os algoritmos não funcionam pois não influenciam diretamente os dados contidos"
            "no Grafo mas sim somente as cópias. Ao criar um grafo de apontadores a situação fica normalizada!\n" << endl;

    Graph graph = Graph(9, false);
    fillGraph(graph);
    resetNodes(graph);
    PrimAlgorithm(graph, 1);
    showResults(graph, "Prim");

    Graph graph2 = Graph(9, false);
    fillGraph(graph2);
    resetNodes(graph2);
    list<KruskalEdge> answer = KruskalAlgorithm(graph2);
    showKruskalsResults(answer);

    return 0;
}