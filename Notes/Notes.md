# AED Second Exam (2022/02/12)

### Topics: <br>

- [x] Binary Search Trees
  - AVL Trees
  - Red Black Trees
  - Splay Trees
  - B-Trees
  - Time complexity
- [x] STL C++ for BSTs
  - Set
  - Multiset
  - Map
  - Multimap
- [x] HashTables
  - Hashing
  - Rehashing
  - Collisions
  - Separate Chaining
  - Open Addressing
  - Time complexity
- [x] STL C++ for HashTables
  - Unordered Set
  - Unordered Multiset
  - Unordered Map
  - Unordered Multimap
- [x] Graphs
  - Definitions
  - Representation
  - Adjacent Matrix
  - Adjacent List
- [x] Searching
  - Depth First Search
  - Breadth First Search
  - Dijkstra Algorithm
- [x] Minimum Spanning Trees
  - Definition
  - Prim Algorithm
  - Kruskal Algorithm
- [x] Auxiliary Structures
  - Priority queue
  - Heap
  - Disjoint Sets

<br>

## 1 - Balanced Binary Search Trees

Há sempre hipótese de melhorar o desempenho de uma pesquisa usando uma árvore binária de pesquisa pois as pesquisas têm praticamente a mesma complexidade: `O(h)`, e como se trata de árvores binárias equilibradas, h = log(n), sendo n o número de nós. <br>
No fundo, para cada árvore binária equilobrada presente nos tópicos seguintes, temos complexidade `O(log(n))` para uma pesquisa.

### 1.1 - AVL