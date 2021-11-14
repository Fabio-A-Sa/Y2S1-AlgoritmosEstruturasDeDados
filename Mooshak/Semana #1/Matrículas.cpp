// Created on 11 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <pair>

using namespace std;

// type --> minLimit, maxLimit
const vector<pair<int, vector<string>>> keys = { pair(1, {"", ""})

};

const vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q',
                                    'R', 'S', 'T', 'U', 'V', 'X', 'X'   } ;

const vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} ;

const int diffBetweenTypes = pow(numbers.size(), 4) * pow(letters.size(), 2) ;

/**
 * Type 1: LL-NN-NN
 * Type 2: NN-NN-LL
 * Type 3: NN-LL-NN
 * Type 4: LL-NN-LL
 */

int findType (string & m) {

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

void getDiff(string m1, string m2) {

    int t1 = findType(m1);
    int t2 = findType(m2);
    if (t1 > t2) swap(m1, m2);

    cout << "m1 = " << findType(m1) << " and m2 = " << findType(m2) << endl;
    cout << "A distância é de pelo menos " << abs(findType(m1)- findType(m2)) * diffBetweenTypes << endl << endl;
}

int main () {

    /**
     *     int lines;
    string matricula1, matricula2;

    cin >> lines;
    for (int i = 0 ; i < lines ; i++) {
        cin >> matricula1 >> matricula2;
        cout << getDiff(matricula1, matricula2) << endl;
    }
     */

    getDiff("ZZ-90-00", "00-00-AA");
    getDiff("01-AA-00", "00-AA-99");
    getDiff("AA-00-00", "00-00-AA");
    getDiff("23-AC-47", "41-86-ZZ");
    getDiff("98-ZZ-99", "AA-42-AA");
    getDiff("ZZ-99-ZZ", "AA-00-00");
    getDiff("GT-09-32", "32-TG-09");
    getDiff("12-SV-45", "67-PT-89");

    return 0;
}