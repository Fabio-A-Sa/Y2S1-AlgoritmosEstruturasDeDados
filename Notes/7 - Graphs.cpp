// Created on December, 2021
// @author: Fábio Araújo de Sá

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Graph {

    /**
     * 
     */
    struct Edge {
        int destination;
        int weight;
    };

    struct Node {
        list<Edge> adjacents;
    };

    int size;
    bool hasDirection;
    vector<Node> nodes;
};

int main () {


}