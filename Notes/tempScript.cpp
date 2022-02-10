// Fun with Red Black Trees!

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

int main () {

    // unordered sets
    unordered_set<string> names;
    fillUnorderedSet(names);
    showContent(names);

    // unordered multisets

    return 0;
}