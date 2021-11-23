// Created on 23 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void solve (const string &expression) {
    cout << "Test" << endl;
}

int main () {

    int loops;
    string currentExpression;
    cin >> loops;

    for (int i = 0 ; i < loops ; i++) {
        cin >> currentExpression;
        solve(currentExpression);
    }
    return 0;
}