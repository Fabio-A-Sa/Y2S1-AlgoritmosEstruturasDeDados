// Created on 21 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solve (vector<int> numbers, int question) {

    vector<int> result = {};
    int a, int b, int minRange = INT_MAX;
    for (int i = 0 ; i < numbers.size() ; i++) {
        for (int j = i + 1 ; j < numbers.size() ; j++) {
            if (abs() < minRange) {
                minRange =
            }
        }
    }

    return result;
}

int main () {

    int nNumbers, currentNumber, nQuestions, currentQuestion;
    vector<int> numbers = {}, questions = {};

    cin >> nNumbers;
    for (int i = 0 ; i < nNumbers ; i++) {
        cin >> currentNumber;
        numbers.push_back(currentNumber);
    }
    sort(numbers.begin(), numbers.end());

    cin >> nQuestions;
    for (int i = 0 ; i < nQuestions ; i++) {
        cin >> currentQuestion;
        questions.push_back(currentQuestion);
    }

    return 0;
}