// Fun with Red Black Trees!

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <ctime>
using namespace std;

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