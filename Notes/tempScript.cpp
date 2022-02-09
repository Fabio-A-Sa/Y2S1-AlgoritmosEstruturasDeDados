// Fun with Red Black Trees!

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <ctime>
using namespace std;

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