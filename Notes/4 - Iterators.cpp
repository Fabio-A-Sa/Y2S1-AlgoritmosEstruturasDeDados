// Created on November, 2021
// @author: Fábio Araújo de Sá
// Theorical Lecture 5, 04/11/2021, Iterators

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sequentialSearch() {

    vector<int> numbers = {23, 3, 123, 3, 1, 3, 5, 65, 32, 654, 246, 776, 3, 76, 457, 5, 975, 3224, 8, 2, 5, 42, 644, 75, 2, 44, 64};
    vector<int> keys = {1, 2, 3, 4, 5, 6, 7, 8};
    for (auto key : keys) {
        cout << find(numbers.begin(), numbers.end()) << endl;
    }
}

int main () {

    sequentialSearch();
    return 0;
}