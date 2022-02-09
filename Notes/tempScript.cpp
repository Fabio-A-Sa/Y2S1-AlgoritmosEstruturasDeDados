// Fun with Red Black Trees!

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <ctime>
using namespace std;

// @Overload
void showContent(const set<int> &numbers) {
    for (set<int>::iterator i = numbers.begin() ; i != numbers.end() ; i++) {
        cout << *i << ", ";
    }
}

void setRandomFill(set<int> &numbers , int requestedSize) {

    string answer = numbers.empty() ? "empty" : "not empty";
    cout << answer << endl;

    // fill set with random numbers
    while (numbers.size() != requestedSize) {
        numbers.insert(rand() % 100);
    }
    showContent(numbers); // 1, 3, 10, 22, 27, 43, 58, 82, 83, 92
}

int main () {

    srand(time(NULL));
    set<int> numbers;

    setRandomFill(numbers, 10);

    return 0;
}