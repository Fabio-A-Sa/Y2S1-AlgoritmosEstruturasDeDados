// Created on October, 2021
// @author: Fábio Araújo de Sá

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

TEST(test_1, getPrice){
RegularMail m1("manuel", "ana","3330-454", 401);
RegularMail m2("ana", "rui","4400-146", 10);
GreenMail m3("maria", "luis","2520-110", "envelope");
GreenMail m4("carla", "lara","7100-514", "box");

EXPECT_EQ(140, m1.getPrice());
EXPECT_EQ(50, m2.getPrice());
EXPECT_EQ(80, m3.getPrice());
EXPECT_EQ(240, m4.getPrice());
}

TEST(test_1, removePostman){
PostOffice po;
Postman p1;
p1.setName("joao");
p1.addMail(new RegularMail("ana", "rui","4400-146", 33));
Postman p2;
p2.setName("paulo");
p2.addMail(new RegularMail("rui", "ana","3330-454", 33));
p2.addMail(new RegularMail("luis", "maria","8600-306", 67));
p2.addMail(new RegularMail("carla", "lara","7100-514", 67));
p2.addMail(new RegularMail("luis", "rui","4400-146", 33));
Postman p3;
p3.setName("fernando");
p3.addMail(new RegularMail("manuel", "ana","3330-454", 33));
po.addPostman(p1);
po.addPostman(p2);
po.addPostman(p3);

vector <Mail *> mailP = po.removePostman("joao");
EXPECT_EQ(1, mailP.size());
EXPECT_EQ(2,po.getPostman().size());

mailP.clear();
mailP = po.removePostman("sergio");
EXPECT_EQ(0, mailP.size());

mailP.clear();
mailP = po.removePostman("paulo");
EXPECT_EQ(4, mailP.size());

mailP.clear();
mailP = po.removePostman("fernando");
EXPECT_EQ(1, mailP.size());

EXPECT_EQ(0,po.getPostman().size());
}

TEST(test_1, endOfDay){
PostOffice po("2600-000", "3999-999");
po.addMailToSend(new RegularMail("manuel", "ana","3330-454", 401));
po.addMailToSend(new RegularMail("ana", "rui","4400-146", 10));
po.addMailToSend(new GreenMail("maria", "luis","2520-110", "envelope"));
po.addMailToSend(new GreenMail("carla", "lara","7100-514", "box"));

unsigned int bal = 0;
vector<Mail *> mailToOtherPO = po.endOfDay(bal);
EXPECT_EQ(510, bal);
EXPECT_EQ(3,mailToOtherPO.size());
EXPECT_EQ(1,po.getMailToDeliver().size());
EXPECT_EQ(0,po.getMailToSend().size());

PostOffice po2("2600-000", "3999-999");
po2.addMailToSend(new RegularMail("rita", "joana","3200-514", 120));

mailToOtherPO = po2.endOfDay(bal);
EXPECT_EQ(140, bal);
EXPECT_EQ(0,mailToOtherPO.size());
EXPECT_EQ(1,po2.getMailToDeliver().size());
EXPECT_EQ(0,po2.getMailToSend().size());
}

TEST(test_1, addMailToPostman){
PostOffice po;
Postman p1;
p1. setName("joao");
p1.addMail(new RegularMail("ana", "rui","4400-146", 33));
p1.addMail(new RegularMail("luis", "rui","4400-146", 33));
Postman p2;
p2. setName("paulo");
Postman p3;
p3.setName("fernando");
p3.addMail(new RegularMail("manuel", "ana","3330-454", 33));
po.addPostman(p1);
po.addPostman(p2);
po.addPostman(p3);

Postman px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"paulo");
EXPECT_EQ(1,px.getMail().size());

EXPECT_THROW(po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"luis"), NoPostmanException);

try {
px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"joao");
EXPECT_EQ(3,px.getMail().size());
px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"ricardo");
}
catch(NoPostmanException &e) {
EXPECT_EQ("ricardo", e.getName());
}

px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"fernando");
EXPECT_EQ(2,px.getMail().size());
}

unsigned fibonacci_1(unsigned n) {

    unsigned valPrevPrev = 0, valPrev = 1;
    if (n == 0)
        return valPrevPrev;
    if (n == 1)
        return valPrev;
    unsigned val;
    for (unsigned i = 2; i <= n; i ++)
    {
        val = valPrevPrev + valPrev;
        valPrevPrev = valPrev;
        valPrev = val;
    }
    return val;

    // Complexidade espacial: O(1), o número de variáveis usadas não dependem do valor de n inicial
    // Complexidade temporal: O(n), o número de ciclos vai depender diretamente do valor de n inicial
}

unsigned fibonacci_2(unsigned n) {

    if (n <= 1)
        return n;
    return fibonacci_2(n-1) + fibonacci_2(n-2);

    // Complexidade espacial: O(n), o número de variáveis usadas depende do número de chamadas recursivas (n)
    // Complexidade temporal: O(2^n), o número de chamadas recursivas é sempre exponencial de base 2 (duas para cada valor de n)
}

template <class T>
class MyVector {

    vector<T> values;

public:
    MyVector();
    ~MyVector();
    void push_back(T v1);
    vector<T> getValues() const;
    T max() const;
    bool hasDuplicates() const;
    void removeDuplicates() ;
};

class EmptyVector { };

template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

template <class T>
T MyVector<T>::max() const {

    if (!values.empty()) {
        T maxValue = values[0];
        for (int i = 0 ; i < values.size() ; i++ ) {
            if (maxValue < values[i]) maxValue = values[i];
        }
        return maxValue;

    } else {
        EmptyVector e = EmptyVector();
        throw (e);
    }

    // Complexidade espacial: O(1), pois as variáveis estáticas usadas não dependem do tamanho do vector
    // Complexidade temporal: O(n), pois percorre-se o vector de tamanho n (for loop)
}

template<class T>
bool MyVector<T>::hasDuplicates() const {

    if (values.empty()) return false;
    for (int i = 0 ; i < values.size() ; i++) {
        for (int j = i + 1 ; j < values.size() ; j++) {
            if (values[i] == values[j]) return true;
        }
    }
    return false;

    // Complexidade espacial: O(1), pois as variáveis estáticas usadas não dependem do tamanho do vector
    // Complexidade temporal: O(n^2), pois no pior cenário percorre-se o vector n(n-1) vezes
}

template<class T>
bool notIn (vector<T> vector, T number) {

    for (int i = 0 ; i < vector.size() ; i++) {
        if (number == vector[i]) return false;
    }
    return true;
}

template<class T>
void MyVector<T>::removeDuplicates() {

    if (hasDuplicates()) {
        vector<T> unique = {};
        for (auto number : values) {
            if (notIn(unique, number)) unique.push_back(number);
        }
        values = unique;
    }

    // Complexidade Temporal: O(n^2), no pior cenário, para cada n é necessário percorrer n vezes o vector unique (bool notIn)
    // Complexidade Espacial: O(1), as variáveis usadas não dependem do tamanho n do vector
}

TEST(test_1, max){

MyVector<int> v;
vector<int> tests = {10, 100, 1000, 10000, 100000, 1000000, 10000000};

for (auto test : tests) {
MyVector<int> v;
for (int i = 0 ; i <= test ; i++) { v.push_back(i); }
ticks tstart, tend;
unsigned t;
tstart = getticks();
EXPECT_EQ(test,v.max());
tend = getticks();
t = ( (int)tend - (int)tstart )/1000;
cout << "(vmax(size " << test << ")) t = " <<  t <<endl;
} }

TEST(test_1, hasDuplicates){
MyVector<int> v;

v.push_back(4); v.push_back(33);
v.push_back(14); v.push_back(18);
v.push_back(45);
EXPECT_EQ(false,v.hasDuplicates());

v.push_back(33);
EXPECT_EQ(true,v.hasDuplicates());
}

TEST(test_1, removeDuplicates){
MyVector<int> v;

v.push_back(4); v.push_back(33);
v.push_back(14); v.push_back(18);
v.push_back(45); v.push_back(10);

v.removeDuplicates();
vector<int> vx = v.getValues();
EXPECT_EQ(6, vx.size());
EXPECT_EQ(4, vx[0]);
EXPECT_EQ(18, vx[3]);

v.push_back(33); v.push_back(20);
v.push_back(18);
v.removeDuplicates();
vx = v.getValues();
EXPECT_EQ(7, vx.size());
EXPECT_EQ(4, vx[0]);
EXPECT_EQ(33, vx[1]);
EXPECT_EQ(18, vx[3]);
EXPECT_EQ(20, vx[6]);

v.push_back(20); v.push_back(20);
v.push_back(20); v.push_back(44);
v.removeDuplicates();
vx = v.getValues();
EXPECT_EQ(8, vx.size());
EXPECT_EQ(4, vx[0]);
EXPECT_EQ(18, vx[3]);
EXPECT_EQ(20, vx[6]);
EXPECT_EQ(44, vx[7]);
}

TEST(test_2, fibonacci_1){
EXPECT_EQ(0, fibonacci_1(0));
EXPECT_EQ(1, fibonacci_1(1));
EXPECT_EQ(1, fibonacci_1(2));
EXPECT_EQ(13, fibonacci_1(7));
EXPECT_EQ(144, fibonacci_1(12));
EXPECT_EQ(2584, fibonacci_1(18));
}

TEST(test_2, fibonacci_2){
EXPECT_EQ(0, fibonacci_2(0));
EXPECT_EQ(1, fibonacci_2(1));
EXPECT_EQ(1, fibonacci_2(2));
EXPECT_EQ(13, fibonacci_2(7));
EXPECT_EQ(144, fibonacci_2(12));
EXPECT_EQ(2584, fibonacci_2(18));
}

void showVector (const vector<int> &vector) {
    for (auto number : vector) {
        cout << number << " ";
    }
    cout << endl << endl;
}

void insertionSort (vector<int> numbers) {

    for (int i = 1 ; i < numbers.size() ; i++ ) {
        int temp = numbers[i], j;
        for (j = i ; j > 0 && temp < numbers[j-1] ; j-- ) {
            numbers[j] = numbers[j-1];
        }
        numbers[j] = temp;
    }
    cout << "Insertion Sort: " << endl;
    showVector(numbers);
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void selectionSort (vector<int> numbers) {

    for (int i = 0 ; i < numbers.size() ; i++ ) {
        int min = i;
        for (int j = i+1 ; j < numbers.size() ; j++ ) {
            if (numbers[j] < numbers[min]) min = j;
        }
        int temp = numbers[i];
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }
    cout << "Selection Sort: " << endl;
    showVector(numbers);
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void bubbleSort (vector<int> numbers) {

    bool swap = true;
    while (swap) {
        swap = false;
        for (int i = 0 ; i < numbers.size()-1 ; i++ ) {
            for (int j = i + 1 ; j < numbers.size() ; j++ ) {
                if (numbers[i] > numbers[j]) {
                    int temp = numbers [i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
                    swap = true;
                }
            }
        }
    }
    cout << "Bubble Sort: " << endl;
    showVector(numbers);
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void shellSort (vector<int> numbers) {

    int j;
    for (int gap = numbers.size() / 2 ; gap > 0 ; gap /= 2) {
        for (int i = gap ; i < numbers.size() ; i++ ) {
            int temp = numbers[i];
            for (j = i ; j >= gap && temp < numbers[j-gap] ; j -= gap) {
                numbers[j] = numbers[j-gap];
            }
            numbers[j] = temp;
        }
    }
    cout << "Shell Sort: " << endl;
    showVector(numbers);
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void merge(vector <int> &v, vector<int> &tmpArr, int leftPos, int rightPos, int rightEnd) {

    int leftEnd = rightPos--, tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    while ( leftPos <= leftEnd && rightPos <= rightEnd )
        if ( v[leftPos] <= v[rightPos] )
            tmpArr[tmpPos++] = v[leftPos++];
        else
            tmpArr[tmpPos++] = v[rightPos++];
    while ( leftPos <= leftEnd )
        tmpArr[tmpPos++] = v[leftPos++];
    while ( rightPos <= rightEnd )
        tmpArr[tmpPos++] = v[rightPos++];
    for ( int i = 0; i < numElements; i++, rightEnd-- )
        v[rightEnd] = tmpArr[rightEnd];
}

void mergeSort(vector <int> &v, vector<int> &tmpArr, int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(v, tmpArr, left, center);
        mergeSort(v, tmpArr, center + 1, right);
        merge(v, tmpArr, left, center +1, right);
    }
}

void mergeSortMain(vector <int> v) {
    vector<int> tmpArr(v.size());
    mergeSort(v, tmpArr, 0, v.size()-1);
    cout << "Merge Sort: " << endl;
    showVector(v);
    // Time complexity: O(n*log(n))
    // Space complexity: O(n)
}

void quickSort (vector<int> numbers) {

    // TODO
    cout << "Quick Sort: " << endl;
    showVector(numbers);
}

int main () {

    srand(time(NULL));
    int min = -5, max = 100, size = 20;
    vector<int> numbers = {};

    // Fill vector with random numbers
    for (int i = 0 ; i < size ; i++) {
        numbers.push_back(min + (rand() % (max - min)));
    }
    cout << "\nInitial vector" << endl; showVector(numbers);

    // Tests
    insertionSort(numbers);
    selectionSort(numbers);
    bubbleSort(numbers);
    shellSort(numbers);
    mergeSortMain(numbers);
    quickSort(numbers);

    return 0;
}

FunSearchProblem::FunSearchProblem() {}

int FunSearchProblem::facingSun(const vector<int> & values) {

    if (!values.empty()) {
        int result = 1, maxHeight = values[0];
        for (int i = 1 ; i < values.size() ; i++ ) {
            if (maxHeight < values[i]) {
                maxHeight = values[i];
                result++;
            }
        }
        return result;
    }
    return 0;
}

int FunSearchProblem::squareR(int num) {

    if (num > 0) {

        int left = 1, right = num, middle;

        while (right - left > 1) {

            middle = (right + left) / 2;
            if (middle*middle > num) {
                right = middle;
            } else if (middle*middle < num) {
                left = middle;
            } else {
                return middle;
            }
        }
        return left;

    } else {
        cout << "Invalid number" << endl;
        return 0;
    }
}

bool thereArePositives(const vector<int> & values) {
    for (auto number : values) {
        if (number > 0) return true;
    }
    return false;
}

int FunSearchProblem::smallestMissingValue(const vector<int> & values) {

    if (thereArePositives(values)) {
        int toSearch = 1;
        while (true) {
            bool found = false;
            for (auto number : values) {
                if (number == toSearch) {
                    toSearch++;
                    found = true;
                    break;
                }
            }
            if (!found) return toSearch;
        }
    } else {
        return 0;
    }
}

int findStudents(const vector<int> & values, int students) {

    int sum = 0, maxStudents = 1;
    for (auto number : values) {
        sum += number;
        if (sum > students) {
            sum = number;
            maxStudents++;
        }
    }
    return maxStudents;
}

int FunSearchProblem::minPages(const vector<int> & values, int numSt) {

    if (!values.empty() && values.size() >= numSt) {

        int low = values[0], high = 0;
        for (auto number : values) {
            high += number;
            if (low < number) low = number;
        }

        while (low < high) {
            int middle = low + (high-low) / 2;
            if (findStudents(values, middle) <= numSt) high = middle;
            else low = middle + 1;
        }
        return low;
    }
    return -1;
}

/**
 * The class with methods using sequential search and binary search algorithms
 */
class FunSearchProblem {

public:

    /**
     * A default constructor of class FunSearchProblem. No arguments needed.
     */
    FunSearchProblem();

    /**
     * A function that determines a smallest missing integer positive value in vector
     * @param values a vector of integer numbers passed by reference
     * @return an smallest integer missing number in vector
     */
    static int smallestMissingValue(const vector<int> & values);

    /**
     * A functions that determines the number of buildings facing the sun based on their height
     * @param values a vector of integer numbers (heights) passed by reference
     * @return an integer number of buildings that are facing the sun
     */
    static int facingSun(const vector<int> & values);

    /**
     * A function that returns an integer number that is the square root of a given number, if this number is a perfect
     * square, or an integer approximated number closer to the real square root, using Binary Search algorithm.
     * @param num an integer number passed by value
     * @return a integer square root (total or partial) of a given number
     */
    static int squareR(int num);

    /**
     * A function that returns a minimum pages of a given library based on students distribution
     * using Binary Search algorithm.
     * @param values a vector of integer numbers (number of pages in each book) passed by reference
     * @param numSt an integer number of students available passed by value
     * @return a integer number of minimum pages allocated for each student
     */
    static int minPages(const vector<int> & values, int numSt);
};

TEST(test, facingsun){

FunSearchProblem problem;
vector<int> alturas = {12, 3, 45, 45, 56, 23, 89, 10, 100, 25, 67};
EXPECT_EQ(5, problem.facingSun(alturas));
alturas = {12, 3, 45, 45, 56, 23, 89, 10, 100, 25, 67, 1002, 1002};
EXPECT_EQ(6, problem.facingSun(alturas));
}

TEST(test, squareR){

FunSearchProblem problem;
EXPECT_EQ(3, problem.squareR(10));
EXPECT_EQ(10, problem.squareR(102));
EXPECT_EQ(13, problem.squareR(169));
EXPECT_EQ(13, problem.squareR(170));
EXPECT_EQ(0, problem.squareR(-2));
EXPECT_EQ(2, problem.squareR(8));
EXPECT_EQ(1, problem.squareR(1));
}

TEST(test, missingvalue){

FunSearchProblem problem;
vector<int> numbers;

numbers = {7, 0, 4, 2, 3, -6, 7, 8, 20, 1, -1, 5};
EXPECT_EQ(6, problem.smallestMissingValue(numbers));
numbers.clear();
EXPECT_EQ(0, problem.smallestMissingValue(numbers));
numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 14};
EXPECT_EQ(12, problem.smallestMissingValue(numbers));
numbers = {-1, 2, 4, 5, 6, 7, 9, 10, 11, 14, 3};
EXPECT_EQ(1, problem.smallestMissingValue(numbers));
}

TEST(test, minPages){

FunSearchProblem problem;
vector<int> numbers;

numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
EXPECT_EQ(10, problem.minPages(numbers, 10));
numbers = {10, 20, 34, 42, 42, 63, 78, 98, 102, 123};
EXPECT_EQ(123, problem.minPages(numbers, 9));
numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
EXPECT_EQ(-1, problem.minPages(numbers, 11));
}

int main() {

    int lines, attemp;
    cin >> lines;
    int count = 0;

    for (int i = 0 ; i < lines ; i++) {
        cin >> attemp;
        if (attemp == 42) count++;
    }

    cout << count << endl;

    return 0;
}

bool match (long int attemp, int sum) {

    int currentSum = 0, digit;
    while (attemp) {
        digit = attemp % 10;
        attemp = attemp / 10;
        currentSum += digit;
    }
    return currentSum == sum;
}

int main() {

    long int number;
    int sum, lines;

    cin >> lines;
    for (int i = 0 ; i < lines ; i++) {
        cin >> number >> sum;
        while (!match(number + 1, sum)) number++;
        cout << number + 1 << endl;
    }

    return 0;
}

const vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                              'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q',
                              'R', 'S', 'T', 'U', 'V', 'X', 'X'   };

const vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

const int diffBetweenTypes = pow(numbers.size(), 4) * pow(letters.size(), 2);

int findType (string &matricula) { // Find type (1, 2, 3, 4) and modify matricula to type 1 to compare later
    return 1;
}

int diffInt(int c1, int c2) {
    return abs(c2-c1);
}

int diffChar(char c1, char c2) {
    int  = 0;
    for (int i = 0 ; i < letters.size() ; i++) {
        if ()
    }
    return abs();
}

int main () {

    int lines;
    string matricula1, matricula2;

    cin >> lines;
    for (int i = 0 ; i < lines ; i++) {
        cin >> matricula1 >> matricula2;
        cout << matricula2 << endl;
    }

    return 0;
}

const int MIN_VALUE = 0;
const int MAX_VALUE = 100;
const int LENGTH = 20;

vector<int> getUnsortedVector() {

    vector<int> numbers = {};
    for (int i = 0 ; i < LENGTH ; i++) {
        numbers.push_back(MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE)));
    }
    return numbers;
}

