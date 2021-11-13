// Created on 11 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <typeinfo>
#include <algorithm>

using namespace std;

const vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q',
                                    'R', 'S', 'T', 'U', 'V', 'X', 'X'   };

const vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

const int diffBetweenTypes = pow(numbers.size(), 4) * pow(letters.size(), 2) ;

/**
 * Type 1: XX-NN-NN
 * Type 2: NN-NN-XX
 * Type 3: NN-XX-NN
 * Type 4: XX-NN-XX
 * myType: XX-NNNN or XXXX-NN quando aplicável
 */
int findType (string & m) { // Find type (1, 2, 3, 4) and normalize to myType to compare later

    int type;
    string p1 = m.substr(0, 2), p2 = m.substr(3, 2), p3 = m.substr(6, 2);
    cout << p2 <<
    return 1;
}

int diffChar(char c1, char c2) {
    int indexC1, indexC2;
    for (int i = 0 ; i < letters.size() ; i++) {
        if (letters[i] =)
    }
    return abs(indexC1 - indexC2);
}

long int getDiff(string m1, string m2) {
    return 0;
}

int main () {

    int lines;
    string matricula1, matricula2;

    cin >> lines;
    for (int i = 0 ; i < lines ; i++) {
        cin >> matricula1 >> matricula2;
        cout << getDiff(matricula1, matricula2) << endl;
    }

    return 0;
}