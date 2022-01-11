// Created on January, 2022
// @author: Fábio Araújo de Sá

#include "graph.h"

Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {}

void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

int Graph::prim(int r) {

    MinHeap<int, int> heap(n, -1);

    for (int i = 1 ; i <= n ; i++) {
        nodes[i].distance = INT_MAX;
        nodes[i].parent = NULL;
        heap.insert(i, nodes[i].distance);
    }

    nodes[r].distance = 0;
    heap.decreaseKey(r, 0);

    while (heap.getSize()) {

        int nodeIndex = heap.removeMin(); // o índice do nó que possui menor distância a r

        for (Edge edge : nodes[nodeIndex].adj) {
            int neighbor = edge.dest;
            if (heap.hasKey(neighbor) && edge.weight < nodes[neighbor].distance) {
                nodes[neighbor].parent = neighbor;
                nodes[neighbor].distance = edge.weight;
                heap.decreaseKey(neighbor, edge.weight);
            }
        }
    }

    int total = 0;
    for (int i = 1 ; i <= n ; i++) {
        total += nodes[i].distance;
        cout << "Node " << i << " distance: " << nodes[i].distance << endl;
    }

    return total;
}

int Graph::kruskal() {

    vector<Edge> minimalSpanningTree = {};
    vector<Edge> allEdges = {};
    DisjointSets<int> set;

    for (int i = 0 ; i <= n ; i++) {
        set.makeSet(i);
        for (Edge edge : nodes[i].adj) {
            edge.origin = i;
            allEdges.push_back(edge);
        }
    }

    sort(allEdges.begin(), allEdges.end(), [](const Edge &e1, const Edge &e2) { return e1.weight < e2.weight; });

    for (Edge edge : allEdges) {
        if (set.find(edge.origin) != set.find(edge.dest)) {
            minimalSpanningTree.push_back(edge);
            set.unite(edge.origin, edge.dest);
        }
    }

    int total = 0;
    for (Edge edge : minimalSpanningTree)
        total += edge.weight;
    return total;
}