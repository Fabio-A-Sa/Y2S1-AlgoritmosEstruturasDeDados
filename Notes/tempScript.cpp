// Fun with priority queues!

#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

void showContent(priority_queue<int> numbers) {

    while (!numbers.empty()) {
        cout << numbers.top() << ", ";
        numbers.pop();
    }
    cout << endl;
}

void fillContent(priority_queue<int> &numbers, int size) {

    while (numbers.size() < size) {
        int attemp = rand() % 20;
        cout << "Inserindo n = " << attemp << endl;
        numbers.push(attemp);
    }
}

int main () {

    srand(time(NULL));
    priority_queue<int> numbers;
    fillContent(numbers, 10);

    return 0;
}