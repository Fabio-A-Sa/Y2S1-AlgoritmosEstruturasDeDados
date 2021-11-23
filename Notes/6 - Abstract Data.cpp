// Created on November, 2021
// @author: Fábio Araújo de Sá

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class SegmentationFaultException : public Exception {
    public:
        SegmentationFaultException();
        void showError();
};

SegmentationFaultException::SegmentationFaultException() {};
void SegmentationFaultException::showError() { cout << "Error. pop() not allowed in empty stack!" << endl; }

void Arrays() {

    cout << endl << "Arrays:" << endl;
    char name[] = {'F', 'E', 'U', 'P'};
    for (auto letter : name) cout << letter;
    cout << endl;
}

void Lists() {

    cout << endl << "Lists:" << endl;
    list<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto number : numbers) cout << number << " ";
    cout << endl;
}

void Stack() {

    cout << endl << "Stack:" << endl;
    stack<int> numbers = {};

    try {
        numbers.pop();
    } catch (SegmentationFaultException e) {
        e.showError();
    }

    cout << "Input:" << endl;
    for (int i = 0 ; i < 10 ; i++) {
        cout << i << " ";
        numbers.push(i);
    }

    cout << endl << "Output:" << endl;
    while (!numbers.empty()) {
        cout << numbers.top() << " ";   // Show header number
        numbers.pop();                  // Erase header number
    }
    cout << endl;
}

void Queues() {

    cout << endl << "Queue:" << endl;
}

int main () {

    Arrays();
    Lists();
    Stack();
    Queues();
    return 0;
}