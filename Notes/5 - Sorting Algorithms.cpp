// Created on November, 2021
// @author: Fábio Araújo de Sá
// Theorical Lecture 6 and 7, 08-11/11/2021, Sorting Algorithms

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

const int MIN_VALUE = 0;
const int MAX_VALUE = 100;
const int LENGTH = 20;

vector<int> getUnsortedVector() {

    vector<int> numbers = {};
    for (int i = 0 ; i < LENGTH ; i++) {
        numbers.push_back(MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE)));
    }
    return numbers;
}

void showVector (vector<int> vector) {
    for (auto number : vector) {
        cout << number << " ";
    }
    cout << endl;
}

void insertionSortRun (vector<int> numbers) {

    cout << "Insertion Sort Algorithm: " << endl;
    showVector(numbers);

    for (int i = 1 ; i < numbers.size() ; i++ ) {
        int temp = numbers[i], j;
        for (j = i ; j > 0 && temp < numbers[j-1] ; j-- ) {
            numbers[j] = numbers[j-1];
        }
        numbers[j] = temp;
    }

    showVector(numbers); cout << endl;
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void selectionSortRun (vector<int> numbers) {

    cout << "Selection Sort Algorithm: " << endl;
    showVector(numbers);

    for (int i = 0 ; i < numbers.size() ; i++ ) {
        int min = i;
        for (int j = i+1 ; j < numbers.size() ; j++ ) {
            if (numbers[j] < numbers[min]) min = j;
        }
        int temp = numbers[i];
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }

    showVector(numbers); cout << endl;
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void bubbleSortRun (vector<int> numbers) {

    cout << "Bubble Sort Algorithm: " << endl;
    showVector(numbers);

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

    showVector(numbers); cout << endl;
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void shellSortRun (vector<int> numbers) {

    cout << "Shell Sort Algorithm: " << endl;
    showVector(numbers);

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
    showVector(numbers); cout << endl;
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void merge(vector <int> &v, vector<int> &tmpArr, int leftPos, int rightPos, int rightEnd) {

    int leftEnd = rightPos - 1, tmpPos = leftPos;
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

    if (left < right){
        int center = (left + right) / 2;
        mergeSort(v, tmpArr, left, center);
        mergeSort(v, tmpArr, center + 1, right);
        merge(v, tmpArr, left, center +1, right);
    }
}

void mergeSortRun(vector <int> v) {

    cout << "Merge Sort Algorithm:" << endl;
    showVector(v);
    vector<int> tmpArr(v.size());
    mergeSort(v, tmpArr, 0, v.size()-1);
    showVector(v); cout << endl;
    // Time complexity: O(n*log(n))
    // Space complexity: O(n)
}

void swap (int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

const int &median3(vector<int> &v, int left, int right){

    int center = (left+right) /2;
    if (v[center] < v[left])
        swap(v[left], v[center]); //swap elements if order incorrect
    if (v[right] < v[left])
        swap(v[left], v[right]); //swap elements if order incorrect
    if (v[right] < v[center])
        swap(v[center], v[right]); //swap elements if order incorrect
    swap(v[center], v[right-1]); //puts pivot in position right-1
    return v[right-1];
}

void quickSort(vector<int> &v, int left, int right){

    if (right-left <= 10) // if small vector, using insertionSortRun(v);

        for (int i = 1 ; i < v.size() ; i++ ) {
            int temp = v[i], j;
            for (j = i ; j > 0 && temp < v[j-1] ; j-- ) {
                v[j] = v[j-1];
            }
            v[j] = temp;
        }

    else {

        int x = median3(v, left, right); // x is the pivot
        int i = left; int j = right-1;
        while (true) {
            while (v[++i] < x) ;
            while (x < v[--j]) ;
            if (i < j)
                swap(v[i], v[j]);
            else break;
        }
        swap(v[i], v[right-1]); //reset pivot
        quickSort(v, left, i-1);
        quickSort(v, i+1, right);
    }
}

void quickSortRun (vector<int> numbers) {

    cout << "Quick Sort Algorithm:" << endl;
    showVector(numbers);
    quickSort(numbers, 0, numbers.size()-1);
    showVector(numbers); cout << endl;
    // Time complexity: O(n*log(n)) or O(n^2) if pivot is minimum value (worst case)
    // Space complexity: O(n) or O(log(n)) in best case
}

void countingSortRun(vector<int> numbers) {

    cout << "Counting Sort Algorithm:" << endl;
    showVector(numbers);

    // Get maximum:
    int maximum = numbers[0];
    for (int i = 1 ; i < numbers.size() ; i++) if (maximum < numbers[i]) maximum = numbers[i];

    // Create an empty vector and fill with number of occurrences/index
    vector<int> count(maximum);
    for (auto number : numbers) count[number] += 1;

    // Create a sorted vector based on index vector
    vector<int> sortedNumbers = {};
    for (int i = 0 ; i <= maximum ; i++) {
        while (count[i]) {
            sortedNumbers.push_back(i);
            count[i]--;
        }
    }
    showVector(sortedNumbers); cout << endl;
    // Time complexity: O(n+k), k is the maximum element
    // Space complexity: O(k), k is the maximum element
}

void STLSortRun(vector<int> vector) {

    cout << "STL Sort():" << endl;
    showVector(vector);
    sort(vector.begin(), vector.end());
    showVector(vector); cout << endl;
}

int main () {

    srand(time(NULL));

    // Test sorting comparative based algorithms
    insertionSortRun(getUnsortedVector());
    selectionSortRun(getUnsortedVector());
    bubbleSortRun(getUnsortedVector());
    shellSortRun(getUnsortedVector());
    mergeSortRun(getUnsortedVector());
    quickSortRun(getUnsortedVector());

    // Using STL algorithm: IntroSort() = (QuickSort + HeapSort) + InsertionSort
    STLSortRun(getUnsortedVector());

    // Test sorting non-comparative based algorithms
    countingSortRun(getUnsortedVector());

    return 0;
}