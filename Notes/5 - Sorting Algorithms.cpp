// Created on November, 2021
// @author: Fábio Araújo de Sá
// Theorical Lecture 6 and 7, 08-11/11/2021, Sorting Algorithms

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

void showVector (const vector<int> &vector) {
    for (auto number : vector) {
        cout << number << " ";
    }
    cout << endl << endl;
}

void insertionSort (vector<int> numbers) {

    for (int i = 1 ; i < numbers.size() ; i++ ) {
        int temp = numbers[i], j;
        for (j = i ; j > 0 && temp < numbers[j-1] ; j-- ) {
            numbers[j] = numbers[j-1];
        }
        numbers[j] = temp;
    }
    cout << "Insertion Sort: " << endl;
    showVector(numbers);
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void selectionSort (vector<int> numbers) {

    for (int i = 0 ; i < numbers.size() ; i++ ) {
        int min = i;
        for (int j = i+1 ; j < numbers.size() ; j++ ) {
            if (numbers[j] < numbers[min]) min = j;
        }
        int temp = numbers[i];
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }
    cout << "Selection Sort: " << endl;
    showVector(numbers);
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void bubbleSort (vector<int> numbers) {

    bool swap = true;
    while (swap) {
        swap = false;
        for (int i = 0 ; i < numbers.size()-1 ; i++ ) {
            for (int j = i + 1 ; j < numbers.size() ; j++ ) {
                if (numbers[i] > numbers[j]) {
                    int temp = numbers [i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
                    swap = true;
                }
            }
        }
    }
    cout << "Bubble Sort: " << endl;
    showVector(numbers);
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void shellSort (vector<int> numbers) {
    cout
}

int main () {

    srand(time(NULL));
    int min = -5, max = 100, size = 20;
    vector<int> numbers = {};

    // Fill vector with random numbers
    for (int i = 0 ; i < size ; i++) {
        numbers.push_back(min + (rand() % (max - min)));
    }
    cout << "\nInitial vector" << endl; showVector(numbers);

    // Tests
    insertionSort(numbers);
    selectionSort(numbers);
    bubbleSort(numbers);
    shellSort(numbers);

    return 0;
}