void showVector (vector<int> vector) {
    for (auto number : vector) {
        cout << number << " ";
    }
    cout << endl;
}

int getMax(vector<int> vector) {

    if (!vector.empty()) {
        int max = vector[0];
        for (int i = 1 ; i < vector.size() ; i++) if (vector[i] > max) max = vector[i];
        return max;
    } else return 0;
}

void insertionSortRun (vector<int> numbers) {

    cout << "Insertion Sort Algorithm: " << endl;
    showVector(numbers);

    for (int i = 1 ; i < numbers.size() ; i++ ) {
        int temp = numbers[i], j;
        for (j = i ; j > 0 && temp < numbers[j-1] ; j-- ) {
            numbers[j] = numbers[j-1];
        }
        numbers[j] = temp;
    }

    showVector(numbers); cout << endl;
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void selectionSortRun (vector<int> numbers) {

    cout << "Selection Sort Algorithm: " << endl;
    showVector(numbers);

    for (int i = 0 ; i < numbers.size() ; i++ ) {
        int min = i;
        for (int j = i+1 ; j < numbers.size() ; j++ ) {
            if (numbers[j] < numbers[min]) min = j;
        }
        int temp = numbers[i];
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }

    showVector(numbers); cout << endl;
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void bubbleSortRun (vector<int> numbers) {

    cout << "Bubble Sort Algorithm: " << endl;
    showVector(numbers);

    bool swap = true;
    while (swap) {
        swap = false;
        for (int i = 0 ; i < numbers.size()-1 ; i++ ) {
            for (int j = i + 1 ; j < numbers.size() ; j++ ) {
                if (numbers[i] > numbers[j]) {
                    int temp = numbers [i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
                    swap = true;
                }
            }
        }
    }

    showVector(numbers); cout << endl;
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void shellSortRun (vector<int> numbers) {

    cout << "Shell Sort Algorithm: " << endl;
    showVector(numbers);

    int j;
    for (int gap = numbers.size() / 2 ; gap > 0 ; gap /= 2) {
        for (int i = gap ; i < numbers.size() ; i++ ) {
            int temp = numbers[i];
            for (j = i ; j >= gap && temp < numbers[j-gap] ; j -= gap) {
                numbers[j] = numbers[j-gap];
            }
            numbers[j] = temp;
        }
    }
    showVector(numbers); cout << endl;
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void merge(vector <int> &v, vector<int> &tmpArr, int leftPos, int rightPos, int rightEnd) {

    int leftEnd = rightPos - 1, tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    while ( leftPos <= leftEnd && rightPos <= rightEnd )
        if ( v[leftPos] <= v[rightPos] )
            tmpArr[tmpPos++] = v[leftPos++];
        else
            tmpArr[tmpPos++] = v[rightPos++];
    while ( leftPos <= leftEnd )
        tmpArr[tmpPos++] = v[leftPos++];
    while ( rightPos <= rightEnd )
        tmpArr[tmpPos++] = v[rightPos++];
    for ( int i = 0; i < numElements; i++, rightEnd-- )
        v[rightEnd] = tmpArr[rightEnd];
}

void mergeSort(vector <int> &v, vector<int> &tmpArr, int left, int right) {

    if (left < right){
        int center = (left + right) / 2;
        mergeSort(v, tmpArr, left, center);
        mergeSort(v, tmpArr, center + 1, right);
        merge(v, tmpArr, left, center +1, right);
    }
}

void mergeSortRun(vector <int> v) {

    cout << "Merge Sort Algorithm:" << endl;
    showVector(v);
    vector<int> tmpArr(v.size());
    mergeSort(v, tmpArr, 0, v.size()-1);
    showVector(v); cout << endl;
    // Time complexity: O(n*log(n))
    // Space complexity: O(n)
}

void swap (int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

const int &median3(vector<int> &v, int left, int right){

    int center = (left+right) /2;
    if (v[center] < v[left])
        swap(v[left], v[center]); //swap elements if order incorrect
    if (v[right] < v[left])
        swap(v[left], v[right]); //swap elements if order incorrect
    if (v[right] < v[center])
        swap(v[center], v[right]); //swap elements if order incorrect
    swap(v[center], v[right-1]); //puts pivot in position right-1
    return v[right-1];
}

void quickSort(vector<int> &v, int left, int right){

    if (right-left <= 10) // if small vector, using insertionSortRun(v);

        for (int i = 1 ; i < v.size() ; i++ ) {
            int temp = v[i], j;
            for (j = i ; j > 0 && temp < v[j-1] ; j-- ) {
                v[j] = v[j-1];
            }
            v[j] = temp;
        }

    else {

        int x = median3(v, left, right); // x is the pivot
        int i = left; int j = right-1;
        while (true) {
            while (v[++i] < x) ;
            while (x < v[--j]) ;
            if (i < j)
                swap(v[i], v[j]);
            else break;
        }
        swap(v[i], v[right-1]); //reset pivot
        quickSort(v, left, i-1);
        quickSort(v, i+1, right);
    }
}

void quickSortRun (vector<int> numbers) {

    cout << "Quick Sort Algorithm:" << endl;
    showVector(numbers);
    quickSort(numbers, 0, numbers.size()-1);
    showVector(numbers); cout << endl;
    // Time complexity: O(n*log(n)) or O(n^2) if pivot is minimum value (worst case)
    // Space complexity: O(n) or O(log(n)) in best case
}

void countingSortRun(vector<int> numbers) {

    cout << "Counting Sort Algorithm:" << endl;
    showVector(numbers);

    // Get maximum:
    int maximum = getMax(numbers);

    // Create an empty vector and fill with number of occurrences/index
    vector<int> count(maximum);
    for (auto number : numbers) count[number] += 1;

    // Create a sorted vector based on index vector
    vector<int> sortedNumbers = {};
    for (int i = 0 ; i <= maximum ; i++) {
        while (count[i]) {
            sortedNumbers.push_back(i);
            count[i]--;
        }
    }
    showVector(sortedNumbers); cout << endl;
    // Time complexity: O(n+k), k is the maximum element
    // Space complexity: O(k), k is the maximum element
}

void STLSortRun(vector<int> vector) {

    cout << "STL Sort():" << endl;
    showVector(vector);
    sort(vector.begin(), vector.end());
    showVector(vector); cout << endl;
}

void countSort(vector<int> &v, int size, int exp) {

    vector<int> output(size);
    vector<int> count(10);

    for (int i = 0 ; i < size ; i++) {
        count[(v[i] / exp) % 10]++;
    }

    for (int i = 1 ; i < 10 ; i++) {
        count[i] += count[i-1];
    }

    for (int i = size -1 ; i >= 0 ; i--) {
        output[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }

    for (int i = 0 ; i < size ; i++) {
        v[i] = output[i];
    }
}

void radixSort(vector<int> &numbers, int size) {

    int maximum = getMax(numbers);
    for (int i = 1 ; maximum / i > 0 ; i *= 10)
        countSort(numbers, numbers.size(), i);

}

void radixSortRun(vector<int> numbers) {

    cout << "Radix Sort Algorithm: " << endl;
    showVector(numbers);

    radixSort(numbers, numbers.size());

    showVector(numbers);
    // d --> maximum number of digits; k --> maximum element;
    // Time complexity: O(d*(n+k))
    // Space complexity: O(d*(n+10))
}

int main () {

    srand(time(NULL));

    // Test sorting comparative based algorithms
    insertionSortRun(getUnsortedVector());
    selectionSortRun(getUnsortedVector());
    bubbleSortRun(getUnsortedVector());
    shellSortRun(getUnsortedVector());
    mergeSortRun(getUnsortedVector());
    quickSortRun(getUnsortedVector());

    // Using STL algorithm: IntroSort() = (QuickSort + HeapSort) + InsertionSort
    STLSortRun(getUnsortedVector());

    // Test sorting non-comparative based algorithms
    countingSortRun(getUnsortedVector());
    radixSortRun(getUnsortedVector());

    return 0;
}

using namespace std;

class FunSortProblem {

public:

    FunSortProblem();

    static void expressLane(vector<Product> &products, unsigned k);
    static int minDifference(const vector<unsigned> &values, unsigned nc);
    static unsigned minPlatforms (const vector<float> &arrival, const vector<float> &departure);
    static void nutsBolts(vector<Piece> &nuts, vector<Piece> &bolds);
};

Piece::Piece(string i, float d): id(i), diameter(d) {}

string Piece::getId() const {
    return id;
}

float Piece::getDiameter() const {
    return diameter;
}

class Piece {

    string id;
    float diameter;

public:
    Piece(string i, float d);
    string getId() const;
    float getDiameter() const;
};

Product::Product(string i, float p, float w): id(i), price(p), weight(w) {}

string Product::getId() const {
    return id;
}

float Product::getPrice() const {
    return price;
}

float Product::getWeight() const {
    return weight;
}

bool Product::operator < (const Product &p) const {
    if (this->getPrice() == p.getPrice()) {
        return this->getWeight() < p.getWeight();
    }
    return this->getPrice() < p.getPrice();
}

class Product {

    string id;
    float price;
    float weight;

public:
    Product(string i, float p, float w);
    string getId() const;
    float getPrice() const;
    float getWeight() const;
    bool operator < (const Product &p) const;
};

using testing::Eq;

TEST(test, expressLane) {

Product p1("pastaX1",3.2,500);
Product p2("peanutsYY",5.4,700 );
Product p3("cookieSA2",4.2,600);
Product p4("milkAS",5.4,600);
vector<Product> products = {p1,p2,p3,p4};

FunSortProblem::expressLane(products,3);
EXPECT_EQ(3,products.size());
if (products.size() == 3) {
EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "pastaX1"; }));
EXPECT_EQ(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "peanutsYY"; }));
EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "cookieSA2"; }));
EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "milkAS"; }));
}

products = {p1,p2,p3};
FunSortProblem::expressLane(products,3);
EXPECT_EQ(3,products.size());
if (products.size() == 3) {
EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "pastaX1"; }));
EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "peanutsYY"; }));
EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "cookieSA2"; }));
}

products = {p1,p2,p3};
FunSortProblem::expressLane(products,4);
EXPECT_EQ(3,products.size());
if (products.size() == 3) {
EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "pastaX1"; }));
EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "peanutsYY"; }));
EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "cookieSA2"; }));
}

products = {};
FunSortProblem::expressLane(products,2);
EXPECT_EQ(0,products.size());
}

TEST(test, minDifference) {

EXPECT_EQ(6,FunSortProblem::minDifference({3,4,1,9,56,7,9,12}, 5));
EXPECT_EQ(-1,FunSortProblem::minDifference({3,4,1,9,56,7}, 7));
EXPECT_EQ(11,FunSortProblem::minDifference({3,4,1,9,12,7}, 6));
EXPECT_EQ(2,FunSortProblem::minDifference({7, 3, 2, 4, 9, 12, 56}, 3));
}

TEST(test, minPlatforms) {

EXPECT_EQ(3,FunSortProblem::minPlatforms({9.00, 9.40, 9.50, 11.00, 15.00, 18.00}, {9.10, 12.00, 11.20, 11.30, 19.00, 20.00}));
EXPECT_EQ(1,FunSortProblem::minPlatforms({9.00, 11.00, 12.35}, {10.00, 12.00, 12.40}));
EXPECT_EQ(3,FunSortProblem::minPlatforms({2.00, 2.10, 3.00, 3.20, 3.50, 5.00 }, { 2.30, 3.40, 3.20, 4.30, 4.00, 5.20 }));
}

TEST(test, nutsBolts) {

vector<Piece> nuts = {Piece("n1",10),Piece("n7",9),Piece("n4",11),Piece("n2",8),Piece("n5",7),Piece("n8",12), Piece("n9",15)};
vector<Piece> bolts = { Piece("b5",7), Piece("b8",12), Piece("b1",10), Piece("b2",8), Piece("b9",15), Piece("b4",11), Piece("b7",9)};
FunSortProblem::nutsBolts(nuts, bolts);
EXPECT_EQ(7, nuts.size());
EXPECT_EQ(7, bolts.size());
for (unsigned i=0; i<7; i++) {
EXPECT_EQ(true,nuts[i].getDiameter() == bolts[i].getDiameter());
}
}

FunSortProblem::FunSortProblem() {}

template <class F>
void swapElements(F &p1, F &p2) {
    F temp = p1;
    p1 = p2;
    p2 = temp;
}

void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {

    if (products.size() > k) {

        // Sort vector based on Selection Sort Algorithm and operator < implemented in class Product
        for (int i = 0 ; i < products.size() ; i++ ) {
            int min = i;
            for (int j = i+1 ; j < products.size() ; j++ ) {
                if (products[j] < products[min]) min = j;
            }
            swapElements(products[i], products[min]);
        }

        // Buy all first k products
        products.erase(products.begin() + k, products.end());
    }
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {

    if (values.size() >= nc) {

        // Sorting chocolate vector using Selection Sort Algorithm
        vector<unsigned> v = values;

        for (int i = 0 ; i < v.size() ; i++ ) {
            int min = i;
            for (int j = i+1 ; j < v.size() ; j++ ) {
                if (v[j] < v[min]) min = j;
            }
            swapElements(v[i], v[min]);
        }

        // Get minimum difference in [i,i+nc]
        int minDiff = INT_MAX, currentDiff;
        for (int i = 0 ; i < v.size() - nc + 1; i++) {
            currentDiff = v[i+nc-1] - v[i];
            if (currentDiff < minDiff) minDiff = currentDiff;
        }
        return minDiff;

    } else return -1;

    // Time complexity: O(n^2)
    // Space complexity: O(n), clone of initial vector to swap values if necessary
}

bool key (pair<float, char> &p1, pair<float, char> &p2) {
    return p1.first < p2.first;
}

bool exist(const vector<char> & horarios) {
    for (auto h : horarios) if (h != 'V') return true;
    return false;
}

void generateTrain (vector<char> &horarios) {

    char toSeek = 'A';
    for (auto & h : horarios) {
        if (h == toSeek) {
            h = 'V'; // visited
            toSeek = toSeek == 'A' ? 'D' : 'A';
        }
    }
}

unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {

    if (!arrival.empty() || !departure.empty()) {

        int platforms = 0;
        vector<pair<float, char>> order = {};
        for (auto time : arrival) order.push_back(pair<float, char>(time, 'A'));
        for (auto time : departure) order.push_back(pair<float, char>(time, 'D'));

        sort(order.begin(), order.end(), key);
        vector<char> horarios = {};
        for (auto pair : order) horarios.push_back(pair.second);

        while (exist(horarios)) {
            generateTrain(horarios);
            platforms++;
        }

        /**
            A --> Chegada
            D --> Partida
            V --> Horário visitado

            Cada comboio consome uma plataforma e a máxima sequência de pares de horários (A + D)

            A D A A A D D D A A D D --> platforms = 0, existem ainda horários = true;
            V V V A A V D D V A V D --> platforms = 1, existem ainda horários = true;
            V V V V A V V D V V V V --> platforms = 2, existem ainda horários = true;
            V V V V V V V V V V V V --> platforms = 3, existem ainda horários = false;

            A D A D A D --> platforms = 0, existem ainda horários = true;
            V V V V V V --> platforms = 1, existem ainda horários = false;
         */

        return platforms;

    } else return arrival.empty() ? departure.size() : arrival.size();

    // Time complexity: O(n^2)
    // Space complexity: O(n)
}

int partition(vector<Piece> &v, int low, int high) {

    float pivot = v[high].getDiameter();
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (v[j].getDiameter() <= pivot) {
            i++;
            swapElements(v[i], v[j]);
        }
    }
    swapElements(v[i + 1], v[high]);
    return (i + 1);
}

