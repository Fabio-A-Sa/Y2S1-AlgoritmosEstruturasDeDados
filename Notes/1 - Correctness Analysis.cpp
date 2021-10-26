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
    cout << "Preconditions: x >= 0\nPostconditions: result >= 0 && pow(result, 2) == x\n" << endl;

    cout << "Parcial correctness:\n\t- Com as pré-condições correctas, caso o algoritmo termine então está correcto;" << endl;
    cout << "\t- Detetar a invariante do ciclo e provar a veracidade para o início, meio e fim;\n" << endl;
    cout << "Total correctness:\n\t- Com as pré-condições correctas provar que o algoritmo termina;" << endl;
    cout << "\t- Detetar a invariante do ciclo e provar a veracidade para o início, meio e fim;" << endl;
    cout << "\t- Detetar a variante do ciclo e provar que é uma expressão inteira, não-negativa e decrescente;\n\n" << endl;

    return 0;
}