// Created on November, 2021
// @author: Fábio Araújo de Sá

#include <iostream>
#include <algorithm>
#include <exception>
#include <list>
#include <stack>
#include <ctime>
#include <queue>
#include <map>

using namespace std;

class SegmentationFaultException : public exception {
    public:
        SegmentationFaultException();
        void showError();
};

SegmentationFaultException::SegmentationFaultException() {};
void SegmentationFaultException::showError() { cout << "Error. pop() not allowed in empty deque!" << endl; }

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

    if (!numbers.empty()) {
        numbers.pop();
    } else {
        SegmentationFaultException e = SegmentationFaultException();
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
    queue<int> numbers = {};

    if (!numbers.empty()) {
        numbers.pop();
    } else {
        SegmentationFaultException e = SegmentationFaultException();
        e.showError();
    }

    cout << "Input:" << endl;
    for (int i = 0 ; i < 10 ; i++) {
        cout << i << " ";
        numbers.push(i);
    }

    cout << endl << "Output:" << endl;
    while (!numbers.empty()) {
        cout << numbers.front() << " ";     // Show header number
        numbers.pop();                      // Erase header number
    }
    cout << endl;
}

// @Overload
void showContent(const vector<int> &numbers) {
    for (int number : numbers) cout << number << " ";
    cout << endl;
}

// @Overload
void showContent(priority_queue<int> numbers) {
    while (!numbers.empty()) {
        cout << numbers.top() << " ";
        numbers.pop();
    }
    cout << endl;
}

vector<int> getRandomNumbers() {

    vector<int> numbers = {};
    for (int i = 0 ; i < 20 ; i++) numbers.push_back(1 + rand() % 100);
    return numbers;
}

void priorityQueue() {

    vector<int> numbers = getRandomNumbers();
    cout << "\nInitial content: " << endl;
    showContent(numbers);

    priority_queue<int> sortedNumbers;
    for (int number : numbers) sortedNumbers.push(number);

    cout << "\nSorted content: " << endl;
    showContent(sortedNumbers);
}

void verify(const vector<int> &numbers)  {

    cout << "\nVerification:\n" << endl;

    map<int, int> indexNumber = {};
    for (int i = 0 ; i < numbers.size() ; i++) {
        indexNumber.insert(make_pair(i+1, numbers[i]));
    }

    for (int i = 0 ; i < numbers.size() ; i++) {
        int index1 = (i+1)*2;
        int index2 = (i+1)*2+1;
        if (index2 < numbers.size()) {
            cout << "Parent: " << numbers[i] << endl;
            cout << "Child 1: " << numbers[index1-1] << " correct? " << (numbers[index1-1] == indexNumber[index1]) << endl;
            cout << "Child 2: " << numbers[index2-1] << " correct? " << (numbers[index2-1] == indexNumber[index2]) << endl;
            cout << endl;
        }
    }
}

void heapSort() {

    vector<int> numbers = getRandomNumbers();
    cout << "\nInitial content: " << endl;
    showContent(numbers);

    make_heap(numbers.begin(), numbers.end());
    cout << "\nSorted content: " << endl;
    showContent(numbers);
    verify(numbers);
}

int main () {

    srand(time(NULL));
    Arrays();
    Lists();
    Stack();
    Queues();
    priorityQueue();
    heapSort();
    disjointSets();
    return 0;
}