void quickSort(vector<Piece> &v, int low, int high) {

    if (low < high) {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

bool NBKey (const Piece &p1, const Piece &p2) {
    return p1.getDiameter() < p2.getDiameter();
}

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

    sort(nuts.begin(), nuts.end(), NBKey);
    sort(bolts.begin(), bolts.end(), NBKey);

    // Time complexity: O(n*log(n));
    // Space complexity: O(n);
}

class Letter {

    char letter;
    int frequency, firstOccurrence;

public:
    Letter(char letter, int frequency, int firstOccurrence);
    char getLetter() const;
    int getFrequency() const;
    int getFirstOccurrence() const;
};

Letter::Letter(char letter, int frequency, int firstOccurrence) :
        letter(letter),
        frequency(frequency),
        firstOccurrence(firstOccurrence) {}

char Letter::getLetter() const { return letter; }
int Letter::getFrequency() const { return frequency; }
int Letter::getFirstOccurrence() const { return firstOccurrence; }

class ADN {

    vector<Letter> letters;
    string sequence;
    string unique;

public:
    ADN(string name);
    void showFrequency();
    friend bool notIn (char c, string s);
};

bool notIn (char c, string s) {
    for (auto l : s) if (c == l) return false;
    return true;
}

bool key (const Letter &a, const Letter &b) {
    if (a.getFrequency() == b.getFrequency()) {
        return a.getFirstOccurrence() < b.getFirstOccurrence();
    } else return a.getFrequency() > b.getFrequency();
}

ADN::ADN(string sequence) : sequence(sequence) {

    this->letters.clear();
    int firstOcc;
    string unique = "";

    for (auto letter : sequence) if (notIn(letter, unique)) unique += letter;

    for (auto letter : unique) {
        for (int i = 0 ; i < sequence.size() ; i++) {
            if (sequence[i] == letter) {
                firstOcc = i;
                break;
            }
        }
        Letter l = Letter(letter, count(sequence.begin(), sequence.end(), letter), firstOcc);
        letters.push_back(l);
    }
    sort(letters.begin(), letters.end(), key);
}

void ADN::showFrequency() {

    for (auto letter : letters) {
        cout << letter.getLetter() << " " << letter.getFrequency()  << endl;
    }
}

int main () {

    string sequence;
    cin >> sequence;
    ADN input = ADN(sequence);
    input.showFrequency();

    return 0;
}

void showResult (vector<int> result, int question) {

    if (!result.empty()) {

        if (result.size() == 1) {
            cout << result[result.size()-1] << endl;
        } else {
            int minRange = abs(question - result[result.size()-1]);
            for (int i = 0 ; i < result.size() ; i++ ) {
                if (result[i] == result[result.size()-1]) {
                    cout << result[i];
                } else {
                    if (abs(result[i]-question) == minRange) {
                        cout << result[i] << " ";
                    }
                }

            }
            cout << endl;
        }

    } else cout << endl;
}

vector<int> solve (vector<int> numbers, int question) {

    vector<int> result = {};
    int a, b, minRange = 2147483647; // Mooshak não reconhece o INT_MAX?!
    for (int i = 0 ; i < numbers.size() ; i++) {
        for (int j = i + 1 ; j < numbers.size() ; j++) {
            if (abs(numbers[i]+numbers[j]-question) <= minRange) {
                a = numbers[i];
                b = numbers[j];
                minRange = abs(a+b-question);
                result.push_back(a+b);
            }
        }
    }

    // Remove duplicates using iterators
    for (vector<int>::iterator i = result.begin() ; i != result.end() ; i++) {
        for (vector<int>::iterator j = i + 1 ; j != result.end() ; j++) {
            if (*i == *j) {
                result.erase(j);
                j--;
            }
        }
    }

    return result;
}

int main () {

    int nNumbers, currentNumber, nQuestions, currentQuestion;
    vector<int> numbers = {}, questions = {};

    cin >> nNumbers;
    for (int i = 0 ; i < nNumbers ; i++) {
        cin >> currentNumber;
        numbers.push_back(currentNumber);
    }
    sort(numbers.begin(), numbers.end());

    cin >> nQuestions;
    for (int i = 0 ; i < nQuestions ; i++) {
        cin >> currentQuestion;
        questions.push_back(currentQuestion);
    }

    /**
    numbers = {5, 6, 8, 9};
    questions = {1, 2, 14, 16, 18, 1000};
    sort(numbers.begin(), numbers.end());
    */

    for (auto question : questions) {
        vector<int> result = solve (numbers, question);
        showResult(result, question);
    }

    return 0;
}

unsigned int Game::numberOfWords(string phrase) {
    int result = 0;
    for (auto c : phrase) if (c == ' ') result++;
    return result ? result + 1 : result;
}

Game::Game() {
    this->kids.clear();
}

Game::Game(list<Kid>& l2) {
    this->kids = l2;
}

void Game::addKid(const Kid k1) {
    kids.push_back(k1);
}

list<Kid> Game::getKids() const {
    return kids;
}

void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}

void Game::splitKids(queue<Kid> &boys, queue<Kid> &girls) const {

    for (auto const &kid : kids) {
        if (kid.getSex() == 'm') boys.push(kid);
        else girls.push(kid);
    }
}

Kid Game::loseGame(string phrase) {

    int words = numberOfWords(phrase);
    int index = 0;

    while (kids.size() > 1) {
        index = (words-1+index) % kids.size();
        list<Kid>::iterator it = kids.begin();
        for (int i = 0 ; i < index ; i++) { it++; }
        kids.remove(*it);
    }

    return kids.front();
}

list<Kid> Game::removeOlder(unsigned id) {

    list<Kid> result = {};
    for (auto kid : kids) {
        if (kid.getAge() > id) {
            result.push_back(kid);
            kids.remove(kid);
        }
    }
    return result;
}

queue<Kid> Game::rearrange() {

    queue<Kid> result = {}, qBoys = {}, qGirls = {};
    list<Kid> sortedKids = {};
    splitKids(qBoys, qGirls);

    int boys = qBoys.size(), girls = qGirls.size();
    int nBoys = girls < boys ? boys/girls : 1;
    int nGirls = girls >= boys ? girls/boys : 1;

    int loop = kids.size() / (nGirls+nBoys);

    while (loop) {

        int qtdGirls = nGirls, qtdBoys = nBoys;
        while (qtdGirls) {
            sortedKids.push_back(qGirls.front());
            qGirls.pop();
            qtdGirls--;
        }
        while (qtdBoys) {
            sortedKids.push_back(qBoys.front());
            qBoys.pop();
            qtdBoys--;
        }
        loop--;
    }

    while (qGirls.size()) {
        result.push(qGirls.front());
        qGirls.pop();
    }
    while (qBoys.size()) {
        result.push(qBoys.front());
        qBoys.pop();
    }

    kids = sortedKids;
    return result;
}

bool Game::operator == (Game& g2) {

    if (this->getKids().size() != g2.getKids().size()) return false;

    int i = 0;
    for (auto k1 : this->getKids()) {
        int j = 0;
        for (auto k2 : g2.getKids()) {
            if (i == j && !(k1 == k2)) return false;
            j++;
        }
        i++;
    }

    return true;
}

list<Kid> Game::shuffle() const {

    list<Kid> result = {}, k = kids;
    int index;

    while (k.size()) {

        index = rand() % k.size(); // random index in [0..k.size()]

        int i = 0;
        for (auto kid : k) {
            if (i == index) {
                result.push_back(kid);
                k.remove(kid);
                break;
            }
            i++;
        }

    }
    return result;
}

class Game
{
    list<Kid> kids;

public:
    Game();
    Game(list<Kid>& l2);
    static unsigned numberOfWords(string phrase);
    void addKid(const Kid k1);
    list<Kid> getKids() const;
    void setKids(const list<Kid>& l1);
    Kid loseGame(string phrase);
    list<Kid> removeOlder(unsigned id);
    queue<Kid> rearrange();
    bool operator==(Game& g2);
    list<Kid> shuffle() const;
    void splitKids(queue<Kid> &a, queue<Kid> &b) const;
};

Kid::Kid(): name(""), age(0), sex('x') {}

Kid::Kid(string nm, unsigned a, char s): name(nm), age(a), sex(s) {}

Kid::Kid(const Kid& k1) {
    this->name = k1.name;
    this->age = k1.age;
    this->sex = k1.sex;
}

string Kid::getName() const {
    return this->name;
}

unsigned Kid::getAge() const {
    return this->age;
}

char Kid::getSex() const {
    return this->sex;
}

bool Kid::operator == (const Kid& k2) const {
    return( this->name == k2.name && this->age == k2.age);
}

string Kid::write() const {
    stringstream oss;
    oss << name << " : " << age;
    return oss.str();
}

class Kid {

    string name;
    int age;
    char sex;

public:
    Kid();
    Kid(string nm, unsigned a, char s);
    Kid(const Kid& k1);
    string getName() const;
    unsigned getAge() const;
    char getSex() const;
    bool operator == (const Kid& k2) const;
    string write() const;
    friend ostream & operator<<(ostream & o, const Kid & d);
};

template <class T>
class StackExt {

    stack<T> values;
    stack<T> minimums;

public:
    StackExt() {};
    bool empty() const;
    T& top();
    void pop();
    void push(const T& val);
    T& findMin();
};

template <class T>
bool StackExt<T>::empty() const {
    return this->values.empty();
}

template <class T>
T& StackExt<T>::top() {
    T& result = this->values.top();
    return result;
}

template <class T>
void StackExt<T>::pop() {
    if (this->minimums.top() == this->values.top()) {
        this->minimums.pop();
    }
    this->values.pop();
}

template <class T>
void StackExt<T>::push(const T& val) {
    if (this->minimums.empty()) this->minimums.push(val);
    this->values.push(val);
    if (val < this->minimums.top()) this->minimums.push(val);
}

template <class T>
T& StackExt<T>::findMin() {
    T& result = this->minimums.top();
    return result;
}

int getWords (const string &phrase) {
    int result = 0;
    for (auto letter : phrase) if (letter == ' ') result++;
    return phrase.size()? result + 1 : 0;
}

string getLoser (int words, list<string> kids) {

    int index = 0;

    while (kids.size() > 1) {
        index = (words-1+index) % kids.size();
        list<string>::iterator it = kids.begin();
        for (int i = 0 ; i < index ; i++) { it++; }
        kids.remove(*it);
    }

    return kids.front();
}

void showResults (const string& phrase, const list<string> &kids) {

    string loser = getLoser(getWords(phrase), kids);
    if (loser == "Carlos") {
        cout << "O Carlos nao se livrou" << endl;
    } else {
        cout << "O Carlos livrou-se (coitado do " << loser << "!)" << endl;
    }
}

int main () {

    list<string> names = {};
    int loops, nNames;
    string phrase, currentName;
    cin >> loops;

    for (int i = 0 ; i < loops ; i++) {
        cin.clear();
        cin.ignore(10000, '\n');
        getline(cin, phrase);
        cin >> nNames;
        for (int j = 0 ; j < nNames ; j++) {
            cin >> currentName;
            names.push_back(currentName);
        }
        showResults(phrase, names);
        names.clear();
    }

    return 0;
}

int calculator (int a, int b, char operation) {

    switch (operation) {
        case '+': return a+b;
        case '-': return a-b;
        case '/': return a/b;
        case '*': return a*b;
        default: return 0;
    }
}

void solve (const vector<string> &expression) {

    stack<int> numbers = {};

    for (string c : expression) {

        bool isNumber = true;
        for (char digit : c) {
            isNumber &= isdigit(digit);
        }

        if (isNumber) {
            numbers.push(stoi(c)); // char to int using ASCII code :)

        } else {
            if (numbers.size() > 1) {
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                int result = calculator(a, b, c[0]);
                numbers.push(result);
            } else {
                cout << "Expressao Incorrecta" << endl;
                return;
            }
        }
    }
    if (numbers.size() == 1) {
        cout << numbers.top() << endl;
    } else {
        cout << "Expressao Incorrecta" << endl;
    }
}

int main () {

    int loops;
    string currentExpression;
    vector<string> expression;
    cin >> loops;
    cin.ignore(1000, '\n');

    for (int i = 0 ; i < loops ; i++) {
        getline(cin, currentExpression);
        string currentElement = "";
        for (char c : currentExpression) {

            if (c != ' ') currentElement += c;
            else {
                expression.push_back(currentElement);
                currentElement = "";
            }
        }
        expression.push_back(currentElement);
        solve(expression);
        expression.clear();
    }

    return 0;
}

class Plane {

public:

    char AorL;
    string name;
    int minute;
    int delay;
    bool runway;

    Plane (string name, int minute, char AorL) : name(name), minute(minute), delay(0), AorL(AorL), runway(false) {}

    bool operator < (Plane p);
    bool operator == (Plane p);
};

ostream & operator << (ostream & os,  Plane p) {
    os << p.name << " " << p.delay << endl;
    return os;
}

bool Plane::operator < (Plane p) {
    if (minute == p.minute) {
        return AorL < p.AorL;
    } else return minute < p.minute;
}

bool Plane::operator == (Plane p) {
    return runway == p.runway && AorL == p.AorL && minute == p.minute && name == p.name;
}

void findPlanes (vector<Plane> &planes, int clock) {

    vector<Plane> result = {};
    for (Plane plane : planes) {
        if (clock == plane.minute && !plane.runway) result.push_back(plane);
    }
    sort(result.begin(), result.end());

    for (auto & plane2 : result) {                       // todos os aviões
        cout << "current avião: " << plane2.name << endl;
        for ( auto & plane : planes) {                  // os selecionados -> os que têm a pista assegurada por ordem
            if (plane == plane2) {                      // se o avião estiver na lista de selecionados (por ordem)
                plane.runway = true;
                plane2.runway = true;// voa
                cout << plane2.name << " voou" << endl;
            } else {
                if (!plane.runway) plane.delay++;
            }
        }
    }
}

void solve (vector<Plane> &planes, vector<int> times) {

    for (int time : times) {

        findPlanes(planes, time);
        for (Plane & plane : planes) {
            if (plane.delay < time && !plane.runway) plane.delay = time;
        }
    }

}

bool notIn(vector<int> times, int time) {
    for (int i : times) if (i == time) return false;
    return true;
}

int main () {

    int cases, nLevantar, nAterrar, time;
    vector<Plane> planes = {};
    vector<int> times = {};
    string currentName;

    cin >> cases;
    for (int i = 0 ; i < cases ; i++) {

        cin >> nLevantar >> nAterrar;
        for (int j = 0 ; j < nLevantar ; j++) {
            cin >> currentName >> time;
            Plane p = Plane(currentName, time, 'L');
            if (notIn(times, time)) times.push_back(time);
            planes.push_back(p);
        }

        for (int k = 0 ; k < nAterrar ; k++) {
            cin >> currentName >> time;
            Plane p = Plane(currentName, time, 'A');
            if (notIn(times, time)) times.push_back(time);
            planes.push_back(p);
        }

        cout << nLevantar <<  " " << nAterrar << endl;
        sort(times.begin(), times.end());
        solve(planes, times);

        for (Plane plane : planes) {
            cout << plane;
        }

        planes.clear();
    }

    return 0;
}

void solve (int a, int b, int c) {
    cout << "Test: " << a << " " << b << " " << c << endl;
}

int main () {

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    solve (n1, n2, n3);
    return 0;
}

class Rectangle {

private:
    int x0;
    int y0;
    int x1;
    int y1;

public:

    Rectangle(int x0, int y0, int x1, int y1) {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }

    int area() {
        return abs(x1-x0) * abs(y1-y0);
    }

    int perimeter() {
        return 2 * (abs(x1-x0) + abs(y1-y0));
    }

    void rotate90() {
        this->x1 = -abs(x1-x0);
        this->y1 = abs(y1-y0);
    }

    int compareTo(Rectangle r) {
        if (this->x0 < r.x0 && this->x1 < r.x1) return 0;
        else if (this->y1 < r.y1 && this->y0 < r.y0) return -1;
        return 1;
    }
};

// Complexity: O(log(n)) --> Binary search
public int binarySearch(int[] values, int val, int left = 0, int right = sizeof(values)/sizeof(values[0])) {

    if (left == right) return left;
    else {
        int middle = (left + (right - left)) / 2;
        if (values[middle] == val) return middle;
        else if (values[middle] < val) return binarySearch(values, val, middle, right);
        return binarySearch(values, val, left, middle);
    }
}

// Complexidade O(n*n) --> menos eficiente que QuickSort, IntroSort, MergeSort, que são todos O(n*log(n))
void minSelectionSort (int[] values) {

    int size = sizeof(values) / sizeof(values[0]);
    for (int i = 1 ; i < size ; i++ ) {
        int temp = values[i], j;
        for (j = i ; j > 0 && temp < values[j-1] ; j-- ) {
            numbers[j] = numbers[j-1];
        }
        numbers[j] = temp;
    }
}

int main () {
    return 0;
}

class Matrix {

    int rows;
    int columns;
    vector<vector<int>> matrix;

public:

    Matrix(int rows, int columns, int valueK) {
        this->rows = rows;
        this->columns = columns;
        this->matrix = vector<vector<int>(rows, k)>(columns);
    }

};

class C1 {

    int value;

public:
    C1(int value);
};

int main () {
    C1 c;
    return 0;
}

/**
 * Neste exemplo considera-se:
 * Fruta -> a bagagem do passageiro
 * Cesta -> o voo que o passageiro apanha
 * Armário -> o avião que possui o voo
 */

class Fruta {
public:
    string name;
    Fruta();
    Fruta(string name) {this->name = name;}
    void setName(string name) { this->name = name;}
};

class Cesta {
public:
    vector<Fruta*>* frutas;
    Cesta();
    Cesta(vector<Fruta*> frutas) { this->frutas = frutas;}
    vector<Fruta*> getFruta() { return *frutas ;}
    void pushFruta(Fruta &fruta) { frutas.push_back(&fruta); }
};

class Armario {
public:
    vector<Cesta*>* cestas;
    Armario();
    Armario(vector<Cesta*> cestas) { this->cestas = cestas;}
    vector<Cesta*> getCestas() { return *cestas; }

};

