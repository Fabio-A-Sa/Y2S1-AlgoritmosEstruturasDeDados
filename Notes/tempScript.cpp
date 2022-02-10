// Fun with HashTables!

#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

void showContent (unordered_map<string, int> &names) {
    for (unordered_map<string, int>::iterator it = names.begin() ; it != names.end() ; it++) {
        cout << it->first << " -> " << it->second << endl;
    }
}

void fillUnorderedMap (unordered_map<string, int> &names) {
    names.insert(make_pair("cao", 1));
    names.insert(make_pair("cao", 4));
    names.insert(make_pair("cao", 2));
    names.insert(make_pair("gato", 9));
    names.insert(make_pair("passaro", 1));
    names.insert(make_pair("passaro", 1));
    names.insert(make_pair("tartaruga", 3));
}

bool exists(const unordered_map<string, int> &names, const string &key) {
    return names.find(key) != names.end();
}

void removeKey(unordered_map<string, int> &names, const string &key) {
    if (exists(names, key))
        names.erase(names.find(key));
}

void showContent (unordered_multimap<string, int> &names) {
    for (unordered_multimap<string, int>::iterator it = names.begin() ; it != names.end() ; it++) {
        cout << it->first << " -> " << it->second << endl;
    }
}

void fillUnorderedMap (unordered_multimap<string, int> &names) {
    names.insert(make_pair("cao", 1));
    names.insert(make_pair("cao", 4));
    names.insert(make_pair("cao", 2));
    names.insert(make_pair("gato", 9));
    names.insert(make_pair("passaro", 1));
    names.insert(make_pair("passaro", 1));
    names.insert(make_pair("tartaruga", 3));
}

bool exists(const unordered_multimap<string, int> &names, const string &key) {
    return names.find(key) != names.end();
}

void removeKey(unordered_multimap<string, int> &names, const string &key) {
    if (exists(names, key))
        names.erase(names.find(key));
}

int main () {

    // unordered sets
    unordered_map<string, int> names;
    fillUnorderedMap(names);
    showContent(names);                                         // tartaruga = 3, passaro = 1, gato = 9, cao = 1

    cout << exists(names, "tartaruga") << endl;                 // 1
    cout << exists(names, "rola") << endl;                      // 0
    removeKey(names, "tartaruga");                              // passaro = 1, gato = 9, cao = 1

    // unordered multisets
    unordered_multimap<string, int> names2;
    fillUnorderedMap(names2);
    showContent(names2);                                    // passaro = 1, passaro = 1, gato = 9, cao = 1, cao = 4, cao = 9

    cout << exists(names2, "tartaruga") << endl;    // 1
    cout << exists(names2, "rola") << endl;         // 0
    removeKey(names2, "cao");                                   // passaro = 1, passaro = 1, gato = 9, cao = 4, cao = 9

    return 0;
}