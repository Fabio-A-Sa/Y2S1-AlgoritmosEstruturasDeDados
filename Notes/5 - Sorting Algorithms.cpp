// Created on November, 2021
// @author: Fábio Araújo de Sá
// Theorical Lecture 6 and 7, 08-11/11/2021, Sorting Algorithms

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

void showVectorRun (const vector<int> &vector) {
    for (auto number : vector) {
        cout << number << " ";
    }
    cout << endl << endl;
}

void insertionSortRun (vector<int> numbers) {

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

void selectionSortRun (vector<int> numbers) {

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

void bubbleSortRun (vector<int> numbers) {

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

void shellSortRun (vector<int> numbers) {

    int j;
    for (int gap = numbers.size() / 2 ; gap > 0 ; gap /= 2) {
        for (int i = gap ; i < numbers.size() ; i++ ) {
            int temp = numbers[i];
            for (j = i ; j >= gap && temp < numbers[j-gap] ; j -= gap) {
                numbers[j] = numbers[j-gap];
            }
            numbers[j] = temp;
        }
    }
    cout << "Shell Sort: " << endl;
    showVector(numbers);
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void merge(vector <int> &v, vector<int> &tmpArr, int leftPos, int rightPos, int rightEnd) {

    int leftEnd = rightPos--, tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    while ( leftPos <= leftEnd && rightPos <= rightEnd )
        if ( v[leftPos] <= v[rightPos] )
            tmpArr[tmpPos++] = v[leftPos++];
        else
            tmpArr[tmpPos++] = v[rightPos++];
    while ( leftPos <= leftEnd )
        tmpArr[tmpPos++] = v[leftPos++];
    while ( rightPos <= rightEnd )
        tmpArr[tmpPos++] = v[rightPos++];
    for ( int i = 0; i < numElements; i++, rightEnd-- )
        v[rightEnd] = tmpArr[rightEnd];
}

void mergeSort(vector <int> &v, vector<int> &tmpArr, int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(v, tmpArr, left, center);
        mergeSort(v, tmpArr, center + 1, right);
        merge(v, tmpArr, left, center +1, right);
    }
}

void mergeSortRun(vector <int> v) {
    vector<int> tmpArr(v.size());
    mergeSort(v, tmpArr, 0, v.size()-1);
    cout << "Merge Sort: " << endl;
    showVector(v);
    // Time complexity: O(n*log(n))
    // Space complexity: O(n)
}

template <class Comparable>
void quickSort(vector<Comparable> &v){
    quickSort(v, 0, v.size()-1);
}

template <class Comparable>
void quickSort(vector<Comparable> &v, int left, int right){
    if (right-left <= 10)
        insertionSort(v, left, right);
    else {
        Comparable x = median3(v, left, right);
        int i = left; int j = right-1;
        for(; ; ) {
            while (v[++i] < x) ;
            while (x < v[--j]) ;
            if (i < j)
                swap(v[i], v[j]);
            else break;
        }
        quickSort(v, left, i-1);
        quickSort(v, i+1, right);
    }
}

void quickSortRun (vector<int> numbers) {

    cout << "Quick Sort: " << endl;
    quickSort(numbers);
    showVector(numbers);
    // Time complexity: O(n*log(n)) or O(n^2) if pivot is maximum
    // Space complexity: O(n) or O(log(n)) in best case
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
    insertionSortRun(numbers);
    selectionSortRun(numbers);
    bubbleSortRun(numbers);
    shellSortRun(numbers);
    mergeSortRun(numbers);
    quickSortRun(numbers);

    return 0;
}