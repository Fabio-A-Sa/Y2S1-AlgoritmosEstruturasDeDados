// Created on December, 2021
// @author: Fábio Araújo de Sá

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Graph {

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
     * 
     */
    struct Node {
        list<Edge> adjacents;
    };

    int size;
    bool hasDirection;
    vector<Node> nodes;
};

int main () {


}