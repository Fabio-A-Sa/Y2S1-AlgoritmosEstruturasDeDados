// Created on 23 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <list>
#include <string>
using namespace std;

int getWords (const string &phrase) {
    int result = 0;
    for (auto letter : phrase) if (letter == ' ') result++;
    return result++;
}

string getLoser (const string& phase, const list<string> &kids) {

    int words = getWords(phrase);
    int index = 0;

    while (kids.size() > 1) {
        index = (words-1+index) % kids.size();
        list<Kid>::iterator it = kids.begin();
        for (int i = 0 ; i < index ; i++) { it++; }
        kids.remove(*it);
    }

    return kids.front();
}

void showResults (const string& phrase, const list<string> &kids) {

    string loser = getLoser(phrase, kids);
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