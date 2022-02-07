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

Há sempre hipótese de melhorar o desempenho de uma pesquisa usando uma árvore binária de pesquisa equilibrada pois as pesquisas ficam sempre com a mesma complexidade: `O(h)`, com h = log(n), sendo n o número de nós. <br>
No fundo, para cada árvore binária equilibrada presente nos tópicos seguintes (depois das rotações necessárias em cada nó), temos complexidade `O(log(n))` para uma pesquisa, inserção ou remoção.

### 1.1 - AVL

Árvore equilibrada de pesquisa em que o nível das folhas da subárvore da direita e a subárvore da esquerda diferem, no máximo, em uma unidade. <br>
Assim a altura pode ser expressada em h = log(n) e as pesquisas, inserções e remoções são em tempo praticamente linear.

#### Vantagens
 - Complexidade temporal O(log(n)) para pesquisa, para inserção e para remoção, até mesmo considerando as rotações para manter a integridade estrutural e os piores casos;

#### Desvantagens
 - Apesar de existirem, no máximo, duas rotações para cada operação, levam o seu tempo computacional;
 - Necessitam de memória extra, pois cada nó tem de registar o desiquilíbrio (-1, 0 ou 1) de cada subárvore;
 - Não é uma estrutura amiga da memória cache, pois está em constante mudança;

### 1.2 - Red Black Trees

