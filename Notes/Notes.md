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
  - `set`, armazena somente dados de valores não repetidos e ordenados;
  - `multiset`, o mesmo que um set mas permite valores repetidos. Ao ordenar ordena primeiro first e depois second. Ao eliminar só elimina um dos repetidos;
  - `map`, parecido com um dicionário de Python. Para cada chave possui um valor. Qualquer inicialização names["test"] resulta no valor 0;
  - `multimap, o mesmo que um map mas permite valores repetidos. Ao ordenar ordena apenas pelo valor de first. Ao eliminar elimina apenas o primeiro par;

#### Alguns exemplos de funcionamento:

##### 1.5.1 - Listagem, inserção, remoção, pesquisa e ordenação em sets / multisets

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
    
    // Os sets podem ser adaptados de acordo com a função que faz a comparação
    bool key = [](const string &s1, const string &s2) { return s1.size() < s2.size(); };
    set<string, decltype(key)> strings(key);
    strings.insert("Aurélio");
    strings.insert("Ana");
    string.insert("Oi");
    showContent(strings);  // Oi, Ana, Aurélio;
                                                                                                   
    return 0;                                                                                      
}                                                                                                                                                                  
````

##### 1.5.2 - Listagem, inserção, remoção, pesquisa e ordenação em maps / multimaps

````c++
void showContent(map<string, int> names) {
    for (map<string, int >::iterator it = names.begin() ; it != names.end() ; it++) {
        cout << "'" <<  it->first << "' -> " << it->second << endl;
    }
}

void fillMap(multimap<string, int> &names) {

    names.insert(make_pair<string, int>("Faculdade", 9));
    names.insert(make_pair<string, int>("Engenharia", 11));
    names.insert(make_pair<string, int>("Engenharia", 13));
    names.insert(make_pair<string, int>("Engenharia", 12));
    names.insert(make_pair<string, int>("Universidade", -5));
    names.insert(make_pair<string, int>("Universidade", 6));
    names.insert(make_pair<string, int>("Universidade", 4));
    names.insert(make_pair<string, int>("Porto", -5));
    names.insert(make_pair<string, int>("Porto", 10));
    names.insert(make_pair<string, int>("Porto", 11));
    names.insert(make_pair<string, int>("Porto", 11));
    names.insert(make_pair<string, int>("FEUP", 23));
    names.insert(make_pair<string, int>("FEUP", 20));
    names.insert(make_pair<string, int>("FEUP", 24));
}

bool exists(map<string, int> &names, string name) {
    return names.find(name) != names.end();
}

void removeKey(map<string, int> &names, string name) {
    if (exists(names, name)) {
        names.erase(names.find(name));
    } else cout << "A chave " << name << " não existe no map" << endl;
}

int main () {

    // Map
    map<string, int> names;                         // 'Engenharia' -> 12, 'Faculdade' -> 9, 'FEUP' -> 23
    fillMap(names);                                 // 'Inicializado apenas' -> 0
    showContent(names);                             // 'Porto' -> 11, 'Universidade' -> 4

    cout << exists(names, "Fabio") << endl;         // 0
    cout << exists(names, "FEUP") << endl;          // 1

    removeKey(names, "Fabio");                      //  A chave Fabio não existe no map
    removeKey(names, "FEUP");                       // 'Engenharia' -> 12, 'Faculdade' -> 9, 'Inicializado apenas' -> 0
                                                    // 'Porto' -> 11, 'Universidade' -> 4

    // Multimap
    multimap<string, int> names2;                   // 'Engenharia' -> 11, 'Engenharia' -> 13, 'Engenharia' -> 12
    fillMap(names2);                                // 'FEUP' -> 23, 'FEUP' -> 20, 'FEUP' -> 24
    showContent(names2);                            // 'Faculdade' -> 9
                                                    // 'Porto' -> -5, 'Porto' -> 10, 'Porto' -> 11, 'Porto' -> 11
                                                    // 'Universidade' -> -5, 'Universidade' -> 6, 'Universidade' -> 4

    cout << exists(names2, "Fabio");                // 0
    cout << exists(names2, "Porto");                // 1

    removeKey(names2, "Fabio");                     // 'Engenharia' -> 11, 'Engenharia' -> 13, 'Engenharia' -> 12
    removeKey(names2, "Porto");                     // 'FEUP' -> 23, 'FEUP' -> 20, 'FEUP' -> 24
    showContent(names2);                            // 'Faculdade' -> 9
                                                    // 'Porto' -> 10, 'Porto' -> 11, 'Porto' -> 11
                                                    // 'Universidade' -> -5, 'Universidade' -> 6, 'Universidade' -> 4
    return 0;
}
````
<br>

## 2 - HashTables

Guarda itens numa tabela de modo a que a inserção, pesquisa e remoção sejam numa complexidade temporal baixa, num caso favorável até mesmo O(1). O index da tabela, para cada objecto a alocar, é construído com base numa hashFunction. Exemplos baseados em modular hashing: <br>

```c++
int HashTable::intHash(int value) {
    return value % this->table.size();
}

