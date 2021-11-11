// Created on 11 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
using namespace std;

int main() {

    int lines, attemp;
    cin >> lines;
    int count = 0;

    for (int i = 0 ; i < lines ; i++) {
        cin >> attemp;
        if (attemp == 42) count++;
    }

    cout << count << endl;

    return 0;
}