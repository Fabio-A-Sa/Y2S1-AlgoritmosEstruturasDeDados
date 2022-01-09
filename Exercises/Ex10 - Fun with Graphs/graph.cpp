// Created on January, 2022
// @author: Fábio Araújo de Sá

#include "graph.h"

Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {}

void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

void Graph::dfs(int v) {

    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

void Graph::bfs(int v) {

    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q;
    q.push(v);
    nodes[v]. visited = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

int Graph::outDegree(int v) {
    return 0;
}

int Graph::connectedComponents() {
    return 0;
}

int Graph::giantComponent() {
    return 0;
}

list<int> Graph::topologicalSorting() {
    list<int> order;
    return order;
}

int Graph::distance(int a, int b) {
    return 0;
}

int Graph::diameter() {
    return 0;
}

bool Graph::hasCycle() {
    return false;
}