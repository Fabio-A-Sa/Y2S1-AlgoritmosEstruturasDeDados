// Created on October, 2021

#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using testing::Eq;

template <class Number>
Number squareRoot (Number n) { return sqrt(n); }

// invariant: em cada iteração, sum = 1+2+…+(k-1)
// variant: n + 1 - k, pois o valor máximo de K será n + 1 e K é incrementado a cada iteração

long sum (int n) {
    long sum = 0;
    int k = 1;
    while (k <= n) {
        sum += k;
        k++;
    }
    return sum;
}

int main () {

    double x = 25.651;
    double result = squareRoot(25.651);
    cout << "\n\nPreconditions and postconditions\n" << endl;
    cout << "X = " << x << endl << "Result = squareRoot(X) = " << result << endl;
    cout << "Preconditions: x >= 0\nPostconditions: result >= 0 && pow(result, 2) == x\n" << endl;

    cout << "Parcial correctness:\n\t- Com as pré-condições correctas, caso o algoritmo termine então está correcto;" << endl;
    cout << "\t- Detetar a invariante do ciclo e provar a veracidade para o início, meio e fim;\n" << endl;
    cout << "Total correctness:\n\t- Com as pré-condições correctas provar que o algoritmo termina;" << endl;
    cout << "\t- Detetar a invariante do ciclo e provar a veracidade para o início, meio e fim;" << endl;
    cout << "\t- Detetar a variante do ciclo e provar que é uma expressão inteira, não-negativa e decrescente;\n\n" << endl;

    return 0;
}

