// Created on 23 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int calculator(int a, int b, char operation) {

    switch (operation) {
        case '+': return a+b;
        case '-': return a-b;
        case '/': return a/b;
        case '*': return a*b;
        default: return 0;
    }
}

void solve (const vector<char> &expression) {

    stack<int> numbers = {};

    for (char c : expression) {
        if (c != ' ') {

            if (isdigit(c)) {
                numbers.push(c-48); // char to int using ASCII code :)
            } else {
                if (numbers.size() > 1) {
                    int a = numbers.top();
                    numbers.pop();
                    int b = numbers.top();
                    numbers.pop();
                    int result = calculator(a, b, c);
                    numbers.push(result);
                } else {
                    cout << "Expressao Incorrecta" << endl;
                    return;
                }
            }
        }
    }
    cout << numbers.top() << endl;
    numbers.pop();
}

int main () {

    vector<char> expression = {};
    int loops;
    string currentExpression;
    cin >> loops;

    for (int i = 0 ; i < loops ; i++) {
        getline(cin, currentExpression);
        cin.clear();
        cin.ignore(1000, '\n');
        solve(currentExpression);
    }

    return 0;
}