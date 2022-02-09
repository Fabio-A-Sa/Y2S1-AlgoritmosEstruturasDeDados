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
    cout << endl;
}

// @Overload
void showContent(const multiset<int> &numbers) {
    for (multiset<int>::iterator i = numbers.begin() ; i != numbers.end() ; i++) {
        cout << *i << ", ";
    }
    cout << endl;
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

void multisetRandomFill(multiset<int> &numbers , int requestedSize) {

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
    set<int> numbers1;
    multiset<int> numbers2;

    setRandomFill(numbers1, 10); // 1, 3, 10, 22, 27, 43, 58, 82, 83, 92
    multisetRandomFill(numbers2, 10); // 1, 3, 3, 22, 27, 43, 50, 50, 83, 92

    return 0;
}