// Created on 20 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class ADN {

    public:
        string sequence;
        string unique;
        ADN(string name);
        void showFrequency();
        bool key(const pair<char, int> &a, const pair<char, int> &b);
};

bool notIn (char c, string s) {
    for (auto l : s) if (c == l) return false;
    return true;
}

ADN::ADN(string sequence) : sequence(sequence) {
    string t = "";
    for (auto letter : sequence) if (notIn(letter, t)) t += letter;
    this->unique = t;
}

bool ADN::key(const pair<char, int> &a, const pair<char, int> &b) {

    if (a.second == b.second) {
        return true;
    } else return a.second > b.second;
}

void ADN::showFrequency() {

    vector<pair<char, int>> frequency = {};
    for (auto letter : unique) frequency.push_back(pair<char, int>(letter, count(sequence.begin(), sequence.end(), letter)));
    sort(frequency.begin(), frequency.end(), ADN::key);

    for (auto pair : frequency) {
        cout << pair.first << " " <<pair.second << endl;
    }
}

int main () {

    string sequence;
    cin >> sequence;
    ADN input = ADN(sequence);
    input.showFrequency();

    return 0;
}