int main() {

    vector<Fruta*> frutas1 = {};
    Fruta f11 = Fruta("Maca"); frutas1.push_back(&f11);
    Fruta f21 = Fruta("Banana"); frutas1.push_back(&f21);
    Fruta f31 = Fruta("Pera"); frutas1.push_back(&f31);

    vector<Fruta*> frutas2 = {};
    Fruta f12 = Fruta("Maca"); frutas2.push_back(&f12);
    Fruta f22 = Fruta("Banana"); frutas2.push_back(&f22);
    Fruta f32 = Fruta("Pera"); frutas2.push_back(&f32);

    vector<Fruta*> frutas3 = {};
    Fruta f13 = Fruta("Maca"); frutas3.push_back(&f13);
    Fruta f23 = Fruta("Banana"); frutas3.push_back(&f23);
    Fruta f33 = Fruta("Pera"); frutas3.push_back(&f33);

    vector<Cesta*> cestas = {};
    Cesta cesta1 = Cesta(frutas1); cestas.push_back(&cesta1);
    Cesta cesta2 = Cesta(frutas2); cestas.push_back(&cesta2);
    Cesta cesta3 = Cesta(frutas3); cestas.push_back(&cesta3);
    Armario armario = Armario(cestas);

    cout << "O armário inicialmente:" << endl;
    for (Cesta *cesta : armario.getCestas()) {
        cout << "Cesta:" << endl;
        for (Fruta *fruta : cesta->getFruta())  {
            cout << fruta->name << endl;
        }
        cout << endl;
    }

    /**
     * Na segunda cesta do armário, a segunda fruta era "Banana"
     * Vai ser mudada para "Morango" e espera-se que o armário perceba a diferença :)
     * Parecido com o processo de atualização da carga/lotação atual do voo.
     */
    armario.getCestas()[1]->getFruta()[1]->setName("Morango");

    cout << "No segundo cesto Banana -> Morango:" << endl;
    for (Cesta *cesta : armario->getCestas()) {
        cout << "Cesta:" << endl;
        for (Fruta *fruta : cesta->getFruta())  {
            cout << fruta->name << endl;
        }
        cout << endl;
    }

    /**
     * Agora uma fruta (Ananás) é adicionada ao último cesto do armário.
     * Parecido com a bagagem a ser adicionada no voo.
     * Espera-se que o armário também reaja à diferença.
     */
    Fruta ananas("Ananas");
    armario.getCestas()[2]->pushFruta(ananas);

    cout << "Foi adicionada uma fruta no último cesto" << endl;
    for (Cesta *cesta : armario->getCestas()) {
        cout << "Cesta:" << endl;
        for (Fruta *fruta : cesta->getFruta())  {
            cout << fruta->name << endl;
        }
        cout << endl;
    }

    return 0;
}

template <class Comparable> class BSTItrIn;
template <class Comparable> class BSTItrPre;
template <class Comparable> class BSTItrPost;
template <class Comparable> class BSTItrLevel;
template <class Comparable> class iteratorBST;
template <class Comparable> class BST;

template <class Comparable>
class BinaryNode {
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt): element(theElement), left(lt), right(rt) { }
    friend class BST<Comparable>;
    friend class BSTItrIn<Comparable>;
    friend class BSTItrPre<Comparable>;
    friend class BSTItrPost<Comparable>;
    friend class BSTItrLevel<Comparable>;
    friend class iteratorBST<Comparable>;
};

template <class Comparable>
class BST {
    BinaryNode<Comparable> *root;
    const Comparable ITEM_NOT_FOUND;

    const Comparable& elementAt(BinaryNode<Comparable>* t) const;
    bool insert(const Comparable& x, BinaryNode<Comparable>* & t) const;
    bool remove(const Comparable& x, BinaryNode<Comparable>* & t) const;
    BinaryNode<Comparable>* findMin( BinaryNode<Comparable>* t) const;
    BinaryNode<Comparable>* findMax( BinaryNode<Comparable>* t) const;
    BinaryNode<Comparable>* find(const Comparable& x, BinaryNode<Comparable>* t) const;
    void makeEmpty(BinaryNode<Comparable>* & t) const;
    void printTree(BinaryNode<Comparable>* t) const;
    BinaryNode<Comparable>* clone(BinaryNode<Comparable>* t) const;
    friend class BSTItrIn<Comparable>;
    friend class BSTItrPre<Comparable>;
    friend class BSTItrPost<Comparable>;
    friend class BSTItrLevel<Comparable>;
    friend class iteratorBST<Comparable>;
public:
    explicit BST(const Comparable& notFound);
    BST(const BST& rhs);
    ~BST( );
    const Comparable& findMin( ) const;
    const Comparable& findMax( ) const;
    const Comparable& find(const Comparable& x) const;
    bool isEmpty( ) const;
    void printTree( ) const;
    void makeEmpty( );
    bool insert(const Comparable& x);
    bool remove(const Comparable& x);
    const BST& operator= (const BST& rhs);
    iteratorBST<Comparable> begin() const;
    iteratorBST<Comparable> end() const;
    int size(const Comparable& el) const;   //new
};

// Note that all "matching" is based on the < method.

template <class Comparable>
BST<Comparable>::BST(const Comparable& notFound): root(NULL), ITEM_NOT_FOUND(notFound)
{ }

template <class Comparable>
BST<Comparable>::BST(const BST<Comparable>& rhs): root(NULL), ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND) {
    *this = rhs;
}

template <class Comparable>
BST<Comparable>::~BST( ) {
    makeEmpty( );
}

template <class Comparable>
bool BST<Comparable>::insert(const Comparable& x) {
    return insert(x, root);
}

template <class Comparable>
bool BST<Comparable>::remove(const Comparable& x) {
    return remove(x, root);
}

template <class Comparable>
const Comparable& BST<Comparable>::findMin( ) const {
    return elementAt(findMin(root));
}

template <class Comparable>
const Comparable& BST<Comparable>::findMax( ) const {
    return elementAt(findMax(root));
}

template <class Comparable>
const Comparable& BST<Comparable>::find(const Comparable& x) const {
    return elementAt(find(x, root));
}

template <class Comparable>
void BST<Comparable>::makeEmpty( ) {
    makeEmpty(root);
}

template <class Comparable>
bool BST<Comparable>::isEmpty( ) const {
    return root == NULL;
}


template <class Comparable>
void BST<Comparable>::printTree( ) const {
    if(isEmpty())
        cout << "Empty tree" << endl;
    else
        printTree(root);
}

template <class Comparable>
const BST<Comparable>& BST<Comparable>::operator= (const BST<Comparable>& rhs) {
    if(this != &rhs) {
        makeEmpty( );
        root = clone(rhs.root);
    }
    return *this;
}

template <class Comparable>
iteratorBST<Comparable> BST<Comparable>::begin() const {
    iteratorBST<Comparable> it;
    it.setBST(root);
    return it;
}

template <class Comparable>
iteratorBST<Comparable> BST<Comparable>::end() const {
    iteratorBST<Comparable> it;
    it.setBST(NULL);
    return it;
}


// private methods

template <class Comparable>
const Comparable& BST<Comparable>::elementAt(BinaryNode<Comparable>* t) const {
    if(t == NULL)
        return ITEM_NOT_FOUND;
    else
        return t->element;
}

template <class Comparable>
bool BST<Comparable>::insert(const Comparable& x, BinaryNode<Comparable>* & t) const {
    if (t == NULL) {
        t = new BinaryNode<Comparable>(x, NULL, NULL);
        return true;
    }
    else if( x < t->element )
        return insert( x, t->left );
    else if( t->element < x )
        return insert( x, t->right );
    else
        return false;  // Duplicate; do nothing
}

