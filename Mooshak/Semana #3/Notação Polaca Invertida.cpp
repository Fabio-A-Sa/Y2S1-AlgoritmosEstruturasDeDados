// Created on 23 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int calculator (int a, int b, char operation) {

    switch (operation) {
        case '+': return a+b;
        case '-': return a-b;
        case '/': return a/b;
        case '*': return a*b;
        default: return 0;
    }
}

void solve (const vector<string> &expression) {

    stack<int> numbers = {};

    for (string c : expression) {

        bool isNumber = true;
        for (char digit : c) {
            isNumber &= isdigit(digit);
        }

        if (isNumber) {
            numbers.push(stoi(c)); // char to int using ASCII code :)

        } else {
            if (numbers.size() > 1) {
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                int result = calculator(a, b, c[0]);
                numbers.push(result);
            } else {
                cout << "Expressao Incorrecta" << endl;
                return;
            }
        }
    }
    if (numbers.size() == 1) {
        cout << numbers.top() << endl;
    } else {
        cout << "Expressao Incorrecta" << endl;
    }
}

int main () {

    int loops;
    string currentExpression;
    vector<string> expression;
    cin >> loops;
    cin.ignore(1000, '\n');

    for (int i = 0 ; i < loops ; i++) {
        getline(cin, currentExpression);
        string currentElement = "";
        for (char c : currentExpression) {

            if (c != ' ') currentElement += c;
            else {
                expression.push_back(currentElement);
                currentElement = "";
            }
        }
        expression.push_back(currentElement);
        solve(expression);
        expression.clear();
    }

    return 0;
}