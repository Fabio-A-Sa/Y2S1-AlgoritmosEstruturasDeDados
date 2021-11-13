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

