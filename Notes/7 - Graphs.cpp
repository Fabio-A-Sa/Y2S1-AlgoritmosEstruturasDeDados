// Created on December, 2021
// @author: Fábio Araújo de Sá

#include <iostream>
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

        /**
         * Baseado na pesquisa DFS, retorna o número de componentes conexosdo grafo em questão
         */
        int howManyComponents();
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

void Graph::DFS(int v) {

    nodes[v].visited = true;                    // Marcar o nó como visitado
    cout << v << " ";                           // Mostra o nó que visita
    for (Edge edge : nodes[v].adjacents) {      // Para cada aresta a visitar
        int dest = edge.destination;            // Encontra o nó de destino
        if (!nodes[dest].visited) {             // Se esse nó ainda não estiver visitado
            DFS(dest);                          // Visita-o recursivamente
        }
    }
}

int Graph::howManyComponents() {

    int total = 0;

    for (int i = 1 ; i <= size ; i++) {                   // Garantir que nenhum nó foi antes visitado
        nodes[i].visited = false;
    }

    for (int i = 1 ; i <= size ; i++) {
        if (!nodes[i].visited) {
            cout << "Connected components: ";
            total++;
            DFS(i);
            cout << endl;
        }
    }

    cout << "Total: ";
    return total;
}

int main () {

    cout << "\nCreate and fill graphs\n" << endl;

    Graph graphNonDirectional(9, false);
    graphNonDirectional.addEdge(1, 2);
    graphNonDirectional.addEdge(1, 3);
    graphNonDirectional.addEdge(1, 4);
    graphNonDirectional.addEdge(2, 4);
    graphNonDirectional.addEdge(3, 4);
    graphNonDirectional.addEdge(4, 5);
    graphNonDirectional.addEdge(4, 6);
    graphNonDirectional.addEdge(4, 7);
    graphNonDirectional.addEdge(5, 8);
    graphNonDirectional.addEdge(7, 9);

    Graph notConnected(14, false);
    notConnected.addEdge(1, 11);
    notConnected.addEdge(11, 7);
    notConnected.addEdge(11, 12);
    notConnected.addEdge(12, 2);
    notConnected.addEdge(12, 8);
    notConnected.addEdge(3, 13);
    notConnected.addEdge(13, 4);
    notConnected.addEdge(13, 14);
    notConnected.addEdge(14, 9);
    notConnected.addEdge(14, 5);
    notConnected.addEdge(6, 10);

    cout << "DFS Search Sequence: " << endl;
    graphNonDirectional.DFS(1);
    cout << endl << endl;

    cout << "Connected components of graph 1: " << endl;
    cout << graphNonDirectional.howManyComponents() << endl << endl;
    cout << "Connected components of graph 2: " << endl;
    cout << notConnected.howManyComponents() << endl << endl;

    return 0;
}