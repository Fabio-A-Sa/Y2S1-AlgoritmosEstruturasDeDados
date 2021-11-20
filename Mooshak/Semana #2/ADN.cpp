// Created on 20 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool keySort (pair<char, int> a, pair<char, int> b) {
    if (a.second == b.second) {
        return false;
    } else {
        return a.first < b.first ;
    }
}

void atualize (vector<pair<char, int>> &result, char c) {

    bool found = false;
    for (auto &p : result) {
        if (p.first == c) {
            p.second += 1;
            found = true;
        }
    }
    if (!found) {
        result.push_back(pair<char, int>(c, 1));
    }

}

void getResult(const string &m) {

    vector<pair<char, int>> result = {};
    for (auto c : m) atualize(result, c);
    sort(result.begin(), result.end(), keySort);
    for (auto pair : result) {
        cout << pair.first << " " << pair.second << endl;
    }

}

int main() {

    string ADN = "PPOIUYTREWQ";
    getResult(ADN);
    return 0;
}