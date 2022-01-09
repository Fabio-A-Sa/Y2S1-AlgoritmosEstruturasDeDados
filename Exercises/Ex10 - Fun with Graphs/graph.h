// Created on January, 2022
// @author: Fábio Araújo de Sá

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <iostream>

using namespace std;

class Graph {

    private:

        struct Edge {
            int dest;   // Destination node
            int weight; // An integer weight
        };

        enum color {WHITE, GRAY, BLACK};        // Colors for exercise 5

        struct Node {
            list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
            bool visited;   // As the node been visited on a search?
            int distance;   // distance of determinate node
            color color;    // color of node in each iteration
        };

        int n;              // Graph size (vertices are numbered from 1 to n)
        bool hasDir;        // false: undirect; true: directed
        vector<Node> nodes; // The list of nodes being represented

    public:

        // Constructor: nr nodes and direction (default: undirected)
        Graph(int nodes, bool dir = false);

        // Add edge from source to destination with a certain weight
        void addEdge(int src, int dest, int weight = 1);

        // Depth-First Search: example implementation
        void dfs(int v);

        // Breadth-First Search: example implementation
        void bfs(int v);

        // To implement in exercises
        int outDegree(int v);
        int connectedComponents();
        int giantComponent();
        list<int> topologicalSorting();
        int distance(int a, int b);
        int diameter();
        bool hasCycle();

        // My auxiliar functions
        void dfs_Number(int v, int &total);
        void topologicalDFS(int v, list<int> &order);
        void fillDistances(int v);
        bool colorsDFS(int v);
        void resetNodes();
};

#endif