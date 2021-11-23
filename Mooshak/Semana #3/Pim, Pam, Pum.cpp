// Created on 23 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <list>
#include <string>
using namespace std;

int getWords (const string &phrase) {

    cout << "phrase: " << phrase << endl;
    int result = 0;
    for (auto letter : phrase) if (letter == ' ') result++;
    return result + 1;
}

string getLoser (int words, list<string> kids) {

    cout << "Number of words: " << words << endl;
    int index = 0;

    while (kids.size() > 1) {
        index = (words-1+index) % kids.size();
        list<string>::iterator it = kids.begin();
        for (int i = 0 ; i < index ; i++) { it++; }
        cout << "Pessoa salva: " <<  *it << endl;
        kids.remove(*it);
        cout << "Index do próximo: " << index << endl;
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
    string phrase, currentName, line;
    cin >> loops;

    for (int i = 0 ; i < loops ; i++) {
        cin.clear();
        cin.ignore(10000, '\n');
        getline(cin, phrase);
        //cin.clear();
        //cin.ignore(10000, '\n');
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