// Created on January, 2022
// @author: Fábio Araújo de Sá

#include "funWithGraphs.h"
#include "graph.h"

#include <vector>
#include <iostream>


// ----------------------------------------------------------
// Some Example Graphs
// ----------------------------------------------------------

Graph FunWithGraphs::graph1() {
    Graph g(7, false);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 4, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 5, 8);
    g.addEdge(3, 6, 12);
    g.addEdge(3, 7, 11);
    g.addEdge(4, 5, 9);
    g.addEdge(4, 6, 5);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7,10);
    return g;
}

Graph FunWithGraphs::graph2() {
    Graph g(9, false);
    g.addEdge(1,2, 16);
    g.addEdge(1,4, 3);
    g.addEdge(1,5, 8);
    g.addEdge(2,3, 12);
    g.addEdge(2,5, 15);
    g.addEdge(2,6, 1);
    g.addEdge(3,6, 10);
    g.addEdge(4,5, 9);
    g.addEdge(4,7, 7);
    g.addEdge(5,6, 6);
    g.addEdge(5,7, 5);
    g.addEdge(5,8, 2);
    g.addEdge(6,8, 14);
    g.addEdge(6,9, 4);
    g.addEdge(7,8, 13);
    g.addEdge(8,9, 11);
    return g;
}

Graph FunWithGraphs::graph3() {
    Graph g(11, false);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 7, 1);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 8, 3);
    g.addEdge(3, 8, 3);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 5, 3);
    g.addEdge(4, 6, 1);
    g.addEdge(4, 8, 5);
    g.addEdge(5, 10, 2);
    g.addEdge(6, 10, 3);
    g.addEdge(6, 11, 5);
    g.addEdge(7, 8, 5);
    g.addEdge(7, 9, 2);
    g.addEdge(8, 9, 1);
    g.addEdge(9, 10, 7);
    g.addEdge(9, 11, 3);
    g.addEdge(10, 11, 5);
    return g;
}

Graph FunWithGraphs::graph4() {
    Graph g(4, false);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 9);
    g.addEdge(3, 4, 8);
    return g;
}

/*
 * Exercício 1
 *
 * Algoritmo de Prim usando o quarto grafo do exemplo e começando no nó 1 (nó arbitrário)
 *
 * Adicionar o nó 1
 * Adicionar o nó 2, com a aresta 1-2 de custo 2
 * Adicionar o nó 4, com a aresta 1-4 de custo 3
 * Adicionar o nó 3, com a aresta 2-3 de custo 5
 *
 * Assim já foram adicionados |V| vértices, e qualquer aresta a mais iria originar um ciclo
 *
 * Algoritmo de Kruskal usando o quarto grafo do exemplo
 *
 * Adicionar a aresta 1-2, de custo 1
 * Adicionar a aresta 1-4, de custo 3
 * Adicionar a aresta 2-3, de custo 5
 *
 * Assim já foram adicionadas |V| - 1 arestas, e qualquer aresta a mais iria originar um ciclo
 */

int FunWithGraphs::game(const vector<int>& v) {
     return 0;
}

int FunWithGraphs::gridCity(const vector<pair<int, int>>& plants, const vector<pair<int, int>>& houses) {
    return 0;
}

