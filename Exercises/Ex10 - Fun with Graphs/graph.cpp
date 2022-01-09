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

void Graph::resetNodes() {

    for (int i = 1 ; i <= n ; i++) {
        nodes[i].visited = false;
        nodes[i].distance = 0;
        nodes[i].color = WHITE;
    }
}

int Graph::outDegree(int v) {
    if (v < 1 || v > n) return -1;
    return nodes[v].adj.size();
}

int Graph::connectedComponents() {

    int total = 0;
    resetNodes();

    for (int i = 1 ; i <= nodes.size()-1 ; i++) {
        if (!nodes[i].visited) {
            total++;
            dfs(i);
        }
    }

    return total;
}

void Graph::dfs_Number(int v, int &total) {

    nodes[v].visited = true;
    total++;

    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
            dfs_Number(w, total);
        }
    }
}

int Graph::giantComponent() {

    int max = INT_MIN;

    for (auto node : nodes) node.visited = false;

    for (int i = 1 ; i <= nodes.size()-1 ; i++) {
        if (!nodes[i].visited) {
            int attemp = 0;
            dfs_Number(i, attemp);
            max = attemp > max ? attemp : max;
        }
    }

    return max;
}

void Graph::topologicalDFS(int v, list<int> &order) {

    nodes[v].visited = true;
    for (Edge e : nodes[v].adj) {
        int node = e.dest;
        if (!nodes[node].visited) {
            topologicalDFS(node, order);
        }
    }
    order.push_front(v);
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