template <class Comparable>
bool BST<Comparable>::remove(const Comparable& x, BinaryNode<Comparable>* & t) const {
    if(t == NULL)
        return false;   // Item not found; do nothing
    if(x < t->element)
        return remove(x, t->left);
    else if(t->element < x)
        return remove(x, t->right);
    else if(t->left != NULL && t->right != NULL) {     // Two children
        t->element = findMin(t->right)->element;
        return remove(t->element, t->right);
    }
    else {
        BinaryNode<Comparable>* oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
        return true;
    }
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMin(BinaryNode<Comparable>* t) const {
    if(t == NULL)
        return NULL;
    if(t->left == NULL)
        return t;
    return findMin(t->left);
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMax(BinaryNode<Comparable>* t) const {
    if(t != NULL)
        while(t->right != NULL)
            t = t->right;
    return t;
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::find(const Comparable& x, BinaryNode<Comparable>* t) const
{
    if(t == NULL)
        return NULL;
    else if(x < t->element)
        return find(x, t->left);
    else if(t->element < x)
        return find(x, t->right);
    else
        return t;    // Match
}

template <class Comparable>
void BST<Comparable>::makeEmpty(BinaryNode<Comparable>* & t) const {
    if(t != NULL) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = NULL;
}

template <class Comparable>
void BST<Comparable>::printTree(BinaryNode<Comparable>* t) const {
    if(t != NULL) {
        printTree(t->left);
        cout << t->element << endl;
        printTree(t->right);
    }
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::clone( BinaryNode<Comparable>* t ) const {
    if(t == NULL)
        return NULL;
    else
        return new BinaryNode<Comparable>(t->element, clone(t->left), clone(t->right));
}


//----------- iterators ---------

// Postorder iterator
template <class Comparable>
class BSTItrPost {
    stack<BinaryNode<Comparable> *> itrStack;
    stack<bool> visitStack;
    void slideDown(BinaryNode<Comparable>* n);
public:
    BSTItrPost(const BST<Comparable> &bt);
    void advance();
    const Comparable& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class Comparable>
BSTItrPost<Comparable>::BSTItrPost (const BST<Comparable>& bt) {
    if (!bt.isEmpty())
        slideDown(bt.root);
}

template <class Comparable>
void BSTItrPost<Comparable>::advance () {
    itrStack.pop();
    visitStack.pop();
    if ((!itrStack.empty()) && (visitStack.top() == false)) {
        visitStack.pop();
        visitStack.push(true);
        slideDown(itrStack.top()->right);
    }
}

template <class Comparable>
void BSTItrPost<Comparable>::slideDown(BinaryNode<Comparable>* n) {
    while (n) {
        itrStack.push(n);
        if (n->left) {
            visitStack.push(false);
            n = n->left;
        } else if (n->right) {
            visitStack.push(true);
            n = n->right;
        } else {
            visitStack.push(true);
            break;
        }
    }
}


// Preorder iterator
template <class Comparable>
class BSTItrPre {
    stack<BinaryNode<Comparable> *> itrStack;
public:
    BSTItrPre(const BST<Comparable>& bt);
    void advance();
    const Comparable& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class Comparable>
BSTItrPre<Comparable>::BSTItrPre (const BST<Comparable>& bt)
{
    if (!bt.isEmpty())
        itrStack.push(bt.root);
}

template <class Comparable>
void BSTItrPre<Comparable>::advance()
{
    BinaryNode<Comparable>* actual = itrStack.top();
    BinaryNode<Comparable>* next = actual->left;
    if (next)
        itrStack.push(next);
    else {
        while (!itrStack.empty()) {
            actual = itrStack.top();
            itrStack.pop();
            next = actual -> right;
            if (next) {
                itrStack.push(next);
                break;
            }
        }
    }
}


//Inorder iterator
template <class Comparable>
class BSTItrIn {
    stack<BinaryNode<Comparable> *> itrStack;
    void slideLeft(BinaryNode<Comparable> *n);
public:
    BSTItrIn(const BST<Comparable>& bt);
    void advance();
    const Comparable& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class Comparable>
BSTItrIn<Comparable>::BSTItrIn (const BST<Comparable>& bt) {
    if (!bt.isEmpty())
        slideLeft(bt.root);
}

template <class Comparable>
void BSTItrIn<Comparable>::slideLeft(BinaryNode<Comparable>* n) {
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template <class Comparable>
void BSTItrIn<Comparable>::advance() {
    BinaryNode<Comparable> * actual = itrStack.top();
    itrStack.pop();
    BinaryNode<Comparable> * next = actual->right;
    if (next)
        slideLeft(next);
}


//Bylevel iterator
template <class Comparable>
class BSTItrLevel {
    queue<BinaryNode<Comparable> *> itrQueue;
public:
    BSTItrLevel(const BST<Comparable> &bt);
    void advance();
    const Comparable& retrieve() const { return itrQueue.front()->element; }
    bool isAtEnd() const { return itrQueue.empty(); }
};

template <class Comparable>
BSTItrLevel<Comparable>::BSTItrLevel (const BST<Comparable>& bt) {
    if (!bt.isEmpty())
        itrQueue.push(bt.root);
}

template <class Comparable>
void BSTItrLevel<Comparable>::advance() {
    BinaryNode<Comparable>* actual = itrQueue.front();
    itrQueue.pop();
    BinaryNode<Comparable>* next = actual->left;
    if (next)
        itrQueue.push(next);
    next = actual->right;
    if (next)
        itrQueue.push(next);
}


// another inorder iterator
template <class Comparable>
class iteratorBST {
    stack<BinaryNode<Comparable> *> itrStack;
    void slideLeft(BinaryNode<Comparable>* n);
    void setBST(BinaryNode<Comparable>* root);
    friend class BST<Comparable>;
public:
    iteratorBST<Comparable>& operator ++(int);
    Comparable operator*() const;
    bool operator==(const iteratorBST<Comparable>& it2) const;
    bool operator!=(const iteratorBST<Comparable>& it2) const;
};

template <class Comparable>
void iteratorBST<Comparable>::slideLeft(BinaryNode<Comparable>* n) {
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template <class Comparable>
void iteratorBST<Comparable>::setBST(BinaryNode<Comparable>* root) {
    if (root!=NULL)
        slideLeft(root);
}

template <class Comparable>
iteratorBST<Comparable>& iteratorBST<Comparable>::operator++ (int) {
    BinaryNode<Comparable>* actual = itrStack.top();
    itrStack.pop();
    BinaryNode<Comparable>* next = actual->right;
    if (next)
        slideLeft(next);
    return *this;
}

template <class Comparable>
Comparable iteratorBST<Comparable>::operator*() const {
    return itrStack.top()->element;
}

template <class Comparable>
bool iteratorBST<Comparable>::operator== (const iteratorBST<Comparable>& it2) const {
    return itrStack == it2.itrStack;
}

template <class Comparable>
bool iteratorBST<Comparable>::operator!= (const iteratorBST<Comparable>& it2) const {
    return itrStack != it2.itrStack;
}

template <class Comparable>
int BST<Comparable>::size(const Comparable& el) const {

    BinaryNode<Comparable> *solution = this->find(el, this->root);
    if (solution == Comparable(-1)) return -1;
    else {
        int result = 0;
        if (solution->left == NULL || solution->right == NULL) {
            if (solution->left != NULL) result += size(solution->left->element);
            if (solution->right != NULL) result += size(solution->right->element);
        }
        return result;
    }
}

template <class T> class BTItrIn;
template <class T> class BTItrPre;
template <class T> class BTItrPost;
template <class T> class BTItrLevel;
template <class T> class BinaryTree;
class Underflow { };

template <class T>
class BTNode {
    T element;
    BTNode<T>* left, * right;
    friend class BinaryTree<T>;
    friend class BTItrIn<T>;
    friend class BTItrPre<T>;
    friend class BTItrPost<T>;
    friend class BTItrLevel<T>;
public:
    BTNode(const T& el, BTNode<T>* l = 0, BTNode<T>* r = 0): element(el), left(l), right(r) { }
};

template <class T>
class BinaryTree {
    BTNode<T> *root;
    void makeEmpty (BTNode<T> *n);
    BTNode<T>* copySubtree(const BTNode<T>* n) const;
    void outputPreorder(ostream& out, const BTNode<T>* n) const;
    friend class BTItrIn<T>;
    friend class BTItrPre<T>;
    friend class BTItrPost<T>;
    friend class BTItrLevel<T>;
public:
    BinaryTree() { root = 0; }
    BinaryTree(const BinaryTree<T>& t);
    BinaryTree(const T& el);
    BinaryTree(const T& el, const BinaryTree<T>& l, const BinaryTree<T>& r);
    ~BinaryTree() { makeEmpty(); }
    const BinaryTree<T>& operator= (const BinaryTree<T>& rhs);
    bool isEmpty () const;
    T& getRoot () const;
    void makeEmpty();
    void outputPreorder(ostream &out) const;
};


template <class T>
BinaryTree<T>::BinaryTree(const T& el) {
    root = new BTNode<T>(el);
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& t) {
    root = copySubtree(t.root);
}

template <class T>
BTNode<T>* BinaryTree<T>::copySubtree(const BTNode<T>* n) const {
    if (n) {
        BTNode<T>* node = new BTNode<T>(n->element, copySubtree(n->left), copySubtree(n->right));
        return node;
    }
    return 0;
}

template <class T>
BinaryTree<T>::BinaryTree(const T& el, const BinaryTree<T>& l, const BinaryTree<T>& r) {
    root = new BTNode<T>(el, copySubtree(l.root), copySubtree(r.root));
}

template <class T>
const BinaryTree<T>& BinaryTree<T>::operator= (const BinaryTree<T>& rhs) {
    if (this != & rhs) {
        makeEmpty();
        root = copySubtree(rhs.root);
    }
    return *this;
}

template <class T>
bool BinaryTree<T>::isEmpty() const {
    return (root == 0) ? true : false;
}

template <class T>
T& BinaryTree<T>::getRoot () const {
    if (root)
        return root->element;
    throw Underflow();
}

template <class T>
void BinaryTree<T>::makeEmpty() {
    makeEmpty(root);
}


template <class T>
void BinaryTree<T>::makeEmpty(BTNode<T>* n) {
    if (n) {
        makeEmpty(n->left);
        makeEmpty(n->right);
        delete n;
    }
}

template <class T>
void BinaryTree<T>::outputPreorder(ostream& out) const {
    outputPreorder(out, root);
}

template <class T>
void BinaryTree<T>::outputPreorder(ostream& out, const BTNode<T>* n) const {
    out << '(';
    if (n) {
        out <<  n->element << ' ';
        outputPreorder(out, n->left);
        out << ' ';
        outputPreorder(out, n->right);
    }
    out << ')';
}

template <class T>
ostream& operator<<(ostream& out, const BinaryTree<T>& t) {
    t.outputPreorder(out);
    return out;
}


// ---------- Iterators  ------------

// Postorder iterator
template <class T>
class BTItrPost {
    stack<BTNode<T> *> itrStack;
    stack<bool> visitStack;
    void slideDown(BTNode<T>* n);
public:
    BTItrPost(const BinaryTree<T>& t);
    void advance();
    T& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class T>
BTItrPost<T>::BTItrPost (const BinaryTree<T>& t) {
    if (!t.isEmpty())
        slideDown(t.root);
}

template <class T>
void BTItrPost<T>::advance () {
    itrStack.pop();
    visitStack.pop();
    if (!itrStack.empty() && (visitStack.top() == false)) {
        visitStack.pop();
        visitStack.push(true);
        slideDown(itrStack.top()->right);
    }
}

template <class T>
void BTItrPost<T>::slideDown(BTNode<T>* n) {
    while (n) {
        itrStack.push(n);
        if (n->left) {
            visitStack.push(false);
            n = n->left;
        }
        else if (n->right) {
            visitStack.push(true);
            n = n->right;
        }
        else {
            visitStack.push(true);
            break;
        }
    }
}


// Preorder iterator
template <class T>
class BTItrPre {
    stack<BTNode<T> *> itrStack;
public:
    BTItrPre(const BinaryTree<T>& t);
    void advance();
    T& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class T>
BTItrPre<T>::BTItrPre (const BinaryTree<T>& t) {
    if (!t.isEmpty())
        itrStack.push(t.root);
}

template <class T>
void BTItrPre<T>::advance() {
    BTNode<T>* actual = itrStack.top();
    BTNode<T>* next = actual->left;
    if (next)
        itrStack.push(next);
    else {
        while (!itrStack.empty()) {
            actual = itrStack.top();
            itrStack.pop();
            next = actual -> right;
            if (next) {
                itrStack.push(next);
                break;
            }
        }
    }
}


// Inorder iterator
template <class T>
class BTItrIn {
    stack<BTNode<T> *> itrStack;
    void slideLeft(BTNode<T>* n);
public:
    BTItrIn(const BinaryTree<T>& t);
    void advance();
    T& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class T>
BTItrIn<T>::BTItrIn (const BinaryTree<T>& t) {
    if (!t.isEmpty())
        slideLeft(t.root);
}

template <class T>
void BTItrIn<T>::slideLeft(BTNode<T>* n) {
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template <class T>
void BTItrIn<T>::advance() {
    BTNode<T>* actual = itrStack.top();
    itrStack.pop();
    BTNode<T>* next = actual->right;
    if (next)
        slideLeft(next);
}


// Bylevel iterator
template <class T>
class BTItrLevel {
    queue<BTNode<T> *> itrQueue;
public:
    BTItrLevel(const BinaryTree<T>& t);
    void advance();
    T& retrieve() const { return itrQueue.front()->element; }
    bool isAtEnd() const { return itrQueue.empty(); }
};

template <class T>
BTItrLevel<T>::BTItrLevel (const BinaryTree<T>& t) {
    if (!t.isEmpty())
        itrQueue.push(t.root);
}

template <class T>
void BTItrLevel<T>::advance() {
    BTNode<T>* actual = itrQueue.front();
    itrQueue.pop();
    BTNode<T>* next = actual->left;
    if (next)
        itrQueue.push(next);
    next = actual->right;
    if (next)
        itrQueue.push(next);
}

class WordMean {
    string word;
    string meaning;
public:
    WordMean(string w, string m);
    string getWord() const;
    string getMeaning() const;
    void setMeaning(string m);
    void setWord(string w);
    bool operator<(const WordMean &w) const;
    bool operator==(const WordMean &w) const;
};

class Dictionary
{
    BST<WordMean> words;
public:
    Dictionary(): words(WordMean("","")) {};
    BST<WordMean> getWords() const;
    void readFile(ifstream& f);
    string consult(string word1, WordMean& previous, WordMean& next) const;
    bool update(string word1, string mean1);
    void print() const;
};

class Circle {
    int points;
    bool state;
    int nVisits;
public:
    Circle(int p=0, bool s=false);
    int getPoints() const;
    bool getState() const;
    void changeState();
    int getNVisits() const;
    void incNVisits();
};

class Game {
    BinaryTree<Circle> game;
public:
    BinaryTree<Circle>& getGame();
    Game(int height, vector<int>& points, vector<bool>& states);
    int play();
    int mostVisited() const;
};

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

BST<WordMean> Dictionary::getWords() const {
    return words;
}

bool WordMean::operator < (const WordMean &w) const {
    return this->getWord() < w.getWord();
}

bool WordMean::operator == (const WordMean &a) const {
    return this->getWord() == a.getWord();
}

void Dictionary::readFile(ifstream &f) {

    WordMean notFound = WordMean("", "");
    string currentWord, currentMeaning;

    while (!f.eof()) {
        getline(f, currentWord);
        getline(f, currentMeaning);
        WordMean current = WordMean(currentWord, currentMeaning);
        WordMean found = words.find(current);
        if (found == notFound) words.insert(current);
    }
}

string Dictionary::consult(string word1, WordMean& previous, WordMean& next) const {

    WordMean toSearch = WordMean(word1, "");
    WordMean notFound = WordMean("", "");
    WordMean found = words.find(toSearch);
    if (found == notFound) {

        BSTItrIn<WordMean> itr(words);

        while (previous.getWord() > word1 || next.getWord() < word1) {
            previous = next;
            itr.advance();
            next = itr.retrieve();
        }

        return "word not found";

    } else {
        return found.getMeaning();
    }
}

bool Dictionary::update(string word1, string mean1) {

    WordMean found = words.find(WordMean(word1, ""));

    if (found == WordMean("", "")) {
        words.insert(WordMean(word1, mean1));
    } else {
        words.remove(found);
        words.insert(WordMean(word1, mean1));
    }
    return !(found == WordMean("", ""));
}

void Dictionary::print() const {

    BSTItrIn<WordMean> itr(words);
    while (!itr.isAtEnd()) {
        cout << itr.retrieve().getWord() << endl;
        cout << itr.retrieve().getMeaning() << endl;
        itr.advance();
    }
}

Circle::Circle(int p, bool s): points(p), state(s), nVisits(0) {}

int Circle::getPoints() const {
    return points;
}

bool Circle::getState() const {
    return state;
}

void Circle::changeState() {
    if (state == false)
        state = true;
    else
        state = false;
}

int Circle::getNVisits() const {
    return nVisits;
}

void Circle::incNVisits() {
    nVisits++;
}


BinaryTree<Circle>& Game::getGame() {
    return game;
}

// Aided by Pedro Barbeira
Game::Game(int height, vector<int>& points, vector<bool>& states) {

    vector<BinaryTree<Circle>*> leaves(points.size(), nullptr);
    for(int i = points.size()-1; i >= 0; i--){
        if(i*2+1 > points.size()-1){
            leaves[i] = new BinaryTree<Circle>(Circle(points[i], states[i]));
        }
        else{
            leaves[i] = new BinaryTree<Circle>(Circle(points[i], states[i]), (*leaves[2*i+1]), (*leaves[2*i+2]));
        }
    }
    game = (*leaves[0]);
    for(auto it: leaves)
        delete it;
}

// Aided by Pedro Barbeira
int Game::play() {

    BTItrLevel<Circle> it(game);
    Circle c = it.retrieve();
    bool over = false;
    while(!it.isAtEnd()){
        Circle& current = it.retrieve();
        c.incNVisits();
        if(c.getState()){
            for(int p = c.getPoints(); p >= 0; p--) {
                it.advance();
                if (it.isAtEnd()) {
                    over = true;
                    break;
                }
            }
        }
        else{
            for(int p = c.getPoints(); p > 0; p--){
                it.advance();
                if (it.isAtEnd()) {
                    over = true;
                    break;
                }
            }
        }
        if(over) break;
        else {
            c.changeState();
            current = c;
            c = it.retrieve();
        }
    }
    return c.getPoints();
}

int Game::mostVisited() const {

    BTItrLevel<Circle> it(game);
    it.advance();
    int max = 0;
    while(!it.isAtEnd()){
        Circle c = it.retrieve();
        if(c.getNVisits() > max) max = c.getNVisits();
        it.advance();
    }
    return max;
}

template <class Comparable>
int BST<Comparable>::maxDepth(BinaryNode<Comparable>* node) const {

    if (node == NULL) return -1;
    else {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }
}

template <class Comparable>
int BST<Comparable>::balance(const Comparable& x) const {

    BinaryNode<Comparable> *find = this->find(x, this->root);
    if (find == NULL) return 0;
    else {
        int answerLeft = maxDepth(find->left);
        int answerRight = maxDepth(find->right);
        return answerRight - answerLeft;
    }
}

template <class Comparable>
bool BST<Comparable>::isAVLTree(BinaryNode<Comparable>* node) const {

    if (node == NULL) return true;
    int leftDepth = BST<Comparable>::maxDepth(node->left);
    int rightDepth = BST<Comparable>::maxDepth(node->right);
    return abs(leftDepth - rightDepth) < 2 && isAVLTree(node->left) && isAVLTree(node->right);
}

template <class Comparable>
bool BST<Comparable>::isAVL() const {
    return isAVLTree(this->root);
}

template <class Comparable>
void BST<Comparable>::rightRotate(const Comparable& x) {

    BinaryNode<Comparable> *find = this->find(x, this->root);
    if (find == NULL || find->left == NULL) return;

    // De acordo com o exemplo/esquema dado:
    BinaryNode<Comparable> *Y = find->left;
    BinaryNode<Comparable> *T2 = Y->right;
    find->left = T2;
    Y->right = find;
    this->root = Y;
}

int FunWithBSTs::newBag(const vector<int>& collection, const vector<int>& bag) {

    set<int> unRepeted;
    for (int cromo : collection) unRepeted.insert(cromo);
    int beforeInsertion = unRepeted.size();

    for (int newCromo : bag) unRepeted.insert(newCromo);

    return unRepeted.size() - beforeInsertion;
}

int FunWithBSTs::battle(const vector<int>& alice, const vector<int>& bruno) {

    multiset<int> mAlice; for (int card : alice) mAlice.insert(card);
    multiset<int> mBruno; for (int card : bruno) mBruno.insert(card);

    multiset<int>::iterator iteratorAlice;
    multiset<int>::iterator iteratorBruno;

    while (!mAlice.empty() && !mBruno.empty()) {

        iteratorAlice = mAlice.end(); iteratorAlice--;
        iteratorBruno = mBruno.end(); iteratorBruno--;

        int maxAlice = *iteratorAlice; mAlice.erase(iteratorAlice);
        int maxBruno = *iteratorBruno; mBruno.erase(iteratorBruno);

        if (maxAlice > maxBruno) {
            maxAlice -= maxBruno;
            mAlice.insert(maxAlice);
        } else if (maxAlice < maxBruno) {
            maxBruno -= maxAlice;
            mBruno.insert(maxBruno);
        } else continue;
    }

    if (!mAlice.empty()) return mAlice.size();
    if (!mBruno.empty()) return -mBruno.size();
    return 0;
}

int FunWithBSTs::numberMovies(const vector<pair<string, int>>& reviews) {

    set<string> movies = {};
    for (pair<string, int> review : reviews) movies.insert(review.first);
    return movies.size();
}

void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {

    map<string, int> totalReview = {};
    m = 0;
    for (pair<string, int> review : reviews) {
        if (totalReview.find(review.first) != totalReview.end()) totalReview[review.first] += 1;
        else totalReview[review.first] = 1;

        m = totalReview[review.first] > m ? totalReview[review.first] : m;
    }

    n = 0;
    for (map<string, int>::iterator it = totalReview.begin(); it != totalReview.end(); it++) {
        if (it->second == m) n++;
    }
}

vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {

    vector<string> answer = {};
    map<string, int> totalPoints = {};
    map<string, int> occurrence = {};

    for (const pair<string, int> &review : reviews) {

        if (totalPoints.find(review.first) != totalPoints.end()) totalPoints[review.first] += review.second;
        else totalPoints[review.first] = review.second;

        if (occurrence.find(review.first) != occurrence.end()) occurrence[review.first]++;
        else occurrence[review.first] = 1;
    }

    set<string> nonRepeted = {};
    for (const pair<string, int> &review : reviews) {
        if ((float) totalPoints[review.first] / occurrence[review.first] >= k) nonRepeted.insert(review.first);
    }

    answer.assign(nonRepeted.begin(), nonRepeted.end());

    sort(answer.begin(), answer.end());
    return answer;
}

template <class KeyType>
bool HashTable<KeyType>::insert(const KeyType& k) {

    if (numEmpty > 1 && !contains(k)) {
        int position = findPos(k);
        HashEntry h = {ACTIVE, k};
        this->table[position] = h;
        numActive++;
        numEmpty--;
        return true;
    }
    return false;
}

template <class KeyType>
bool HashTable<KeyType>::remove(const KeyType& k) {

    if (contains(k)) {

        int position = findPos(k);
        HashEntry h = {DELETED, k};
        this->table[position] = h;
        numActive--;
        return true;

    } return false;
}

template <class KeyType>
bool HashTable<KeyType>::rehash(int n) {

    if (n >= numActive + 1) {

        vector<HashEntry> oldTable = this->table;
        vector<HashEntry> newTable(n);
        this->table = newTable;
        clear();

        for (int i = 0 ; i < oldTable.size() ; i++) {
            if (oldTable[i].state == ACTIVE) this->insert(oldTable[i].key);
        }
        return true;

    } return false;
}

unsigned FunWithHashTables::hashInt(const int& i) {
    return i;
}

unsigned FunWithHashTables::hashString(const string& s) {
    hash<string> h;
    return h(s);
}

int max (const vector<int>& numbers) {

    int max = numbers[0];
    for (int number : numbers) max = number > max ? number : max;
    return max;
}

int FunWithHashTables::sumPairs(const vector<int>& numbers) {

    int hashTableSize = 2 * max(numbers);
    HashTable<int> allSums = HashTable<int>(hashTableSize, hashInt);
    allSums.clear();

    for (int i = 0 ; i < numbers.size() - 1 ; i++) {
        for (int j = i + 1 ; j < numbers.size() ; j++) {
            allSums.insert(numbers[i] + numbers[j]);
        }
    }

    return allSums.getNumActive();
}

int FunWithHashTables::dnaMotifs(string dna, int k, unordered_set<string>& motifs) {

    unordered_map<string, int> allMotifs = {};
    for (int i = 0 ; i < dna.size() - k + 1; i++) {
        string motif = dna.substr(i, k);
        if (allMotifs.find(motif) == allMotifs.end()) allMotifs[motif] = 1;
        else allMotifs[motif]++;
    }

    int maxOccurrence = 0;
    for (unordered_map<string, int>::iterator it = allMotifs.begin() ; it != allMotifs.end() ; it++) {
        maxOccurrence = maxOccurrence > it->second ? maxOccurrence : it->second;
    }

    for (unordered_map<string, int>::iterator it = allMotifs.begin() ; it != allMotifs.end() ; it++) {
        if (it->second == maxOccurrence) motifs.insert(it->first);
    }

    return maxOccurrence;
}

vector<string> toWords(const string &text) {

    vector<string> allWords = {};
    string currentWord = "";
    for (char letter : text) {
        letter = tolower(letter);
        if (letter == ' ' && !currentWord.empty()) {
            allWords.push_back(currentWord);
            currentWord = "";
        } else if (isalpha(letter)) currentWord += letter;
    }
    allWords.push_back(currentWord);

    return allWords;
}

bool in(const string &w, const vector<string> &words) {
    for (const string &word : words) if (word == w) return true;
    return false;
}

void FunWithHashTables::findLanguage(string text, const unordered_map<string, vector<string>>& dict, unordered_map<string, int>& answer) {

    vector<string> allWords = toWords(text);
    unordered_multimap<string, string> occurrence = {};

    for (string word : allWords) {
        for (auto it = dict.begin() ; it != dict.end() ; it++) {
            if (in(word, it->second)) occurrence.insert(make_pair(word, it->first));
        }
    }

    for (auto it = occurrence.begin(); it != occurrence.end(); it++)
        cout << "<" << it->first << ", " << it->second
             << ">  ";

    cout << endl;

    for (auto it = occurrence.begin() ; it != occurrence.end() ; it ++) {
        if (answer.find(it->second) == answer.end()) answer.insert(make_pair(it->second, 1));
        else answer[it->second]++;
    }
}

vector<string> toWords(const string &text) {

    vector<string> allWords = {};
    string currentWord = "";
    for (char letter : text) {
        letter = tolower(letter);
        if ((letter == ' ' || letter == '-' )&& !currentWord.empty()) {
            allWords.push_back(currentWord);
            currentWord = "";
        } else if (isalpha(letter)) currentWord += letter;
    }
    allWords.push_back(currentWord);

    return allWords;
}

bool in(const string &w, const vector<string> &words) {
    for (const string &word : words) if (word == w) return true;
    return false;
}

void FunWithHashTables::findLanguage(string text, const unordered_map<string, vector<string>>& dict, unordered_map<string, int>& answer) {

    vector<string> allWords = toWords(text);
    unordered_multimap<string, string> occurrence = {};

    for (string word : allWords) {
        for (auto it = dict.begin() ; it != dict.end() ; it++) {
            if (in(word, it->second)) occurrence.insert(make_pair(word, it->first));
        }
    }

    for (auto it = dict.begin() ; it != dict.end() ; it ++) {
        if (answer.find(it->first) == answer.end()) answer.insert(make_pair(it->first, 0));
    }

    for (auto it = occurrence.begin() ; it != occurrence.end() ; it ++) {
        answer[it->second]++;
    }
}

void FunWithHashTables::wordIndex(const vector<string> &words, vector<int>& answer) {

    unordered_map<string, int> allWords = {};
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string currentWord;

    int counter = 1;
    currentWord = "";
    for (int i = 0; i < 26; i++) {
        currentWord = alphabet[i];
        allWords.insert(make_pair(currentWord, counter));
        counter++;
    }

    for (int i = 0; i < 25; i++) {
        currentWord = alphabet[i];
        for (int j = i + 1; j < 26; j++) {
            currentWord += alphabet[j];
            allWords.insert(make_pair(currentWord, counter));
            counter++;
            currentWord = alphabet[i];
        }
    }

    for (int i = 0; i < 24; i++) {
        currentWord = alphabet[i];
        for (int j = i + 1; j < 25; j++) {
            currentWord += alphabet[j];
            for (int k = j + 1; k < 26; k++) {
                currentWord += alphabet[k];
                allWords.insert(make_pair(currentWord, counter));
                counter++;
                currentWord = alphabet[i];
                currentWord += alphabet[j];
            }
            currentWord = alphabet[i];
        }
        currentWord = "";
    }

    for (int i = 0; i < 23; i++) {
        currentWord = alphabet[i];
        for (int j = i + 1; j < 24; j++) {
            currentWord += alphabet[j];
            for (int k = j + 1; k < 25; k++) {
                currentWord += alphabet[k];
                for (int w = k + 1; w < 26; w++) {
                    currentWord += alphabet[w];
                    allWords.insert(make_pair(currentWord, counter));
                    counter++;
                    currentWord = alphabet[i];
                    currentWord += alphabet[j];
                    currentWord += alphabet[k];
                }
                currentWord = alphabet[i];
                currentWord += alphabet[j];
            }
            currentWord = alphabet[i];
        }
        currentWord = "";
    }

    for (int i = 0; i < 22; i++) {
        currentWord = alphabet[i];
        for (int j = i + 1; j < 23; j++) {
            currentWord += alphabet[j];
            for (int k = j + 1; k < 24; k++) {
                currentWord += alphabet[k];
                for (int w = k + 1; w < 25; w++) {
                    currentWord += alphabet[w];
                    for (int z = w + 1; z < 26; z++) {
                        currentWord += alphabet[z];
                        allWords.insert(make_pair(currentWord, counter));
                        counter++;
                        currentWord = alphabet[i];
                        currentWord += alphabet[j];
                        currentWord += alphabet[k];
                        currentWord += alphabet[w];
                    }
                    currentWord = alphabet[i];
                    currentWord += alphabet[j];
                    currentWord += alphabet[k];
                }
                currentWord = alphabet[i];
                currentWord += alphabet[j];
            }
            currentWord = alphabet[i];
        }
        currentWord = "";
    }

    for (string word: words) {
        answer.push_back(allWords[word]);
    }
}

bool isValid1 (string text) {

    bool answer = true;
    for (char letter : text) {
        answer = answer && (letter == '0' || letter == '1');
    }
    return answer;
}

bool isValid2 (string text) {

    if (text.size() == 1) return (text == 1 || text == 0);
    else {
        return (text[0] == 1 || text[0] == 0) && isValid2(text.substr(1, text.size()-1));
    }
}

class Graph {

private:
    /**
     * Uma struct que implementa uma aresta entre dois nós.
     * Destino, se for um grafo direcional. Por predefinição, implementa-se uma bidirecional A -> B e B -> A
     * Peso, se for um grafo pesado. Por predefinição, implementa-se weight = 1
     */
    struct Edge {
        int destination;
        int weight;
    };

    /**
     * Um nó é representado por uma lista de arestas adjacentes, que podem ou não ter
     * direção ou peso
     */
    struct Node {
        list<Edge> adjacents;
    };

    /**
     * Tamanho do grafo
     */
    int size;

    /**
     * Se ele tem direção
     */
    bool hasDirection;

    /**
     * Um grafo é constituido por um vector de nós
     */
    vector<Node> nodes;

public:

    /**
     * Construtor de um grafo com base no tamanho dos nós a albergar. Por predefinição, é um grafo não direcional
     */
    Graph(int nodes, bool dir = false);

    /**
     * Adiciona uma ligação entre a source e o destino, com ou sem peso associado
     */
    void addEdge (int source, int destination, int weight = 1);
};

Graph::Graph(int nodes, bool dir) : nodes(nodes+1) {
    this->size = nodes;
    this->hasDirection= dir;
}

void Graph::addEdge(int source, int destination, int weight) {
    if (source < 1 || source > size || destination < 1 || destination > size) return;
    Edge newEdge;
    newEdge.destination = destination;
    newEdge.weight = weight;
    nodes[source].adjacents.push_back(newEdge);
    if (!hasDirection) {
        newEdge.destination = destination;
        newEdge.weight = weight;
        nodes[destination].adjacents.push_back(newEdge);
    }
}

int main () {

    Graph graph(9, false);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(4, 6);
    graph.addEdge(4, 7);
    graph.addEdge(5, 8);
    graph.addEdge(7, 9);
}

#include <stdio.h>
int i;
int main(_,x,m,a,s) char *s; {
m=i?m:1;
x=i=i?(x?x:21):
    21;a=21-x?0:1;_=i?_:1;
_+=a;putchar(21-x?(12-_?(11-_?(
10-_?(12-x>_?' ':(x-9>_?' ':(m?'/':'\\')
)):(x<10||x>11)?' ':'|'):20+*(s+20-x)):' '):'\n');
return 13-_?main(_,--x,1-m,a,"9Q^^eDYM_hh\\K^UNQU^["):0;
}

// Created on December, 2021
// @author: Fábio Araújo de Sá

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {

private:
    /**
     * Uma struct que implementa uma aresta entre dois nós.
     * Destino, se for um grafo direcional. Por predefinição, implementa-se uma bidirecional A -> B e B -> A
     * Peso, se for um grafo pesado. Por predefinição, implementa-se weight = 1
     */
    struct Edge {
        int destination;
        int weight;
    };

    /**
     * Um nó é representado por uma lista de arestas adjacentes, que podem ou não ter
     * direção ou peso.
     * Foi acrescentado um novo parâmetro, para a pesquisa DFS (que tem de ter algo que verifique se o nó foi visitado)
     */
    struct Node {
        list<Edge> adjacents;
        bool visited;
    };

    /**
     * Tamanho do grafo
     */
    int size;

    /**
     * Se ele tem direção
     */
    bool hasDirection;

    /**
     * Um grafo é constituido por um vector de nós
     */
    vector<Node> nodes;

public:

    /**
     * Construtor de um grafo com base no tamanho dos nós a albergar. Por predefinição, é um grafo não direcional
     */
    Graph(int nodes, bool dir = false);

    /**
     * Adiciona uma ligação entre a source e o destino, com ou sem peso associado
     */
    void addEdge (int source, int destination, int weight = 1);

    /**
     * Depth First Search - vai percorrer o grafo de forma recursiva: primeiro a parte da direita
     * e só depois a parte da esquerda
     */
    void DFS(int v);

    /**
     * Baseado na pesquisa DFS, retorna o número de componentes conexosdo grafo em questão
     */
    int howManyComponents();
};

Graph::Graph(int nodes, bool dir) : nodes(nodes+1) {
    this->size = nodes;
    this->hasDirection= dir;
}

void Graph::addEdge(int source, int destination, int weight) {
    if (source < 1 || source > size || destination < 1 || destination > size) return;
    Edge newEdge;
    newEdge.destination = destination;
    newEdge.weight = weight;
    nodes[source].adjacents.push_back(newEdge);
    if (!hasDirection) {
        Edge anotherEdge;
        anotherEdge.destination = source;
        anotherEdge.weight = weight;
        nodes[destination].adjacents.push_back(anotherEdge);
    }
}

void Graph::DFS(int v) {

    nodes[v].visited = true;                    // Marcar o nó como visitado
    cout << v << " ";                           // Mostra o nó que visita
    for (Edge edge : nodes[v].adjacents) {      // Para cada aresta a visitar
        int dest = edge.destination;            // Encontra o nó de destino
        if (!nodes[dest].visited) {             // Se esse nó ainda não estiver visitado
            DFS(dest);                          // Visita-o recursivamente
        }
    }
}

int Graph::howManyComponents() {

    int total = 0;

    for (int i = 1 ; i <= size ; i++) {                   // Garantir que nenhum nó foi antes visitado
        nodes[i].visited = false;
    }

    for (int i = 1 ; i <= size ; i++) {                   // Para cada conjunto que não foi visitado, visita o seu início
        if (!nodes[i].visited) {                          // E incrementa o contador
            cout << "Connected components: ";
            total++;
            DFS(i);
            cout << endl;
        }
    }

    cout << "Total: ";
    return total;
}

int main () {

    cout << "\nCreate and fill graphs\n" << endl;

    Graph graphNonDirectional(9, false);
    graphNonDirectional.addEdge(1, 2);
    graphNonDirectional.addEdge(1, 3);
    graphNonDirectional.addEdge(1, 4);
    graphNonDirectional.addEdge(2, 4);
    graphNonDirectional.addEdge(3, 4);
    graphNonDirectional.addEdge(4, 5);
    graphNonDirectional.addEdge(4, 6);
    graphNonDirectional.addEdge(4, 7);
    graphNonDirectional.addEdge(5, 8);
    graphNonDirectional.addEdge(7, 9);

    Graph notConnected(14, false);
    notConnected.addEdge(1, 11);
    notConnected.addEdge(11, 7);
    notConnected.addEdge(11, 12);
    notConnected.addEdge(12, 2);
    notConnected.addEdge(12, 8);
    notConnected.addEdge(3, 13);
    notConnected.addEdge(13, 4);
    notConnected.addEdge(13, 14);
    notConnected.addEdge(14, 9);
    notConnected.addEdge(14, 5);
    notConnected.addEdge(6, 10);

    cout << "DFS Search Sequence: " << endl;
    graphNonDirectional.DFS(1);
    cout << endl << endl;

    cout << "Connected components of graph 1: " << endl;
    cout << graphNonDirectional.howManyComponents() << endl << endl;
    cout << "Connected components of graph 2: " << endl;
    cout << notConnected.howManyComponents() << endl << endl;

    return 0;
}

class Graph {

private:
    /**
     * Uma struct que implementa uma aresta entre dois nós.
     * Destino, se for um grafo direcional. Por predefinição, implementa-se uma bidirecional A -> B e B -> A
     * Peso, se for um grafo pesado. Por predefinição, implementa-se weight = 1
     */
    struct Edge {
        int destination;
        int weight;
    };

    /**
     * Um nó é representado por uma lista de arestas adjacentes, que podem ou não ter
     * direção ou peso.
     * Foi acrescentado um novo parâmetro, para a pesquisa DFS (que tem de ter algo que verifique se o nó foi visitado)
     */
    struct Node {
        list<Edge> adjacents;
        bool visited;
        int distance;
    };

    /**
     * Tamanho do grafo
     */
    int size;

    /**
     * Se ele tem direção
     */
    bool hasDirection;

    /**
     * Um grafo é constituido por um vector de nós
     */
    vector<Node> nodes;

public:

    /**
     * Construtor de um grafo com base no tamanho dos nós a albergar. Por predefinição, é um grafo não direcional
     */
    Graph(int nodes, bool dir = false);

    /**
     * Adiciona uma ligação entre a source e o destino, com ou sem peso associado
     */
    void addEdge (int source, int destination, int weight = 1);

    /**
     * Depth First Search - vai percorrer o grafo de forma recursiva: primeiro a parte da direita
     * e só depois a parte da esquerda
     */
    void DFS(int v);

    /**
     * Baseado na pesquisa DFS, retorna o número de componentes conexos do grafo em questão
     */
    int howManyComponents();

    /**
     * Breath First Search - percorre o grafo com uma fila e por ordem de patamares
     */
    void BFS(int v);

    /**
     * Show distances of all nodes starting at given parameter
     */
    void computingDistances(int v);
};

Graph::Graph(int nodes, bool dir) : nodes(nodes+1) {
    this->size = nodes;
    this->hasDirection= dir;
}

void Graph::addEdge(int source, int destination, int weight) {
    if (source < 1 || source > size || destination < 1 || destination > size) return;
    Edge newEdge;
    newEdge.destination = destination;
    newEdge.weight = weight;
    nodes[source].adjacents.push_back(newEdge);
    if (!hasDirection) {
        Edge anotherEdge;
        anotherEdge.destination = source;
        anotherEdge.weight = weight;
        nodes[destination].adjacents.push_back(anotherEdge);
    }
}

void Graph::DFS(int v) {

    nodes[v].visited = true;                    // Marcar o nó como visitado
    cout << v << " ";                           // Mostra o nó que visita
    for (Edge edge : nodes[v].adjacents) {      // Para cada aresta a visitar
        int dest = edge.destination;            // Encontra o nó de destino
        if (!nodes[dest].visited) {             // Se esse nó ainda não estiver visitado
            DFS(dest);                          // Visita-o recursivamente
        }
    }
}

int Graph::howManyComponents() {

    int total = 0;

    for (int i = 1 ; i <= size ; i++) {                   // Garantir que nenhum nó foi antes visitado
        nodes[i].visited = false;
    }

    for (int i = 1 ; i <= size ; i++) {                   // Para cada conjunto que não foi visitado, visita o seu início
        if (!nodes[i].visited) {                          // E incrementa o contador
            cout << "Connected components: ";
            total++;
            DFS(i);
            cout << endl;
        }
    }

    cout << "Total: ";
    return total;
}

void Graph::BFS(int v) {

    for (int i = 1 ; i <= size ; i++) {                // marcar todos como não visitado
        nodes[i].visited = false;
    }

    queue<int> visitedNodes = {};
    visitedNodes.push(v);                           // primeiro nó visitado;
    nodes[v].visited = true;                        // marcar como visitado

    while (!visitedNodes.empty()) {

        int node = visitedNodes.front();
        visitedNodes.pop();                         // retirar o primeiro elemento da fila
        cout << node << " " ;

        for (Edge e : nodes[node].adjacents) {      // Vai a cada adjacência
            int n = e.destination;                  // Vê qual é o nó
            if (!nodes[n].visited) {                // Se o nó ainda não tiver visitado
                visitedNodes.push(n);               // Acrescenta à fila
                nodes[n].visited = true;            // Marca-o como visitado
            }
        }
    }
}

void Graph::computingDistances(int v) {

    for (int i = 1 ; i <= size ; i++) {
        nodes[i].visited = false;                   // marcar todos como não visitados
        nodes[i].distance = 0;                      // marcar todos como distância nula
    }

    queue<int> visitedNodes = {};
    visitedNodes.push(v);                           // primeiro nó visitado;
    nodes[v].distance = 0;                          // distância à origem = 0 unidades
    nodes[v].visited = true;                        // marcar como visitado

    while (!visitedNodes.empty()) {

        int node = visitedNodes.front();
        visitedNodes.pop();                                     // retirar o primeiro elemento da fila
        cout << node << "->" << nodes[node].distance << " ";

        for (Edge e : nodes[node].adjacents) {                  // Vai a cada adjacência
            int n = e.destination;                              // Vê qual é o nó
            if (!nodes[n].visited) {                            // Se o nó ainda não tiver visitado
                visitedNodes.push(n);                           // Acrescenta à fila
                nodes[n].visited = true;                        // Marca-o como visitado
                nodes[n].distance = nodes[node].distance + 1;   // A sua distância é origem++
            }
        }
    }
}

int main () {

    cout << "\n\n##### DFS #####" << endl;
    cout << "\nCreate and fill graphs\n" << endl;

    Graph graphNonDirectional(9, false);
    graphNonDirectional.addEdge(1, 2);
    graphNonDirectional.addEdge(1, 3);
    graphNonDirectional.addEdge(1, 4);
    graphNonDirectional.addEdge(2, 4);
    graphNonDirectional.addEdge(3, 4);
    graphNonDirectional.addEdge(4, 5);
    graphNonDirectional.addEdge(4, 6);
    graphNonDirectional.addEdge(4, 7);
    graphNonDirectional.addEdge(5, 8);
    graphNonDirectional.addEdge(7, 9);

    Graph notConnected(14, false);
    notConnected.addEdge(1, 11);
    notConnected.addEdge(11, 7);
    notConnected.addEdge(11, 12);
    notConnected.addEdge(12, 2);
    notConnected.addEdge(12, 8);
    notConnected.addEdge(3, 13);
    notConnected.addEdge(13, 4);
    notConnected.addEdge(13, 14);
    notConnected.addEdge(14, 9);
    notConnected.addEdge(14, 5);
    notConnected.addEdge(6, 10);

    cout << "DFS Search Sequence: " << endl;
    graphNonDirectional.DFS(1);
    cout << endl << endl;

    cout << "Connected components of graph 1: " << endl;
    cout << graphNonDirectional.howManyComponents() << endl << endl;
    cout << "Connected components of graph 2: " << endl;
    cout << notConnected.howManyComponents() << endl << endl;

    cout << "\n##### BFS #####" << endl << endl;

    cout << "BFS Search starting in 1: ";
    graphNonDirectional.BFS(1); cout << endl;
    cout << "BFS Search starting in 5: ";
    graphNonDirectional.BFS(5); cout << endl;
    cout << "BFS Search starting in 7: ";
    graphNonDirectional.BFS(7); cout << endl << endl;

    cout << "Showing distances of all nodes, starting in node:" << endl;
    cout << "1: "; graphNonDirectional.computingDistances(1); cout << endl;
    cout << "5: "; graphNonDirectional.computingDistances(5); cout << endl;
    cout << "7: "; graphNonDirectional.computingDistances(7); cout << endl;

    return 0;
}

Graph FunWithGraphs::graph1() {
    Graph g(9, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(5,7);
    g.addEdge(6,9);
    g.addEdge(7,8);
    return g;
}

Graph FunWithGraphs::graph2() {
    Graph g(9, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(6,9);
    g.addEdge(6,7);
    g.addEdge(8,7);
    g.addEdge(8,9);
    return g;
}

Graph FunWithGraphs::graph3() {
    Graph g(12, false);
    g.addEdge(8,1);
    g.addEdge(8,2);
    g.addEdge(8,3);
    g.addEdge(8,7);
    g.addEdge(8,9);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(5,11);
    g.addEdge(5,12);
    g.addEdge(6,11);
    g.addEdge(6,12);
    g.addEdge(12,11);
    g.addEdge(11,10);
    return g;
}

Graph FunWithGraphs::graph4() {
    Graph g(9, true);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(9,6);
    g.addEdge(7,5);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph5() {
    Graph g(4, true);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(3,1);
    return g;
}

Graph FunWithGraphs::graph6() {
    Graph g(8, true);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(3,1);
    g.addEdge(5,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(6,8);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph7() {
    Graph g(3, true);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(3,2);
    return g;
}

Graph FunWithGraphs::graph8() {
    Graph g(49, false);

    // F
    g.addEdge(1, 2);
    g.addEdge(1, 23);
    g.addEdge(23, 24);
    g.addEdge(23, 29);
    // E
    g.addEdge(3, 4);
    g.addEdge(3, 25);
    g.addEdge(25, 26);
    g.addEdge(25, 30);
    g.addEdge(30, 31);
    // L
    g.addEdge(5, 32);
    g.addEdge(5, 33);
    // I
    g.addEdge(6, 34);
    // Z
    g.addEdge(7, 8);
    g.addEdge(7, 35);
    g.addEdge(35, 36);
    g.addEdge(3, 25);

    // A
    g.addEdge(9, 10);
    g.addEdge(9, 27);
    g.addEdge(27, 28);
    g.addEdge(10, 28);
    g.addEdge(27, 37);
    g.addEdge(28, 38);
    // N
    g.addEdge(11, 39);
    g.addEdge(11, 40);
    g.addEdge(12, 40);
    // O
    g.addEdge(13, 14);
    g.addEdge(13, 41);
    g.addEdge(41, 42);
    g.addEdge(14, 42);

    // N
    g.addEdge(15, 43);
    g.addEdge(15, 44);
    g.addEdge(16, 44);
    // O
    g.addEdge(17, 18);
    g.addEdge(17, 45);
    g.addEdge(45, 46);
    g.addEdge(18, 46);
    // V
    g.addEdge(19, 47);
    g.addEdge(20, 47);
    // O
    g.addEdge(21, 22);
    g.addEdge(21, 48);
    g.addEdge(48, 49);
    g.addEdge(22, 49);

    return g;
}

class FunWithGraphs {
public:

    static Graph graph1();
    static Graph graph2();
    static Graph graph3();
    static Graph graph4();
    static Graph graph5();
    static Graph graph6();
    static Graph graph7();
    static Graph graph8();
};

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

    resetNodes();

    list<int> order = {};

    for (int i = 1 ; i <= n ; i++) {
        if (!nodes[i].visited) {
            topologicalDFS(i, order);
        }
    }

    return order;
}

void Graph::fillDistances(int v) {

    resetNodes();

    queue<int> visitedNodes = {};
    visitedNodes.push(v);
    nodes[v].distance = 0;
    nodes[v].visited = true;

    while (!visitedNodes.empty()) {

        int node = visitedNodes.front();
        visitedNodes.pop();
        cout << node << "->" << nodes[node].distance << " ";

        for (Edge e : nodes[node].adj) {
            int a = e.dest;
            if (!nodes[a].visited) {
                visitedNodes.push(a);
                nodes[a].visited = true;
                nodes[a].distance = nodes[node].distance + 1;
            }
        }
    }
}

int Graph::distance(int a, int b) {

    if (a == b) return 0;

    fillDistances(a);

    return nodes[b].distance ? nodes[b].distance : -1;
}

int Graph::diameter() {

    if (connectedComponents() > 1) return -1;

    int max = INT_MIN;

    for (int i = 1 ; i <= n ; i++) {
        fillDistances(i);
        for (const Node &node : nodes) {
            max = node.distance > max ? node.distance : max;
        }
    }

    return max;
}

bool Graph::colorsDFS(int v) {

    nodes[v].color = GRAY;

    for (Edge edge : nodes[v].adj) {
        int dest = edge.dest;
        if (nodes[dest].color == GRAY) {
            return true;
        } else {
            colorsDFS(dest);
        }
    }

    nodes[v].color = BLACK;
}

bool Graph::hasCycle() {

    resetNodes();

    for (int i = 0 ; i <= n ; i++) {
        if (nodes[i].color == WHITE) {
            bool answer = colorsDFS(i);
            if (answer) return answer; else continue;
        }
    }
    return false;
}

struct Edge {
    int destination;
    int weight;
};

struct Node {
    list<Edge> adjacents;
    bool visited;
    int distance;
    int parent;
};

class Graph {

private:

    int size;
    bool hasDirection;
    vector<Node> nodes;

public:

    Graph(int nodes, bool dir = false);
    void addEdge (int source, int destination, int weight = 1);
    vector<Node> getNodes();
    void setNodes(const vector<Node> &nodes);
    Node* getNode(int index);
};

Graph::Graph(int nodes, bool dir) : nodes(nodes+1) {
    this->size = nodes;
    this->hasDirection= dir;
}

void Graph::addEdge(int source, int destination, int weight) {
    if (source < 1 || source > size || destination < 1 || destination > size) return;
    Edge newEdge;
    newEdge.destination = destination;
    newEdge.weight = weight;
    nodes[source].adjacents.push_back(newEdge);
    if (!hasDirection) {
        Edge anotherEdge;
        anotherEdge.destination = source;
        anotherEdge.weight = weight;
        nodes[destination].adjacents.push_back(anotherEdge);
    }
}

vector<Node> Graph::getNodes() {
    return this->nodes;
}

void Graph::setNodes(const vector<Node> &nodes) {
    this->nodes = nodes;
}

Node* Graph::getNode(int index) {
    return &nodes[index];
}

void fillGraph(Graph &graph) {

    /**
     * Slide 9, MST Part 1
     */
    graph.addEdge(1, 2, 4);
    graph.addEdge(1, 8, 8);
    graph.addEdge(2, 8, 11);
    graph.addEdge(2, 3, 8);
    graph.addEdge(8, 9, 7);
    graph.addEdge(7, 8, 1);
    graph.addEdge(7, 9, 6);
    graph.addEdge(3, 9, 2);
    graph.addEdge(3, 6, 4);
    graph.addEdge(3, 4, 7);
    graph.addEdge(4, 6, 14);
    graph.addEdge(6, 7, 2);
    graph.addEdge(4, 5, 9);
    graph.addEdge(5, 6, 10);
}

void resetNodes(Graph &graph) {

    for (Node &node : graph.getNodes()) {
        node.distance = -1;
        node.parent = -1;
    }
}

Node extractMinimum(vector<Node> &nodes) {

    int minimumDistance = INT_MAX;
    Node minimumNode;

    // Find Node with minimum distance
    for (int i = 0 ; i < nodes.size() ; i++) {
        if (nodes[i].distance < minimumDistance) {
            minimumDistance = nodes[i].distance;
        }
    }

    // Extract and remove minimum
    for (vector<Node>::iterator it = nodes.begin() ; it != nodes.end() ; it++) {
        if (it->distance == minimumDistance) {
            minimumNode = *it;
            nodes.erase(it);
            break;
        }
    }

    return minimumNode;
}

bool equals(const Node &n1, const Node *n2) {
    return n1.visited == n2->visited && n1.distance == n2->visited
           && n1.parent == n2->parent;
}

bool in(const vector<Node> &nodes, Node *searchNode) {

    for (Node node : nodes) {
        if (equals(node, searchNode)) return true;
    }
    return false;
}

int getIndex(Graph graph, const Node &n) {

    for (int i = 1 ; i < graph.getNodes().size() ; i++) {
        if (equals(n, graph.getNode(i))) return i;
    }
    return -1;
}

void PrimAlgorithm(Graph &graph, int node = 0) {

    vector<Node> graphNodes = graph.getNodes();

    Node root = !node && !graphNodes.empty() ?
                graphNodes[1] : graphNodes[node];
    root.distance = 0;

    while (!graphNodes.empty()) {
        Node u = extractMinimum(graphNodes);
        for (Edge &e : u.adjacents) {
            int dest = e.destination;
            if (in(graphNodes, graph.getNode(dest)) && e.weight < graph.getNode(dest)->distance) {
                graph.getNode(dest)->parent = getIndex(graph, u);
                graph.getNode(dest)->distance = e.weight;
            }
        }
    }
}

void showResults(Graph graph) {

    cout << "\nShowing Prim Algorithm results" << endl << endl;
    vector<Node> graphNodes = graph.getNodes();
    for (int i = 1 ; i < graphNodes.size() ; i++) {
        cout << "Node: " << i << endl;
        cout << "Distance: " << graphNodes[i].distance << endl;
        cout << "Parent: " << graphNodes[i].parent << endl << endl;
    }
}

int main() {

    cout << "\n\nNota: o algoritmo não funciona pois não influencia diretamente os dados contidos"
            "No grafo, somente as cópias. Ao criar um grafo de apontadores a situação fica normalizada!\n" << endl;

    Graph graph = Graph(9, false);
    fillGraph(graph);
    resetNodes(graph);
    PrimAlgorithm(graph);
    showResults(graph);

    return 0;
}

class SegmentationFaultException : public exception {
public:
    SegmentationFaultException();
    void showError();
};

SegmentationFaultException::SegmentationFaultException() {};
void SegmentationFaultException::showError() { cout << "Error. pop() not allowed in empty deque!" << endl; }

void Arrays() {

    cout << endl << "Arrays:" << endl;
    char name[] = {'F', 'E', 'U', 'P'};
    for (auto letter : name) cout << letter;
    cout << endl;
}

void Lists() {

    cout << endl << "Lists:" << endl;
    list<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto number : numbers) cout << number << " ";
    cout << endl;
}

void Stack() {

    cout << endl << "Stack:" << endl;
    stack<int> numbers = {};

    if (!numbers.empty()) {
        numbers.pop();
    } else {
        SegmentationFaultException e = SegmentationFaultException();
        e.showError();
    }

    cout << "Input:" << endl;
    for (int i = 0 ; i < 10 ; i++) {
        cout << i << " ";
        numbers.push(i);
    }

    cout << endl << "Output:" << endl;
    while (!numbers.empty()) {
        cout << numbers.top() << " ";   // Show header number
        numbers.pop();                  // Erase header number
    }
    cout << endl;
}

void Queues() {

    cout << endl << "Queue:" << endl;
    queue<int> numbers = {};

    if (!numbers.empty()) {
        numbers.pop();
    } else {
        SegmentationFaultException e = SegmentationFaultException();
        e.showError();
    }

    cout << "Input:" << endl;
    for (int i = 0 ; i < 10 ; i++) {
        cout << i << " ";
        numbers.push(i);
    }

    cout << endl << "Output:" << endl;
    while (!numbers.empty()) {
        cout << numbers.front() << " ";     // Show header number
        numbers.pop();                      // Erase header number
    }
    cout << endl;
}

// @Overload
void showContent(const vector<int> &numbers) {
    for (int number : numbers) cout << number << " ";
    cout << endl;
}

// @Overload
void showContent(priority_queue<int> numbers) {
    while (!numbers.empty()) {
        cout << numbers.top() << " ";
        numbers.pop();
    }
    cout << endl;
}

vector<int> getRandomNumbers() {

    vector<int> numbers = {};
    for (int i = 0 ; i < 20 ; i++) numbers.push_back(1 + rand() % 100);
    return numbers;
}

void priorityQueue() {

    vector<int> numbers = getRandomNumbers();
    cout << "\nInitial content: " << endl;
    showContent(numbers);

    priority_queue<int> sortedNumbers;
    for (int number : numbers) sortedNumbers.push(number);

    cout << "\nSorted content: " << endl;
    showContent(sortedNumbers);
}

void verify(const vector<int> &numbers)  {

    cout << "\nVerification:\n" << endl;

    map<int, int> indexNumber = {};
    for (int i = 0 ; i < numbers.size() ; i++) {
        indexNumber.insert(make_pair(i+1, numbers[i]));
    }

    for (int i = 0 ; i < numbers.size() ; i++) {
        int index1 = (i+1)*2;
        int index2 = (i+1)*2+1;
        if (index2 < numbers.size()) {
            cout << "Parent: " << numbers[i] << endl;
            cout << "Child 1: " << numbers[index1-1] << " correct? " << (numbers[index1-1] == indexNumber[index1]) << endl;
            cout << "Child 2: " << numbers[index2-1] << " correct? " << (numbers[index2-1] == indexNumber[index2]) << endl;
            cout << endl;
        }
    }
}

void heapSort() {

    vector<int> numbers = getRandomNumbers();
    cout << "\nInitial content: " << endl;
    showContent(numbers);

    make_heap(numbers.begin(), numbers.end());
    cout << "\nSorted content: " << endl;
    showContent(numbers);
    verify(numbers);
}

int main () {

    srand(time(NULL));
    Arrays();
    Lists();
    Stack();
    Queues();
    priorityQueue();
    heapSort();
    return 0;
}

// @Overload
void showContent(const vector<int> &numbers) {
    for (int number : numbers) cout << number << " ";
    cout << endl;
}

// @Overload
void showContent(priority_queue<int> numbers) {
    while (!numbers.empty()) {
        cout << numbers.top() << " ";
        numbers.pop();
    }
    cout << endl;
}

vector<int> getRandomNumbers() {

    vector<int> numbers = {};
    for (int i = 0 ; i < 20 ; i++) numbers.push_back(1 + rand() % 100);
    return numbers;
}

void priorityQueue() {

    vector<int> numbers = getRandomNumbers();
    cout << "\nInitial content: " << endl;
    showContent(numbers);

    priority_queue<int> sortedNumbers;
    for (int number : numbers) sortedNumbers.push(number);

    cout << "\nSorted content: " << endl;
    showContent(sortedNumbers);
}

void verify(const vector<int> &numbers)  {

    cout << "\nVerification:\n" << endl;

    map<int, int> indexNumber = {};
    for (int i = 0 ; i < numbers.size() ; i++) {
        indexNumber.insert(make_pair(i+1, numbers[i]));
    }

    for (int i = 0 ; i < numbers.size() ; i++) {
        int index1 = (i+1)*2;
        int index2 = (i+1)*2+1;
        if (index2 < numbers.size()) {
            cout << "Parent: " << numbers[i] << endl;
            cout << "Child 1: " << numbers[index1-1] << " correct? " << (numbers[index1-1] == indexNumber[index1]) << endl;
            cout << "Child 2: " << numbers[index2-1] << " correct? " << (numbers[index2-1] == indexNumber[index2]) << endl;
            cout << endl;
        }
    }
}

void heapSort() {

    vector<int> numbers = getRandomNumbers();
    cout << "\nInitial content: " << endl;
    showContent(numbers);

    make_heap(numbers.begin(), numbers.end());
    cout << "\nSorted content: " << endl;
    showContent(numbers);
    verify(numbers);
}

struct Tree {
    int node;
    Tree* parent;
    int rank;
};

vector<Tree*> makeSets(int number) {

    vector<Tree*> answer;
    for (int i = 0 ; i < number ; i++) {
        Tree newTree = {i, nullptr, 0};
        newTree.parent = &newTree;
        answer.push_back(&newTree);
    }
    return answer;
}

Tree* findSet(Tree *tree) {

    if (tree->parent == tree) return tree;
    return findSet(tree->parent);
}

void unionSet(Tree *t1, Tree *t2) {

    Tree *t1Root = findSet(t1);
    Tree *t2Root = findSet(t2);
    t1Root->parent = t2Root;
}

void disjointSets() {

    vector<Tree*> trees = makeSets(10);

    unionSet(trees[2], trees[3]);

    for (int i = 0 ; i < 10 ; i++) {
        Tree* t = trees[i];
        cout << "Tree " << t->node << " have parent " << (*t->parent).node << " and rank = " << t->rank << endl;
    }

}

int main () {

    srand(time(NULL));
    Arrays();
    Lists();
    Stack();
    Queues();
    priorityQueue();
    heapSort();
    disjointSets();
    return 0;
}

void showResults(Graph graph, const string &algorithmName) {

    cout << "\nShowing " << algorithmName << " Algorithm results" << endl << endl;
    vector<Node> graphNodes = graph.getNodes();
    for (int i = 1 ; i < graphNodes.size() ; i++) {
        cout << "Node: " << i << endl;
        cout << "Distance: " << graphNodes[i].distance << endl;
        cout << "Parent: " << graphNodes[i].parent << endl << endl;
    }
}

void makeSet(Node &node) {

}

bool keySort(const KruskalEdge &e1, const KruskalEdge &e2) {
    return e1.weight < e2.weight;
}

bool in (const vector<KruskalEdge> &edges, const KruskalEdge &newEdge) {
    for (KruskalEdge edge : edges) {
        if ((edge.u == newEdge.u && edge.v == newEdge.v) ||
            (edge.u == newEdge.v && edge.v == newEdge.u)) return true;
    }
    return false;
}

vector<KruskalEdge> getSortedEdges(Graph graph) {

    vector<KruskalEdge> answer = {};
    for (int i = 1 ; i < graph.getNodes().size() ; i++) {
        Node node = graph.getNodes()[i];
        for (Edge edge : node.adjacents) {
            KruskalEdge newEdge = {i, edge.destination, edge.weight};
            if (!in(answer, newEdge)) answer.push_back(newEdge);
        }
    }
    sort(answer.begin(), answer.end(), keySort);
    return answer;
}

int findSet(int node) {
    return 1;
}

void unionSets(int u, int v) {

}

list<KruskalEdge>  KruskalAlgorithm(Graph graph) {

    list<KruskalEdge> minimalSpanningTree = {};

    for (Node node : graph.getNodes()) {
        makeSet(node);
    }

    vector<KruskalEdge> edges = getSortedEdges(graph);

    /*
     * Output de verificação
     * Nota: não haverá necessáriamente um número de E = V - 1 pois o grafo inicial contém ciclos
     */
    for (KruskalEdge edge : edges) {
        cout << "Nodes " << edge.u << " and " << edge.v << " have an edge with weight = " << edge.weight << endl;
    }

    /**
     * Para já, como o findSet não está implementado, sou obrigado a retornar sempre o mesmo valor. Numa situação
     * normal, o conjunto dos edges têm de ser diferentes para não existirem ciclos na Spanning Tree
     */
    for (KruskalEdge edge : edges) {
        if (findSet(edge.u) == findSet(edge.v)) {
            minimalSpanningTree.push_back(edge);
            unionSets(edge.u, edge.v);
        }
    }

    return minimalSpanningTree;
}

void showKruskalsResults(const list<KruskalEdge> &edges) {

    cout << "\n\nResults of Kruskal's Algortithm\n" << endl;
    for (list<KruskalEdge>::const_iterator it = edges.begin() ; it != edges.end() ; it++) {
        cout << "Nodes u = " << it->u << " and v = " << it->v << " have weight = " << it->weight << endl;
    }
    return;
}

int main() {

    cout << "\n\nNota: os algoritmos não funcionam pois não influenciam diretamente os dados contidos"
            "no Grafo mas sim somente as cópias. Ao criar um grafo de apontadores a situação fica normalizada!\n" << endl;

    Graph graph = Graph(9, false);
    fillGraph(graph);
    resetNodes(graph);
    PrimAlgorithm(graph, 1);
    showResults(graph, "Prim");

    Graph graph2 = Graph(9, false);
    fillGraph(graph2);
    resetNodes(graph2);
    list<KruskalEdge> answer = KruskalAlgorithm(graph2);
    showKruskalsResults(answer);

    return 0;
}

#include <unordered_map>

template <class T>
class DisjointSets {

private:

    struct Node {
        T parent;
        int myrank; // to use on union by rank
    };

    unordered_map<T, Node> a;

public:

    void makeSet(const T& x);            // Create a set with a single element x
    T find(const T& x);                  // Find the representative of the set of element x
    void unite(const T& x, const T& y);  // Merge the sets of elements x and y

};

// Create a set with a single element x
template <class T>
void DisjointSets<T>::makeSet(const T& x) {
    a[x].parent = x;
    a[x].myrank = 0;
}

// Find the representative of the set of element x
template <class T>
T DisjointSets<T>::find(const T& x) {
    if (a[x].parent != x)
        a[x].parent = find(a[x].parent);
    return a[x].parent;
}

// Merge the sets of elements x and y
template <class T>
void DisjointSets<T>::unite(const T& x, const T& y) {

    T xRoot = find(x);
    T yRoot = find(y);

    if (a[xRoot].myrank < a[yRoot].myrank) {
        a[xRoot].parent = yRoot;

    } else if (a[xRoot].myrank > a[yRoot].myrank) {
        a[yRoot].parent = xRoot;

    } else {
        a[yRoot].parent = xRoot;
        a[xRoot].myrank = a[xRoot].myrank + 1;
    }
}

#endif

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

int sum(int number) {

    int result = 0;
    int digit;
    while (number) {
        digit = number % 10;
        number = number / 10;
        result += digit;
    }
    return result;
}

int FunWithGraphs::game(const vector<int>& v) {

    MinHeap<int, int> heap(v.size(), -1);
    for (int number : v) heap.insert(number, sum(number));

    while (heap.getSize() > 1) {
        int min1 = heap.removeMin();
        int min2 = heap.removeMin();
        int subtr = abs(min1 - min2);
        heap.insert(subtr, sum(subtr));
    }

    return heap.removeMin();
}

int FunWithGraphs::gridCity(const vector<pair<int, int>>& plants, const vector<pair<int, int>>& houses) {
    return 0;
}

class FunWithGraphs {

public:
    // Some example graphs
    static Graph graph1();
    static Graph graph2();
    static Graph graph3();
    static Graph graph4();

    // ----- Functions to implement in this class -----
    static int game(const vector<int>& v);
    static int gridCity(const vector<pair<int, int>>& plants, const vector<pair<int, int>>& houses);
};

Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {}

void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

int Graph::prim(int r) {

    MinHeap<int, int> heap(n, -1);

    for (int i = 1 ; i <= n ; i++) {
        nodes[i].distance = INT_MAX;
        nodes[i].parent = NULL;
        heap.insert(i, nodes[i].distance);
    }

    nodes[r].distance = 0;
    heap.decreaseKey(r, 0);

    while (heap.getSize()) {

        int nodeIndex = heap.removeMin(); // o índice do nó que possui menor distância a r

        for (Edge edge : nodes[nodeIndex].adj) {
            int neighbor = edge.dest;
            if (heap.hasKey(neighbor) && edge.weight < nodes[neighbor].distance) {
                nodes[neighbor].parent = neighbor;
                nodes[neighbor].distance = edge.weight;
                heap.decreaseKey(neighbor, edge.weight);
            }
        }
    }

    int total = 0;
    for (int i = 1 ; i <= n ; i++) {
        total += nodes[i].distance;
        cout << "Node " << i << " distance: " << nodes[i].distance << endl;
    }

    return total;
}

int Graph::kruskal() {

    vector<Edge> minimalSpanningTree = {};
    vector<Edge> allEdges = {};
    DisjointSets<int> set;

    for (int i = 0 ; i <= n ; i++) {
        set.makeSet(i);
        for (Edge edge : nodes[i].adj) {
            edge.origin = i;
            allEdges.push_back(edge);
        }
    }

    sort(allEdges.begin(), allEdges.end(), [](const Edge &e1, const Edge &e2) { return e1.weight < e2.weight; });

    for (Edge edge : allEdges) {
        if (set.find(edge.origin) != set.find(edge.dest)) {
            minimalSpanningTree.push_back(edge);
            set.unite(edge.origin, edge.dest);
        }
    }

    int total = 0;
    for (Edge edge : minimalSpanningTree)
        total += edge.weight;
    return total;
}

class Graph {

private:

    struct Edge {
        int origin; // origin node
        int dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        int distance;
        int parent;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:

    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);

    // ----- Functions to implement in this class -----
    int prim(int v);
    int kruskal();
};

// Binary min-heap to represent integer keys of type K with values (priorities) of type V
template <class K, class V>
class MinHeap {
    struct Node { // An element of the heap: a pair (key, value)
        K key;
        V value;
    };

    int size;                  // Number of elements in heap
    int maxSize;               // Maximum number of elements in heap
    vector<Node> a;            // The heap array
    unordered_map<K, int> pos; // maps a key into its position on the array a
    const K KEY_NOT_FOUND;

    void upHeap(int i);
    void downHeap(int i);
    void swap(int i1, int i2);

public:
    MinHeap(int n, const K& notFound); // Create a min-heap for a max of n pairs (K,V) with notFound returned when empty
    int getSize();              // Return number of elements in the heap
    bool hasKey(const K& key);  // Heap has key?
    void insert(const K& key, const V& value);      // Insert (key, value) on the heap
    void decreaseKey(const K& key, const V& value); // Decrease value of key
    K removeMin(); // remove and return key with smaller value
};

// Make a value go "up the tree" until it reaches its position
template <class K, class V>
void MinHeap<K,V>::upHeap(int i) {
    while (i>1 && a[i].value < a[PARENT(i)].value) { // while pos smaller than parent, keep swapping to upper position
        swap(i, PARENT(i));
        i = PARENT(i);
    }
}

// Make a value go "down the tree" until it reaches its position
template <class K, class V>
void MinHeap<K,V>::downHeap(int i) {
    while (LEFT(i) <= size) { // while within heap limits
        int j = LEFT(i);
        if (RIGHT(i)<=size && a[RIGHT(i)].value < a[j].value) j = RIGHT(i); // choose smaller child
        if (a[i].value < a[j].value) break;   // node already smaller than children, stop
        swap(i, j);                    // otherwise, swap with smaller child
        i = j;
    }
}

// Swap two positions of the heap (update their positions)
template <class K, class V>
void MinHeap<K,V>::swap(int i1, int i2) {
    Node tmp = a[i1]; a[i1] = a[i2]; a[i2] = tmp;
    pos[a[i1].key] = i1;
    pos[a[i2].key] = i2;
}

// ----------------------------------------------

// Create a min-heap for a max of n pairs (K,V) with notFound returned when empty
template <class K, class V>
MinHeap<K,V>::MinHeap(int n, const K& notFound) : KEY_NOT_FOUND(notFound), size(0), maxSize(n), a(n+1) {
}

// Return number of elements in the heap
template <class K, class V>
int MinHeap<K,V>::getSize() {
    return size;
}

// Heap has key?
template <class K, class V>
bool MinHeap<K, V>::hasKey(const K& key) {
    return pos.find(key) != pos.end();
}

// Insert (key, value) on the heap
template <class K, class V>
void MinHeap<K,V>::insert(const K& key, const V& value) {
    if (size == maxSize) return; // heap is full, do nothing
    if (hasKey(key)) return;     // key already exists, do nothing
    a[++size] = {key, value};
    pos[key] = size;
    upHeap(size);
}

// Decrease value of key to the indicated value
template <class K, class V>
void MinHeap<K,V>::decreaseKey(const K& key, const V& value) {
    if (!hasKey(key)) return; // key does not exist, do nothing
    int i = pos[key];
    if (value > a[i].value) return; // value would increase, do nothing
    a[i].value = value;
    upHeap(i);
}

// remove and return key with smaller value
template <class K, class V>
K MinHeap<K,V>::removeMin() {
    if (size == 0) return KEY_NOT_FOUND;
    K min = a[1].key;
    pos.erase(min);
    a[1] = a[size--];
    downHeap(1);
    return min;
}

// Created on January, 2022
// @author: Fábio Araújo de Sá

#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

struct Edge {
    int destination;
    int weight;
};

struct Node {
    list<Edge> adjacents;
    bool visited;
    int distance;
    int parent;
};

class Graph {

private:

    int size;
    bool hasDirection;
    vector<Node> nodes;

public:

    Graph(int nodes, bool dir = false);
    void addEdge (int source, int destination, int weight = 1);
    vector<Node> getNodes();
    void setNodes(const vector<Node> &nodes);
    Node* getNode(int index);
};

Graph::Graph(int nodes, bool dir) : nodes(nodes+1) {
    this->size = nodes;
    this->hasDirection= dir;
}

void Graph::addEdge(int source, int destination, int weight) {
    if (source < 1 || source > size || destination < 1 || destination > size) return;
    Edge newEdge;
    newEdge.destination = destination;
    newEdge.weight = weight;
    nodes[source].adjacents.push_back(newEdge);
    if (!hasDirection) {
        Edge anotherEdge;
        anotherEdge.destination = source;
        anotherEdge.weight = weight;
        nodes[destination].adjacents.push_back(anotherEdge);
    }
}

vector<Node> Graph::getNodes() {
    return this->nodes;
}

void fillGraph(Graph &graph) {

    /**
     * Slide 5, Shortest Path
     */

    int s = 1;
    int t = 2;
    int x = 3;
    int y = 4;
    int z = 5;

    graph.addEdge(s, t, 10);
    graph.addEdge(s, y, 5);
    graph.addEdge(t, y, 2);
    graph.addEdge(t, x, 1);
    graph.addEdge(x, z, 4);
    graph.addEdge(y, t, 3);
    graph.addEdge(y, x, 9);
    graph.addEdge(y, z, 2);
    graph.addEdge(z, s, 7);
    graph.addEdge(z, x, 6);
}

void resetNodes(Graph &graph) {

    for (Node &node : graph.getNodes()) {
        node.distance = -1;
        node.parent = -1;
    }
}

map<int, char> getKeys() {

    map<int, char> keys = {};
    keys.insert(make_pair('s', 1));
    keys.insert(make_pair('t', 2));
    keys.insert(make_pair('x', 3));
    keys.insert(make_pair('y', 4));
    keys.insert(make_pair('z', 5));
    return keys;
}

int main () {

    cout << "Algorithm" << endl << endl;
    Graph graph(5, true);
    fillGraph(graph);
    map<int, char> keys = getKeys();

    for (int i = 1 ; i <= graph.getNodes().size() ; i++) {
        Node currentNode = graph.getNodes()[i];
        cout << "Node " << keys[i] << ": " << endl;
        for (Edge edge : currentNode.adjacents) {
            cout << "Node " << keys[i] << " to Node " << keys[edge.destination] << " weight = " << edge.weight << endl;
        }
        cout << endl;
    }

    return 0;
}

Graph FunWithGraphs::graph1() {
    Graph g(7, false);
    g.addEdge(1, 2, 12);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 4, 8);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 1);
    g.addEdge(3, 5, 9);
    g.addEdge(3, 6, 3);
    g.addEdge(3, 7, 6);
    g.addEdge(4, 5, 5);
    g.addEdge(4, 6, 5);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7,1);
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
    Graph g(11, true);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 7, 1);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 8, 15);
    g.addEdge(8, 3, 8);
    g.addEdge(4, 3, 4);
    g.addEdge(5, 4, 3);
    g.addEdge(6, 4, 1);
    g.addEdge(8, 4, 2);
    g.addEdge(10, 5, 2);
    g.addEdge(10, 6, 3);
    g.addEdge(11, 6, 5);
    g.addEdge(7, 8, 5);
    g.addEdge(7, 9, 2);
    g.addEdge(8, 9, 1);
    g.addEdge(9, 10, 7);
    g.addEdge(11, 9, 3);
    g.addEdge(11, 10, 5);
    return g;
}

Graph FunWithGraphs::graph4() {
    Graph g(4, false);
    g.addEdge(1, 2, 5);
    g.addEdge(2, 1, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(3, 1, 8);
    g.addEdge(1, 4, 9);
    g.addEdge(3, 2, 42);
    g.addEdge(4, 2, -6);
    g.addEdge(4, 3, -8);
    return g;
}

class FunWithGraphs {
    static Graph *g;
    static map<string, int> index;

public:
    static Graph graph1();
    static Graph graph2();
    static Graph graph3();
    static Graph graph4();
};

Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

void Graph::dijkstra(int s) {
    MinHeap<int, int> q(n, -1);
    for (int v=1; v<=n; v++) {
        nodes[v].dist = INF;
        q.insert(v, INF);
        nodes[v].visited = false;
    }
    nodes[s].dist = 0;
    q.decreaseKey(s, 0);
    nodes[s].pred = s;
    while (q.getSize()>0) {
        int u = q.removeMin();
        // cout << "Node " << u << " with dist = " << nodes[u].dist << endl;
        nodes[u].visited = true;
        for (auto e : nodes[u].adj) {
            int v = e.dest;
            int w = e.weight;
            if (!nodes[v].visited && nodes[u].dist + w < nodes[v].dist) {
                nodes[v].dist = nodes[u].dist + w;
                q.decreaseKey(v, nodes[v].dist);
                nodes[v].pred = u;
            }
        }
    }
}

int Graph::dijkstra_distance(int a, int b) {
    dijkstra(a);
    if (nodes[b].dist == INF) return -1;
    return nodes[b].dist;
}

list<int> Graph::dijkstra_path(int a, int b) {
    dijkstra(a);
    list<int> path;
    if (nodes[b].dist == INF) return path;
    path.push_back(b);
    int v = b;
    while (v != a) {
        v = nodes[v].pred;
        path.push_front(v);
    }
    return path;
}

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
        string line; //
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        int dist;
        int pred;
        bool visited;
        string name;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented

    void dijkstra(int s);

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);

    // ----- Functions to implement in this class -----
    int dijkstra_distance(int a, int b);
    list<int> dijkstra_path(int a, int b);
};

void showContent(const set<int> &numbers) {
    for (set<int>::iterator i = numbers.begin() ; i != numbers.end() ; i++) {
        cout << *i << ", ";
    }
    cout << endl;
}

void showContent(const multiset<int> &numbers) {
    for (multiset<int>::iterator i = numbers.begin() ; i != numbers.end() ; i++) {
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

void randomFill(multiset<int> &numbers , int requestedSize) {

    string answer = numbers.empty() ? "empty" : "not empty"; cout << answer << endl;

    while (numbers.size() != requestedSize) {
        numbers.insert(rand() % 20);
    }
    showContent(numbers);
}

bool exists(const set<int> &numbers, int attemp) {
    return numbers.find(attemp) != numbers.end();
}

bool exists(const multiset<int> &numbers, int attemp) {
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

void eraseElement(multiset<int> &numbers, int element) {
    if (exists(numbers, element)) {
        numbers.erase(numbers.find(element));
    } else cout << "Elemento não encontrado" << endl;
    showContent(numbers);
}

void eraseElementByPosition(multiset<int> &numbers , int position) {
    if (position >= numbers.size()) return;
    set<int>::iterator it = numbers.begin();
    advance(it, position-1);
    numbers.erase(it);
    showContent(numbers);
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

void showContent(map<string, int> names) {
    for (map<string, int >::iterator it = names.begin() ; it != names.end() ; it++) {
        cout << "'" <<  it->first << "' -> " << it->second << endl;
    }
}

void showContent(multimap<string, int> names) {
    for (multimap<string, int >::iterator it = names.begin() ; it != names.end() ; it++) {
        cout << "'" <<  it->first << "' -> " << it->second << endl;
    }
}

void fillMap(map<string, int> &names) {

    names["Inicializado apenas"];
    names["Faculdade"] = 9;
    names["Engenharia"] = 11;
    names["Engenharia"] = 13;
    names["Engenharia"] = 12;
    names["Universidade"] = -5;
    names["Universidade"] = 6;
    names["Universidade"] = 4;
    names["Porto"] = 10;
    names["Porto"] = 11;
    names["Porto"] = 11;
    names.insert(make_pair<string, int>("FEUP", 23));
    names.insert(make_pair<string, int>("FEUP", 20));
    names.insert(make_pair<string, int>("FEUP", 24));
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

bool exists(multimap<string, int> &names, string name) {
    return names.find(name) != names.end();
}

void removeKey(multimap<string, int> &names, string name) {
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

#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

void showContent(priority_queue<int> numbers) {

    cout << "Content: ";
    while (!numbers.empty()) {
        cout << numbers.top() << " ";
        numbers.pop();
    }
    cout << endl;
}

void fillContent(priority_queue<int> &numbers, int size) {

    while (numbers.size() < size) {
        int attemp = rand() % 20;
        cout << "Inserindo n = " << attemp << endl;
        numbers.push(attemp);
    }
}

int main () {

    srand(time(NULL));
    priority_queue<int> numbers;
    fillContent(numbers, 10);
    showContent(numbers);           // Content: 19 16 15 14 14 11 6 5 2 1

    return 0;
}