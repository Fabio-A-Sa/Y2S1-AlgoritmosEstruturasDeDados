// Created on 14 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool notIn (vector<char> all, char c) {
    for (auto a : all) if (a == c) return false;
    return true;
}

bool sortKey (pair<char, int> a, pair<char, int> b) {
    return a.second > b.second;
}

vector<pair<char, int>> getResult(const string &m) {

    vector<pair<char, int>> result = {};
    vector<char> visited = {};

    for (int i = 0 ; i < m.size() ; i++) {
        char c = m[i];
        if (notIn(visited, c)) {
            int occurrence = 1;
            for (int j = i + 1; j < m.size() ; j++) {
                if (m[j] == c) occurrence++;
            }
            pair<char, int> p(c, occurrence);
            result.push_back(p);
            visited.push_back(c);
        }
    }
    sort(result.begin(), result.end(), sortKey);
    return result;
}

int main() {

    string ADN;
    cin >> ADN;

    vector<pair<char, int>> result = getResult(ADN);
    for (int i = 0 ; i < result.size() ; i++) {
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}