// Created on 11 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const vector<vector<string>> keys = { {"AA-00-00", "ZZ-99-99"},
                                      {"00-00-AA", "99-99-ZZ"},
                                      {"00-AA-00", "99-ZZ-99"},
                                      {"AA-00-AA", "ZZ-99-ZZ"}, };

const vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} ;

const vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                              'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q',
                              'R', 'S', 'T', 'U', 'V', 'X', 'Z'   } ;

const int diffBetweenTypes = pow(numbers.size(), 4) * pow(letters.size(), 2) ;

int findType (string m) {

    string p1 = m.substr(0, 2), p2 = m.substr(3, 2), p3 = m.substr(6, 2);

    if (isalpha(p1[0]) && isdigit(p2[0]) && isdigit(p3[0])) {
        return 1;
    } else if (isdigit(p1[0]) && isdigit(p2[0]) && isalpha(p3[0])) {
        return 2;
    } else if (isdigit(p1[0]) && isalpha(p2[0]) && isdigit(p3[0])) {
        return 3;
    } else if (isalpha(p1[0]) && isdigit(p2[0]) && isalpha(p3[0])) {
        return 4;
    } else {
        return 0;
    }
}

/**
 * Type 1: LL-NN-NN
 * Type 2: NN-NN-LL
 * Type 3: NN-LL-NN
 * Type 4: LL-NN-LL
 */

int d (char c1, char c2) { // Check

    int ic1 = 0, ic2 = 0;
    for (int i = 0 ; i < letters.size() ; i++) {
        if (letters[i] == c1) ic1 = i;
        if (letters[i] == c2) ic2 = i;
    }
    return abs(ic1-ic2);
}

int interval(string m1, string m2) { // Check

    int index = m1.size()-1, exponent = 0;
    int result = 0;
    while (index > -1) {
        //cout <<  d(m1[index], m2[index]) << endl;
        result = result + d(m1[index], m2[index]) * pow(23, exponent);
        index--;
        exponent++;
    }
    return result;
}

int getDiff (string m1, string m2, int type, bool first) {

    int n1, n2, n3;
    switch (type) {

        case 1: // Type 1: LL-NN-NN
            if (first) {
                n1 = abs(stoi(m1.substr(3, 2) + m1.substr(6, 2)) - stoi(m2.substr(3, 2) + m2.substr(6, 2))) + 1;
            } else {
                n1 = abs(stoi(m1.substr(3, 2) + m1.substr(6, 2)) - stoi(m2.substr(3, 2) + m2.substr(6, 2))); // NNNN integer
            }
            n1 = n1 ? n1 : 1;
            n2 = interval(m1.substr(0, 2), m2.substr(0, 2));
            n2 = n2 ? n2 : 1;
            n3 = n1 * n2;
            break;

        case 2: // Type 2: NN-NN-LL
            n1 = abs(stoi(m1.substr(0, 2) + m1.substr(3, 2)) - stoi(m2.substr(0, 2) + m2.substr(3, 2))); // NNNN integer
            n1 = n1 ? n1 : 1;
            n2 = interval(m1.substr(6, 2), m2.substr(6, 2));
            n2 = n2 ? n2 : 1;
            n3 = n1 * n2;
            break;

        case 3: // Type 3: NN-LL-NN
            n1 = abs(stoi(m1.substr(0, 2) + m1.substr(6, 2)) - stoi(m2.substr(0, 2) + m2.substr(6, 2))); // NNNN integer
            n1 = n1 ? n1 : 1;
            n2 = interval(m1.substr(3, 2), m2.substr(3, 2));
            n2 = n2 ? n2 : 1;
            n3 = n1 * n2;
            break;

        case 4: // Type 4: LL-NN-LL
            n1 = abs(stoi(m1.substr(3, 2)) - stoi(m2.substr(3, 2))); // NN integer
            n1 = n1 ? n1 : 1;
            n2 = interval(m1.substr(0, 2) + m1.substr(6, 2), m2.substr(0, 2) + m2.substr(6, 2));
            n2 = n2 ? n2 : 1;
            n3 = n1 * n2;
            break;

        default:
            cout << "Error" << endl;
    }
    //cout << "n1 = " << n1 << " n2 = " << n2 << " n3 = " << n3 << endl;
    return n3;
}

bool old (string m1, string m2) {
    return findType(m1) < findType(m2);
}

void solve(string m1, string m2) {

    vector<string> m = {m1, m2}; sort(m.begin(), m.end(), old);
    int t0 = findType(m[0]), t1 = findType(m[1]); // T0 <= T1 sempre
    cout << t0 << " and " << t1 << endl;

    if (t1 == t0) {
        int a0 = getDiff(m[0], m[1], t0, false);
        cout << m[0] << " vai até " << m[1] << " as duas de tipo " << t0 << " e intervalo = " << a0 << endl << endl;

    } else {

        int a0 = getDiff(m[0], keys[t0 - 1][1], t0, true);
        cout << "string = " << m[0] << " vai até " << keys[t0 - 1][1] << " as duas de tipo " << t0 << " e intervalo calculado " << a0 << endl;
        int a1 = getDiff(keys[t1 - 1][0], m[1], t1, false);
        cout << "string = " << keys[t1 - 1][0] << " vai até " << m[1] << " as duas de tipo " << t1 << " e intervalo calculado " << a1 << endl;

        if (abs(t1-t0) >= 2) {
            cout << a0+a1 + diffBetweenTypes*abs(t1-t0-1) << endl << endl;
        } else {
            cout << a0+a1 << endl << endl;
        }
    }
}

int main () {

    //solve("ZZ-90-00", "00-00-AA");
    //solve("01-AA-00", "00-AA-99");
    solve("AA-00-00", "00-00-AA");
    //solve("23-AC-47", "41-86-ZZ");
    //solve("98-ZZ-99", "AA-42-AA");
    //solve("ZZ-99-ZZ", "AA-00-00");
    //solve("GT-09-32", "32-TG-09");
    //solve("12-SV-45", "67-PT-89");

    return 0;
}