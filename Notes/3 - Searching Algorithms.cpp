// Created on November, 2021
// @author: Fábio Araújo de Sá
// Theorical Lecture 5, 04/11/2021, Searching Algorithms

#include <iostream>
#include <vector>
using namespace std;

template <class F>
int linearSearch(vector<F> values, F number) {

    for (int i = 0 ; i < values.size() ; i++ ) {
        if (values[i] == number) return i;
    }
    return -1;
}



int main () {

    for (int i = 0 ; i < 10 ; i++) {
        cout << "Hello World" << endl;
    }
    return 0;
}