@Overload
int HashTable::stringHash(const string &value) {
    return value.size() % this->table.size();
}

@Overload
int HashTable::stringHash(const string &value) {
    int total = 0;
    for (char letter : value) total += (int) letter;
    return total % this->table.size();
}

int HashTable::objectHash(const Person &person) {
    return stringHash(person.name) ^ person.age ^ person.grade;
}

template <class F>
int HashTable::templateHash(const F &value) {
    std::hash(T) h; // h é um objecto
    return h(T);
}
```

Os principais problemas deste método são:
  - Colisões, exploradas a seguir
  - Gasto de memória, pois a tabela é uma estrutura auxiliar;
  - Obter uma eficiente `hashFunction`, isto é, que minimize as colisões entre objectos;

### 2.1 - Collisions

Há dois métodos principais para implementar a tabela de hash e acima de tudo que lidam com as colisões que daí possam derivar.
Para os dois exemplos abaixo, considera-se `load factor / lambda` = número de elementos a albergar / número de índices disponíveis. Para haver um `resize` basta que o load factor passe para o dobro ou metade, dependendo da técnica utilizada.

#### 2.1.1 - Open Addressing / Closed hashing

As chaves são guardadas na própria tabela e se o valor não der para ser guardado no index retornado pela função hash, tenta colocar-se na posição index+1, até conseguir ter espaço livre. <br>
Neste caso em concreto, se a função lambda = 1/8, então para cada hash teremos mais 7 índices vazios para suportar as colisões. Ao remover, colocar um número `del / tombstone` para que exista `lazy delection`, ou seja, para que a próxima inserção seja colocada ali mas a pesquisa considere aquele lugar ainda como ocupado.
Apesar de ser o método que gasta menos memória (não tem de possuir apontadores nem listas ligadas como o tópico 2.1.2), quando lambda for  terá de se fazer um `rehash` completo, além de poderem existir grandes intervalos completamente preenchidos (clusters) ou esparsos, que invalidam a complexidade temporal almejada (O(1)), passando a ser na pior situação O(n).

#### 2.1.2 - Separate Chaining / Open hashing

Cada índice da tabela corresponde, na verdade, a uma lista ligada de elementos que alberga objectos com o mesmo hash. Assim a função labda é superior a 1, por exemplo 8, o que significa que cada index comporta até 7 colisões com o objecto primário.
A maior desvantagem é mesmo a utilização quase indevida de memória extra, a performence vai sendo deteorada gradualmente até haver necessidade de fazer `rehash` completo.
A complexidade de pesquisa é O(lambda), o tamanho da lista de cada index na tabela.

### 2.2 - HashTables in STL

A STL implementa HashTables para as seguintes estruturas de dados:
- `unordered_set`, parecido com um set, só que não ordenado. Não permite chaves duplicadas;
- `unordered_multiset`, parecido com um multiset, só que não ordenado. Permite chaves duplicadas;
- `unordered_map`, 
- `unordered_multimap`,

#### Alguns exemplos de funcionamento:

##### 2.2.1 - Listagem, inserção, remoção, pesquisa e ordenação em unordered_sets / unordered_multisets

````c++
void showContent (const unordered_set<string> &names) {
    for (unordered_set<string>::iterator it = names.begin() ; it != names.end() ; it++) {
        cout << "Name: " << *it << endl;
    }
}

void fillUnorderedSet(unordered_set<string> &names) {
    names.insert("cao");
    names.insert("cao");
    names.insert("gato");
    names.insert("tartaruga");
    names.insert("passaro");
    names.insert("passaro");
    names.insert("gato");
}

bool exists(const unordered_set<string> &names, const string &key) {
    return names.find(key) != names.end();
}

void removeKey(unordered_set<string> &names, const string &key) {
    if (exists(names, key))
        names.erase(names.find(key));
}

int main () {

    // unordered sets
    unordered_set<string> names;
    fillUnorderedSet(names);
    showContent(names);                                         // passaro, gato, tartaruga, cao
    cout << exists(names, "cao") << endl;                   // 1
    cout << exists(names, "papagaio") << endl;              // 0
    removeKey(names, "passaro");                            // gato, tartaruga, cao

    // unordered multisets
    unordered_multiset<string> names2;
    fillUnorderedSet(names2);
    showContent(names2);                                  // passaro, passaro, gato, gato, cao, cao, tartaruga
    cout << exists(names2, "cao") << endl;            // 1
    cout << exists(names2, "papagaio") << endl;       // 0
    removeKey(names2, "passaro");                         // passaro, gato, gato, cao, cao, tartaruga

    return 0;
}
````

##### 2.2.2 - Listagem, inserção, remoção, pesquisa e ordenação em unordered_maps / unordered_multimaps

```c++

```