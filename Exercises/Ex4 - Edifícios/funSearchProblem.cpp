// Created on November, 2021
// @author: Fábio Araújo de Sá

#include "funSearchProblem.h"

FunSearchProblem::FunSearchProblem() {}

int FunSearchProblem::facingSun(const vector<int> & values) {

    if (!values.empty()) {
        int result = 1, maxHeight = values[0];
        for (int i = 1 ; i < values.size() ; i++ ) {
            if (maxHeight < values[i]) {
                maxHeight = values[i];
                result++;
            }
        }
        return result;
    }
    return 0;
}

int FunSearchProblem::squareR(int num) {

    if (num > 0) {

        int left = 1, right = num, middle;

        while (right - left > 1) {

            middle = (right + left) / 2;
            if (middle*middle > num) {
                right = middle;
            } else if (middle*middle < num) {
                left = middle;
            } else {
                return middle;
            }
        }
        return left;

    } else {
        cout << "Invalid number" << endl;
        return 0;
    }
}

int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    return 0;
}

int findStudents(const vector<int> & values, int students) {

    int sum = 0, maxStudents = 1;
    for (auto number : values) {
        sum += number;
        if (sum > students) {
            sum = number;
            maxStudents++;
        }
    }
    return maxStudents;
}

int FunSearchProblem::minPages(const vector<int> & values, int numSt) {

    if (!values.empty() && values.size() >= numSt) {

        // low: máximo valor do vector = mínimo número de páginas por aluno
        // high: soma de todos os valores do vector = máximo número de páginas por aluno
        // Algoritmo semelhante ao Painters Problem

        int low = values[0], high = 0;
        for (auto number : values) {
            high += number;
            if (low < number) low = number;
        }

        while (low < high) {
            int middle = low + (high-low) / 2;
            if (findStudents(values, middle) <= numSt) high = middle;
            else low = middle + 1;
        }
        return low;
    }
    return -1;
}