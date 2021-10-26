// Created on October, 2021
// @author: Fábio Araújo de Sá
// Theorical Lecture 2, 22/10/2021, Correctness Analysis

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

template <class Number>
Number squareRoot (Number n) { return sqrt(n); }

int main () {

    double x = 25.651;
    double result = squareRoot(25.651);
    cout << "\n\nPreconditions and postconditions\n" << endl;
    cout << "X = " << x << endl << "Result = squareRoot(X) = " << result << endl;
    cout << "Preconditions: x >= 0\nPostconditions: result >= 0 && pow(result, 2) == x" << endl;

    

    return 0;
}