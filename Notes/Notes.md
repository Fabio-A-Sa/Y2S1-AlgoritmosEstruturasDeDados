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

#### Alguns exemplos de funcionamento:

##### 1.5.1 - Para inserção, listagem, remoção em sets / multisets

````c++
void showContent(const set<int> &numbers) {                                        
    for (set<int>::iterator i = numbers.begin() ; i != numbers.end() ; i++) {      
        cout << *i << ", ";                                                        
    }                                                                              
    cout << endl;                                                                  
}                                                                                  

void randomFill(set<int> &numbers , int requestedSize) {                                  
                                                                                          
    string answer = numbers.empty() ? "empty" : "not empty"; cout << answer << endl;      
                                                                                          
    while (numbers.size() != requestedSize) {                                             
        numbers.insert(rand() % 20);                                                      
    }                                                                                     
    showContent(numbers);                                                                 
}                                                                                         

bool exists(const set<int> &numbers, int attemp) {    
    return numbers.find(attemp) != numbers.end();     
}                                                     

void eraseElement(set<int> &numbers, int element) {                 
    if (exists(numbers, element)) {                                 
        numbers.erase(numbers.find(element));                       
    } else cout << "Elemento não encontrado" << endl;               
}                                                                   
                                                                    
void eraseElementByPosition(set<int> &numbers , int position) {     
    if (position >= numbers.size()) return;                         
    set<int>::iterator it = numbers.begin();                        
    advance(it, position-1);                                        
    numbers.erase(it);                                              
}                                                                   

int main () {                                                                                      
                                                                                                   
    srand(time(NULL));                                                                             
                                                                                                   
    // Set                                                                                         
    set<int> numbers1;                                                                             
    randomFill(numbers1, 10);               // 0, 1, 3, 5, 6, 7, 9, 13, 16, 18                     
    exists(numbers1, 13);                   // O número 13 existe no conjunto                      
    eraseElement(numbers1, 18);             // 0, 1, 3, 5, 6, 7, 9, 13, 16                         
    eraseElementByPosition(numbers1, 3);    // 0, 1, 5, 6, 7, 9, 13, 16                            
                                                                                                   
    // Multiset                                                                                    
    multiset<int> numbers2;                                                                        
    randomFill(numbers2, 10);               // 2, 7, 8, 10, 10, 14, 14, 14, 15, 18                 
    exists(numbers2, 10);                   // O número 10 existe no conjunto!                     
    eraseElement(numbers2, 14);             // 2, 7, 8, 10, 10, 14, 14, 15, 18                     
    eraseElementByPosition(numbers2, 4);    // 2, 7, 8, 10, 14, 14, 15, 18                         
                                                                                                   
    // Os sets podem conter vários tipos de dados                                                  
    set<pair<string, int> > names;                                                                 
    names.insert(make_pair("Fabio", 3));                                                           
    names.insert(make_pair("Araújo", 1));                                                          
    names.insert(make_pair("Josefino", 10));                                                       
    names.insert(make_pair("Fabio", 1));                                                           
    names.insert(make_pair("Josefino", 5));                                                        
    names.insert(make_pair("Fabio", 2));                                                           
    names.insert(make_pair("Sá", 1));                                                              
                                                                                                   
    for (set<pair<string, int> >::iterator it = names.begin() ; it != names.end() ; it++) {        
        cout << "Pair: " << it->first << " -> " << it->second << endl;                             
    }                                                                                              
                                                                                                   
    return 0;                                                                                      
}                                                                                                                                                                  
````