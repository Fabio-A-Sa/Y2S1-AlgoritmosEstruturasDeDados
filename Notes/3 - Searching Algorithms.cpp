// Created on November, 2021
// @author: Fábio Araújo de Sá
// Theorical Lecture 5, 04/11/2021, Searching Algorithms

#include <iostream>
#include <vector>
using namespace std;

template <class F>
int sequentialSearch(vector<F> values, F number) {

    for (int i = 0 ; i < values.size() ; i++ ) {
        if (values[i] == number) return i;
    }
    return -1;

    // Time complexity: O(n)
    // Space complexity: O(1)
}

template <class F>
int binarySearch(vector<F> values, F number) {

    int left = 0, right = values.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (v[middle] < el)
            left = middle + 1;
        else if (el < v[middle]) right = middle – 1;
        else
            return middle; // found
        }
    }

}

int main () {
    return 0;
}

