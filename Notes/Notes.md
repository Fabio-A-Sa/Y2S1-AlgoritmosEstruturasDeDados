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

Adaptação colorida das árvores 2-3-4. A altura de uma Red Black Tree é de aproximadamente h = 2 log (n+1), sendo n o número de nós.<br>
Segue as seguintes características:

 - Cada nó pode ter 2, 3 ou 4 filhos;
 - O nó root é preto;
 - As folhas são pretas;
 - Filhos de nós vermelhos são pretos;
 - Para cada nó, o caminho para os nós descendentes passam pelo mesmo número de nós pretos;

#### Vantagens

- Complexidade temporal O(h) -> O(2log(n+1)) -> O(log(n)) para pesquisa, para inserção e para remoção, até mesmo considerando as rotações para manter a integridade estrutural e os piores casos;
- Necessitam de menos reestruturamentos do que as AVL;
- A recoloração de um nó é O(1);

#### Desvantagens

- Necessitam de memória extra, pois cada nó tem de registar a sua cor;
- A nível assintótico, é ligeiramente menos eficiente do que as AVL (diferença de O(1.44log(n) para O(2log(n))));

### 1.3 - Splay Trees

Faz-se splay nos nós mais requisitados, para ser mais rápido, a nível amortizado, resgatá-lo mais vezes (parecido com uma cache). Um "splay" de um nó consiste através de rotações e comparações em colocá-lo no root da árvore para ser usado ou removido, assim torna-se mais simples manipulá-lo. <br>
A complexidade continua a ser O(log(n)) que corresponde à altura da árvore.

### 1.4 - B - Trees

Minimiza o número de acessos ao disco, permitindo mais que dois filhos por nó. Perde menos tempo a navegar na árvore (disco) e mais tempo a navegar pelo nó escolhido (memória). Quando o nó / bloco fica grande de mais, partilha com o pai o valor em excesso.

### 1.5 - BSTs in STL

A STL implementa Red Black Trees para as seguintes estruturas de dados:
  - set, armazena somente dados de valores não repetidos e ordenados;
  - multiset, o mesmo que um set mas permite valores repetidos;
  - map, parecido com um dicionário de Python. Para cada chave possui um valor;
  - multimap, o mesmo que um map mas permite valores repetidos;

Alguns exemplos de funcionamento:

````c++
int
````