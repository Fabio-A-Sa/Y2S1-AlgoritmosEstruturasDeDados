// Created on 11 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <typeinfo>
using namespace std;

const vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q',
                                    'R', 'S', 'T', 'U', 'V', 'X', 'X'   };

const vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

const int diffBetweenTypes = pow(numbers.size(), 4) * pow(letters.size(), 2);

int findType (string &matricula) { // Find type (1, 2, 3, 4) and modify matricula to type 1
    return 1;
}

template<class C>
int diff(C c1, C c2) {
    if ()
}

int main () {

    int lines;
    string matricula1, matricula2;

    cin >> lines;
    for (int i = 0 ; i < lines ; i++) {
        cin >> matricula1 >> matricula2;
        cout << matricula2 << endl;
    }
    
    return 0;
}