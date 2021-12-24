// Created on December, 2021
// @author: Fábio Araújo de Sá

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Graph {

    private:
        /**
         * Uma struct que implementa uma aresta entre dois nós.
         * Destino, se for um grafo direcional. Por predefinição, implementa-se uma bidirecional A -> B e B -> A
         * Peso, se for um grafo pesado. Por predefinição, implementa-se weight = 1
         */
        struct Edge {
            int destination;
            int weight;
        };

        /**
         * Um nó é representado por uma lista de arestas adjacentes, que podem ou não ter
         * direção ou peso
         */
        struct Node {
            list<Edge> adjacents;
        };

        /**
         * Tamanho do grafo
         */
        int size;

        /**
         * Se ele tem direção
         */
        bool hasDirection;

        /**
         * Um grafo é constituido por um vector de nós
         */
        vector<Node> nodes;

    public:

        /**
         * Construtor de um grafo com base no tamanho dos nós a albergar. Por predefinição, é um grafo não direcional
         */
        Graph(int nodes, bool dir = false);

        /**
         * Adiciona uma ligação entre a source e o destino, com ou sem peso associado
         */
        void addEdge (int source, int destination, int weight = 1);
};

Graph::Graph(int nodes, bool dir) {
    this->size = nodes;
    this->hasDirection= dir;
    this->nodes(nodes+1);
}

void Graph::addEdge(int source, int destination, int weight) {
    if (source < 1 || source > size || destination < 1 || destination > size) return;
    nodes[source].adjacents.push_back({destination, weight});
    if (!hasDirection) nodes[destination].adjacents.push_back({source, weight});
}

int main () {

    Graph graph(9, false);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge()
}