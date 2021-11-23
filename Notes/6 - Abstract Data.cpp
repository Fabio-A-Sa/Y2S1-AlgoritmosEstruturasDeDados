// Created on November, 2021
// @author: Fábio Araújo de Sá

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>

using namespace std;

void Arrays() {

    cout << "Arrays:" << endl;
    char name[] = {'F', 'E', 'U', 'P'};
    for (auto letter : name) cout << letter;
    cout << endl;
}

void Lists() {

    cout << "Lists:" << endl;
    list<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto number : numbers) cout << number << " ";
    cout << endl;
}

void Stack() {

    cout << "Stack:" << endl;
    stack<int> numbers = {};
    cout << "Input:" << endl;
    for (int i = 0 ; i < 10 ; i++) {
        cout << i << " ";
        numbers.push(i);
    }
    
    cout << end << "Output:" << endl;
    while (!numbers.empty()) {
        cout << numbers.top() << " ";   // Show header number
        numbers.pop();                  // Erase header number
    }
    cout << endl;

}

void Queues() {

    cout << "Queue:" << endl;
}

int main () {

    Arrays();
    Lists();
    Stack();
    Queues();
    return 0;
}