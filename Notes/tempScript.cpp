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

    string answer = numbers.empty() ? "empty" : "not empty"; cout << answer << endl;

    while (numbers.size() != requestedSize) {
        numbers.insert(rand() % 20);
    }
    showContent(numbers);
}

void multisetRandomFill(multiset<int> &numbers , int requestedSize) {

    string answer = numbers.empty() ? "empty" : "not empty"; cout << answer << endl;

    while (numbers.size() != requestedSize) {
        numbers.insert(rand() % 20);
    }
    showContent(numbers);
}

void exists(const set<int> &numbers, int attemp) {
    string answer = numbers.find(attemp) != numbers.end() ? "O número " + to_string(attemp) + " existe no conjunto!" :
                                                                "O número " + to_string(attemp) + " não existe no conjunto!";
    cout << answer << endl; return;
}

int main () {

    srand(time(NULL));
    set<int> numbers1;
    multiset<int> numbers2;

    setRandomFill(numbers1, 10); // 0, 1, 3, 5, 6, 7, 9, 13, 16, 18
    multisetRandomFill(numbers2, 10); // 2, 7, 8, 10, 10, 14, 14, 14, 15, 18

    exists(numbers1, 13); // O número 13 existe no conjunto!
    exists(numbers2, 10); // 

    //eraseElement(numbers1, 18);
    //eraseElementByPosition(numbers1, 3);

    return 0;
}