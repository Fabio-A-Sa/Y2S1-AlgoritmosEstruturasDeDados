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
         * direção ou peso.
         * Foi acrescentado um novo parâmetro, para a pesquisa DFS (que tem de ter algo que verifique se o nó foi visitado)
         */
        struct Node {
            list<Edge> adjacents;
            bool visited;
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

        /**
         * Depth First Search - vai percorrer o grafo de forma recursiva: primeiro a parte da direita
         * e só depois a parte da esquerda
         */
         void DFS(int v);
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
        newEdge.destination = destination;
        newEdge.weight = weight;
        nodes[destination].adjacents.push_back(newEdge);
    }
}

void Graph::DFS(int v) {
}

int main () {

    Graph graph(9, false);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(4, 6);
    graph.addEdge(4, 7);
    graph.addEdge(5, 8);
    graph.addEdge(7, 9);
}