template <class Comparable>
Comparable maxSubSum1(const vector<Comparable> &a)
{
    Comparable maxSum = 0;
    for (int i = 0 ; i < a.size() ; i++)
        for (int j = i; j < a.size(); j++)
        {
            Comparable thisSum = 0;
            for (int k = i; k <= j; k++)
                thisSum += a[k];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    return maxSum;
}

template <class Comparable>
Comparable maxSubSum2(const vector<Comparable> &a)
{
    Comparable maxSum = 0;
    for (int i = 0 ; i < a.size() ; i++)
    {
        Comparable thisSum = 0;
        for (int j = i; j < a.size(); j++)
        {
            thisSum += a[j];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

template <class Comparable>
Comparable maxSubSum3(const vector<Comparable> &a)
{
    Comparable thisSum = 0; Comparable maxSum = 0;
    for (int i=0 ; i < a.size() ; i++ )
    {
        thisSum += a[i];
        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}

int main () {

    srand(time(NULL));
    vector<int> numbers = { -3, 1, -8, 4, -1, 2, 1, -5, 5, -3, 1, 10, 2, 4, 5, -8, 4, -1, 2, 1,
                            -5, 5, -3, 1, -8, 4, -1, 2, 1, -5, 5, -3, 1, -8, 4, -1, 2, 1, -5, 5, -3 };

    time_t t0, t1, t2, t3, t4, t5;
    int a1, a2, a3;

    t0 = time(nullptr);
    a1 = maxSubSum1(numbers);
    t1 = time(nullptr); t1 = t1 - t0;

    t2 = time(nullptr);
    a2 = maxSubSum2(numbers);
    t3 = time(nullptr); t3 = t3 - t2;

    t4 = time(nullptr);
    a3 = maxSubSum3(numbers);
    t5 = time(nullptr); t5 = t5 - t4;

    cout << "\n\nBig-O Notation\n" << endl;
    cout << "First algorithm\nResult = " << a1 << " in " << t1 << " seconds\nTime complexity: O(n^3)\nSpace complexity: 1\n" << endl;
    cout << "Second algorithm\nResult = " << a2 << " in " << t3 << " seconds\nTime complexity: O(n^2)\nSpace complexity: 1\n" << endl;
    cout << "Third algorithm\nResult = " << a3 << " in " << t5 << " seconds\nTime complexity: O(n)\nSpace complexity: 1\n" << endl;

    return 0;
}

template <class F>
int sequentialSearch(vector<F> values, F number) {

    for (int i = 0 ; i < values.size() ; i++ ) {
        if (values[i] == number) return i;
    }
    return -1;

    // Time complexity: O(n)
    // Space complexity: O(1)
}

template <class F>
int binarySearch(vector<F> values, F number) {

    int left = 0, right = values.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (values[middle] < number) {          // Na parte da direita
            left = middle + 1;
        } else if (number < values[middle]) {   // Na parte da esquerda
            right = middle - 1;
        } else {
            return middle;
        }
    }
    return -1;

    // Time complexity: O(log2(n))
    // Space complexity: O(1)
}

template <class F>
int findK (vector<F> &board, F atmost)
{
    int s = 0, painters = 1;
    for (int i = 0; i < board.size(); i++)  // Vai somando
    {
        s += board[i];
        if (s > atmost)
        {
            s = board[i];   // Se a soma for o máximo possível
            painters++;     // Chama outro pintor
        }
    }
    return painters;
}

template <class F>
int paintersProblem (F k, vector<F> board) {

    int n = board.size(), s = 0, m = 0;
    for(int i = 0; i < n; i++)
    {
        m = max(m, board[i]);       // m = máximo do vector = mínimo de tempo possível
        s += board[i];              // s = soma de todos os tempos = máximo de tempo possível
    }
    int low = m, high = s;          // [máximo do vector, soma de todos os tempos]
    while (low < high)
    {
        int mid = low + (high - low) / 2;       // Observa o tempo intermédio
        int painters = findK(board, mid);       // É possível que k pintores ou menos pintem esse tempo?
        if (painters <= k) high = mid;          // Se sim, o intervalo fica [máximo do vector, tempo médio]
        else low = mid + 1;                     // Senão, o intervalo fica [tempo médio, soma de todos os tempos]
    }
    return low;

    // Time complexity: O(n + nlog2(n)) -> loop inicial (n) e a cada iteração (max = log2(n)) existe uma iteração de n elementos (função findK())
    // Space complexity: O(1)
}

int main () {

    vector<int> numbers = {0, 3, 2, 4, 35, 52, 3, 6, 32, 52, 14, 634, 3, 54, 87, 23, 3, 8, 3, 0, 4, -4, 2, 7, 8, 2};
    cout << "\nTest sequentialSearch() method:" << endl;
    for (int i = 0 ; i < 10 ; i++ ) {
        cout << i << "? " << sequentialSearch(numbers, i) << endl;
    }

    vector<int> sortedNumbers = {0, 4, 6, 7, 12, 45, 67, 89, 133, 245, 246, 467, 6789, 23455};
    vector<int> keys = {3, 7, 12, 245, 246, 247, 890, 23455};
    cout << "\nTest binarySearch() method:" << endl;
    for (auto key : keys) {
        cout << key << "? " << binarySearch(sortedNumbers, key) << endl;
    }

    vector<vector<vector<int>>> input = {
            {{2}, {10, 20, 30, 40}},
            {{3}, {34, 23, 123, 35, 346, 23, 1, 4, 52, 3262, 3, 213, 4, 1}},
            {{3}, {10, 20, 30, 40}},
            {{5}, {34, 23, 123, 35, 346, 23, 1, 4, 52, 3262, 3, 213, 4, 1}},
            {{2}, {34, 23, 123, 35, 4, 52, 3262, 3, 213, 4, 1}},
    };

    cout << "\nTest paintersProblem() method:" << endl;
    for (auto pair : input) {
        cout << paintersProblem (pair[0][0], pair[1]) << endl;
    }

    return 0;
}

class Person {

    string name;
    unsigned int up;
    int age;

public:
    Person();
    Person(string name, unsigned int up, int age);
    void setName(string name);
    void setAge(int age);
    void setUp(unsigned int up);
    string getName() const;
    unsigned int getUp() const;
    int getAge() const;
    void presentation();
    bool operator == (const Person &p) const;
    bool operator < (const Person &p) const;
};

Person::Person() {}
Person::Person(string name = "UNKNOWN", unsigned int up = 0, int age = 0) : name(name), up(up), age(age) {}

void Person::setName (string name) { this->name = name; }
void Person::setAge (int age) { this-> age = age; }
void Person::setUp (unsigned int up) { this->up = up; }

string Person::getName() const { return name; }
unsigned int Person::getUp() const { return up; }
int Person::getAge() const { return age; }

ostream & operator << (ostream & os, const Person &p) {
    os << p.getName() << " have up " << p.getUp() << " and " << p.getAge() << " years old" << endl;
    return os;
}

bool Person::operator == (const Person &p) const {
    return (age == p.getAge() && up == p.getUp() && name == p.getName());
}

bool Person::operator < (const Person &p) const {
    return age < p.getAge();
}

bool isTeenager (const Person &p) { return p.getAge() <= 20 ; }

bool younger (const Person &p1, const Person &p2) {
    return p1.getAge() < p2.getAge();
}

void writeVector (vector<Person> p) {
    for (auto person : p) { cout << person; }
    cout << endl;
}

void sequentialSearch() {

    cout << "\nTest sequentialSearch() STL algorithm:" << endl;
    vector<int> numbers = {23, 3, 123, 3, 1, 3, 5, 65, 32, 654, 246, 776, 3, 76, 457, 5, 975, 3224, 8, 2, 5, 42, 644, 75, 2, 44, 64};
    vector<int> keys = {1, 2, 3, 4, 5, 6, 7, 8};
    for (auto key : keys) {
        vector<int>::iterator it = find(numbers.begin(), numbers.end(), key);
        string result = it == numbers.end() ? "not found" : "found";
        cout << key << "? " << result << endl;
    }
}

bool lambda (int x, int y) { return x < y; }

void binarySearch() {

    cout << "\nTest binarySearch() STL algorithm:" << endl;
    vector<int> sortedNumbers = {0, 4, 6, 7, 12, 45, 67, 89, 133, 245, 246, 467, 6789, 23455};
    vector<int> keys = {3, 7, 12, 245, 246, 247, 890, 23455};
    for (auto key : keys) {
        string result = binary_search(sortedNumbers.begin(), sortedNumbers.end(), key, lambda) ? "found" : "not found";
        cout << key << "? " << result << endl;
    }
    cout << endl;
}

void testPerson() {

    // Fill vector
    vector<Person> people;
    people.push_back(Person("Rui Silva", 21812313, 34));
    people.push_back(Person("Antonio Matos", 23983123, 24));
    people.push_back(Person("Maria Barros", 28328123, 20));
    people.push_back(Person ("Carlos Sousa", 2938921798, 18));
    people.push_back(Person("Fernando Cardoso", 202083293, 33));
    cout << "\nPresentation:" << endl;
    writeVector(people);

    // Is there a person named Fabio Sa in vector?
    Person me = Person("Fabio Sa");
    vector<Person>::iterator i = find(people.begin(), people.end(), me);
    if (i == people.end()) {
        cout << me.getName() << " not found in vector" << endl;
    } else {
        cout << me.getName() << " is in vector" << endl;
    }
    me.setAge(19);
    me.setUp(202007658);
    people.push_back(me);
    vector<Person>::iterator f = find(people.begin(), people.end(), me);
    if (f == people.end()) {
        cout << me.getName() << " not found in vector" << endl;
    } else {
        cout << me.getName() << " is in vector" << endl;
    }
    cout << endl;

    // Are teenagers in people?
    f = find_if(people.begin(), people.end(), isTeenager);
    if (f == people.end()) {
        cout << "There's no teenager in this vector" << endl;
    } else {
        cout << (*f).getName() << " is a teenager" << endl;
    }
    cout << endl;

    // List all teenagers in people
    for (vector<Person>::iterator it = people.begin(); it != people.end() ; it++) {
        if (isTeenager(*it)) { cout << *it; }
    }
    cout << endl;

    // Searching using binarySearch STL algorithm
    people.clear();
    people.push_back(Person("Fabio Sa", 202007658, 19));
    people.push_back(Person("Tó Ferreira", 223007658, 24));
    people.push_back(Person("Alexandre Afonso", 12343124, 25));
    people.push_back(Person("Correia Lopes", 543545658, 34));
    people.push_back(Person("Torcato Silva", 70213658, 92));

    for (int age = 15 ; age < 26 ; age++) {
        Person unknown = Person("unknown", 0, age);
        string answer = binary_search(people.begin(), people.end(), unknown, younger) ? " found" : " not found";
        cout << unknown.getAge() << answer << " in people" << endl;
    }
}

int main () {

    sequentialSearch();
    binarySearch();
    testPerson();
    return 0;
}

class InfoCartao {

public:
    string nome;
    bool presente;
};

class ParqueEstacionamento {

    unsigned vagas;
    unsigned  lotacao;
    vector<InfoCartao> clientes;
    unsigned numMaximoClientes;

public:
    ParqueEstacionamento(unsigned lot, unsigned nMaxCli);
    bool adicionaCliente(const string & nome);
    bool retiraCliente(const string & nome);
    bool entrar(const string & nome);
    bool sair(const string & nome);
    int posicaoCliente(const string & nome) const;
    unsigned getNumLugares() const;
    unsigned getNumMaximoClientes() const;
    unsigned getNumLugaresOcupados() const;
    unsigned getNumClientesAtuais() const;
};

ParqueEstacionamento::ParqueEstacionamento(unsigned lot, unsigned nMaxCli) {
    this->lotacao = lot;
    this->numMaximoClientes = nMaxCli;
    this->vagas = lot;
    this->clientes = {};
}

unsigned ParqueEstacionamento::getNumLugares() const {
    return lotacao;
}

unsigned ParqueEstacionamento::getNumMaximoClientes() const {
    return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const {
    for (unsigned i=0; i<clientes.size(); i++)
        if (clientes[i].nome == nome) return i;
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome) {
    if (clientes.size() == numMaximoClientes) return false;
    if (posicaoCliente(nome) != -1) return false;
    InfoCartao info;
    info.nome = nome;
    info.presente = false;
    clientes.push_back(info);
    return true;
}

bool ParqueEstacionamento::entrar(const string & nome) {
    if (!vagas) return false;
    if (posicaoCliente(nome) == -1) return false;
    if (clientes[posicaoCliente(nome)].presente) return false;
    clientes[posicaoCliente(nome)].presente = true;
    vagas --;
    return true;
}

bool ParqueEstacionamento::retiraCliente(const string & nome) {

    for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
        if ( (*it).nome == nome ) {
            if (!(*it).presente) {
                clientes.erase(it);
                return true;
            }
            else return false;
        }
    return false;
}

bool ParqueEstacionamento::sair(const string & nome)
{
    if (posicaoCliente(nome) == -1) return false;
    if (!clientes[posicaoCliente(nome)].presente) return false;
    clientes[posicaoCliente(nome)].presente = false;
    vagas ++;
    return true;
}

unsigned ParqueEstacionamento::getNumLugaresOcupados() const {
    return lotacao - vagas;
}

unsigned ParqueEstacionamento::getNumClientesAtuais() const {
    return clientes.size();
}

TEST(test_1, abrirParque){
ParqueEstacionamento p1(4, 6);
// Testa se o parque foi aberto com a lotacao indicada
EXPECT_EQ(4, p1.getNumLugares());
// Testa se o parque foi aberto com o numero maximo de clientes indicado
EXPECT_EQ(6, p1.getNumMaximoClientes());
}

TEST(test_1, adicionarCliente){
ParqueEstacionamento p1(3, 5);
// Testa se deixa adicionar um novo cliente
EXPECT_EQ(true, p1.adicionaCliente("Joao"));
p1.adicionaCliente("Antonio");
p1.adicionaCliente("Rui");
p1.adicionaCliente("Maria");
p1.adicionaCliente("Clara");
// Testa se recusa novo cliente quando numero maximo de clientes foi atingido
EXPECT_EQ(false, p1.adicionaCliente("Paula"));
// Testa se retorna a posicaoo correcta do cliente
EXPECT_EQ(1, p1.posicaoCliente("Antonio"));
// Testa se retorna -1 caso o cliente nao exista
EXPECT_EQ(-1, p1.posicaoCliente("Joana"));
}

TEST(test_1, entrarParque){
ParqueEstacionamento p1(3, 5);
p1.adicionaCliente("Joao");
p1.adicionaCliente("Maria");
p1.adicionaCliente("Antonio");
p1.adicionaCliente("Rui");
// Testa se deixa entrar no parque um cliente existente
EXPECT_EQ(true, p1.entrar("Maria"));
// Testa se nao deixa entrar no parque um cliente que nao existe
EXPECT_EQ(false, p1.entrar("Paula"));
// Testa se nao dexia entrar em cliente que ja la esta
EXPECT_EQ(false, p1.entrar("Maria"));
p1.entrar("Joao");
p1.entrar("Antonio");
// Testa se nao deixa entrar quando a lotacao esta completa
EXPECT_EQ(false, p1.entrar("Rui"));
}

TEST(test_1, retirarCliente){
ParqueEstacionamento p1(3, 5);
p1.adicionaCliente("Joao");
p1.adicionaCliente("Maria");
p1.adicionaCliente("Antonio");
p1.entrar("Maria");
// Testa se nao deixa remover cliente que esta dentro do parque
EXPECT_EQ(false, p1.retiraCliente("Maria"));
// Testa se deixa remover cliente que esta fora do parque
EXPECT_EQ(true, p1.retiraCliente("Antonio"));
// Testa se nao deixa remover cliente que nao existe
EXPECT_EQ(false, p1.retiraCliente("Ana"));
}

TEST(test_1, sairParque){
ParqueEstacionamento p1(3, 5);
p1.adicionaCliente("Joao");
p1.adicionaCliente("Maria");
p1.adicionaCliente("Rui");
p1.entrar("Maria");
p1.entrar("Joao");
p1.entrar("Rui");
// Testa se um cliente estacionado no parque, sai.
EXPECT_EQ(true, p1.sair("Maria"));
// Testa se nao deixa sair um cliente que nao esta estacionado.
EXPECT_EQ(false, p1.sair("Maria"));
// Testa se nao deixa sair um cliente que nao existe.
EXPECT_EQ(false, p1.sair("Antonio"));
}

TEST(test_1, lugaresLotacaoParque){
ParqueEstacionamento p1(3, 5);
p1.adicionaCliente("Joao");
p1.adicionaCliente("Maria");
p1.adicionaCliente("Antonio");
p1.entrar("Maria");
p1.entrar("Antonio");
// Testa se Lotacao do parque esta correcta
EXPECT_EQ(3, p1.getNumLugares());
// Testa se o numero de viaturas presentes no parque esta correcto
EXPECT_EQ(2, p1.getNumLugaresOcupados());
// Testa se o o numero de clientes registados no parque esta correcto
EXPECT_EQ(3, p1.getNumClientesAtuais());
}

class Mail {

    string sender;
    string receiver;
    string zipCode;

public:
    Mail(string send, string rec, string zcode);
    virtual ~Mail();
    string getZipCode() const;
    virtual unsigned int getPrice() const = 0;
};

class RegularMail: public Mail {

    unsigned int weight;

public:
    RegularMail(string send, string rec, string code, unsigned int w);
    unsigned int getPrice() const;
};

class GreenMail: public Mail {

    string type;

public:
    GreenMail(string send, string rec, string code, string t);
    unsigned int getPrice() const;
};

Mail::Mail(string send, string rec, string zcode) {
    this->sender = send;
    this->zipCode = zcode;
    this->receiver = rec;
}

Mail::~Mail() {};

string Mail::getZipCode() const {
    return zipCode;
}

RegularMail::RegularMail(string send, string rec, string zcode, unsigned int w) : Mail(send, rec, zcode) {
    this->weight = w;
}

GreenMail::GreenMail(string send, string rec, string zcode, string t) : Mail(send, rec, zcode) {
    this->type = t;
}

unsigned int RegularMail::getPrice() const {
    if (weight <= 20) return 50;
    if (weight > 20 && weight <= 100) return 75;
    if (weight > 100 && weight <= 500) return 140;
    return 325;
}

unsigned int GreenMail::getPrice() const {
    if (type == "envelope") return 80;
    if (type == "bag") return 200;
    return 240;
}

class Postman {

    unsigned int id;
    string name;
    vector<Mail *> myMail;

public:
    Postman();
    void setName(string nm);
    void addMail(Mail *m);
    void addMail(vector<Mail *> mails);
    string getName() const;
    vector<Mail *> getMail() const;
    unsigned int getID() const;
};

Postman::Postman(): id(0) {}

void Postman::setName(string nm){
    name = nm;
}

string Postman::getName() const{
    return name;
}

vector<Mail *> Postman::getMail() const {
    return myMail;
}

void Postman::addMail(Mail *m) {
    myMail.push_back(m);
}

void Postman::addMail(vector<Mail *> mails) {
    myMail.insert(myMail.end(),mails.begin(),mails.end());
}

unsigned int Postman::getID() const{
    return id;
}
class PostOffice {

    vector<Mail *> mailToSend;
    vector<Mail *> mailToDeliver;
    vector<Postman> postmen;
    string firstZipCode, lastZipCode;

public:
    PostOffice();
    PostOffice(string firstZCode, string lastZCode);
    void addMailToSend(Mail *m);
    void addMailToDeliver(Mail *m);
    void addPostman(const Postman &p);
    vector<Mail *> getMailToSend() const;
    vector<Mail *> getMailToDeliver() const;
    vector<Postman> getPostman() const;
    vector<Mail *> removePostman(string name);
    vector<Mail *> endOfDay(unsigned int &balance);
    Postman addMailToPostman(Mail *m, string name);
};

class NoPostmanException {

    string name;

public:
    NoPostmanException(string name);
    string getName() const;
};

PostOffice::PostOffice() {}

PostOffice::PostOffice(string firstZCode, string lastZCode) {
    this->firstZipCode = firstZCode;
    this->lastZipCode = lastZCode;
}

NoPostmanException::NoPostmanException(string name) {
    this->name = name;
}

string NoPostmanException::getName() const {
    return name;
}

void PostOffice::addMailToSend(Mail *m) {
    mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
    mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
    postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
    return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
    return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
    return postmen;
}

vector<Mail *> PostOffice::removePostman(string name) {

    vector<Mail *> res = {};
    for (vector<Postman>::iterator p = postmen.begin() ; p != postmen.end() ; p++) {
        if ((*p).getName() == name) {
            res = (*p).getMail();
            postmen.erase(p);
            return res;
        }
    }
    return res;
}

vector<Mail *> PostOffice::endOfDay(unsigned int &balance) {

    unsigned int total = 0;
    vector<Mail *> answer;
    string n1 = firstZipCode.substr(0, 4) + firstZipCode.substr(5, 3);
    stringstream toInt1(n1);
    int minimo = 0; toInt1 >> minimo;
    string n2 = lastZipCode.substr(0, 4) + lastZipCode.substr(5, 3);
    stringstream toInt2(n2);
    int maximo = 0; toInt2 >> maximo;

    for (vector<Mail *>::iterator i = mailToSend.begin() ; i != mailToSend.end() ; i++) {

        total += (*i)->getPrice();

        string currentZip = (*i)->getZipCode().substr(0, 4) + (*i)->getZipCode().substr(5, 3);
        stringstream toInt(currentZip);
        int current = 0; toInt >> current;

        if (current >= minimo && current <= maximo) {
            addMailToDeliver(*i);
        } else {
            answer.push_back(*i);
        }
    }
    mailToSend.clear();
    balance = total;
    return answer;
}

Postman PostOffice::addMailToPostman(Mail *m, string name) {

    for (auto postman : postmen) {
        if (postman.getName() == name) {
            postman.addMail(m);
            return postman;
        }
    }
    NoPostmanException non = NoPostmanException(name);
    throw (non);
}

