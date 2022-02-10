// Fun with HashTables!

#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

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

void showContent (const unordered_multiset<string> &names) {
    for (unordered_multiset<string>::iterator it = names.begin() ; it != names.end() ; it++) {
        cout << "Name: " << *it << endl;
    }
}

void fillUnorderedSet(unordered_multiset<string> &names) {
    names.insert("cao");
    names.insert("cao");
    names.insert("gato");
    names.insert("tartaruga");
    names.insert("passaro");
    names.insert("passaro");
    names.insert("gato");
}

bool exists(const unordered_multiset<string> &names, const string &key) {
    return names.find(key) != names.end();
}

void removeKey(unordered_multiset<string> &names, const string &key) {
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