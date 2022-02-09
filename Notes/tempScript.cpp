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
    names.insert(make_pair<string, int>("FEUP", 23));
    names.insert(make_pair<string, int>("FEUP", 20));
    names.insert(make_pair<string, int>("FEUP", 24));
}

int main () {

    // Map
    map<string, int> names;
    fillMap(names);
    showContent(names);

    return 0;
}