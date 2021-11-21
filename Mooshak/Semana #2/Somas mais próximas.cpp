// Created on 21 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void showResult (vector<int> result, int question) {

    if (!result.empty()) {

        if (result.size() == 1) {
            cout << result[result.size()-1] << endl;
        } else {
            int minRange = abs(question - result[result.size()-1]);
            for (int i = 0 ; i < result.size() ; i++ ) {
                if (result[i] == result[result.size()-1]) {
                    cout << result[i];
                } else {
                    if (abs(result[i]-question) == minRange) {
                        cout << result[i] << " ";
                    }
                }

            }
            cout << endl;
        }

    } else cout << endl;
}

vector<int> solve (vector<int> numbers, int question) {

    vector<int> result = {};
    int a, b, minRange = 2147483647;
    for (int i = 0 ; i < numbers.size() ; i++) {
        for (int j = i + 1 ; j < numbers.size() ; j++) {
            if (abs(numbers[i]+numbers[j]-question) <= minRange) {
                a = numbers[i];
                b = numbers[j];
                minRange = abs(a+b-question);
                result.push_back(a+b); // sempre que troca
            }
        }
    }
    return result;
}

int main () {

    int nNumbers, currentNumber, nQuestions, currentQuestion;
    vector<int> numbers = {}, questions = {};

    /**
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
    */

    numbers = {5 6 8 9};
    questions = {1 2 14 16 18 1000};
    sort(numbers.begin(), numbers.end());


    for (auto question : questions) {
        vector<int> result = solve (numbers, question);
        showResult(result, question);
    }

    return 0;
}