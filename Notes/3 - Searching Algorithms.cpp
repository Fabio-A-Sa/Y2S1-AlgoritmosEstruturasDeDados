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

        if (values[middle] < number) {          // Na parte da direita
            left = middle + 1;
        } else if (number < values[middle]) {   // Na parte da esquerda
            right = middle - 1;
        } else {
            return middle;
        }
    }
    return -1;

    // Time complexity: O(log2(n))
    // Space complexity: O(1)
}

template <class F>
int findK (vector<F> &board, F atmost)
{
    int n = board.size();
    int s = 0, painters = 1;
    for (int i = 0; i < n; i++)
    {
        s += board[i];
        if (s > atmost)
        {
            s = board[i];
            painters++;
        }
    }
    return painters;
}

template <class F>
int paintersProblem (F k, vector<F> board) {

    int n = board.size(), s = 0, m = 0;
    for(int i = 0; i < n; i++)
    {
        m = max(m, board[i]);
        s += board[i];
    }
    int low = m, high = s;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int painters = findK(board, mid);
        if (painters <= k) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main () {

    vector<int> numbers = {0, 3, 2, 4, 35, 52, 3, 6, 32, 52, 14, 634, 3, 54, 87, 23, 3, 8, 3, 0, 4, -4, 2, 7, 8, 2};
    cout << "\nTest sequentialSearch() method:" << endl;
    for (int i = 0 ; i < 10 ; i++ ) {
        cout << i << "? " << sequentialSearch(numbers, i) << endl;
    }

    vector<int> sortedNumbers = {0, 4, 6, 7, 12, 45, 67, 89, 133, 245, 246, 467, 6789, 23455};
    vector<int> keys = {3, 7, 12, 245, 246, 247, 890, 23455};
    cout << "\nTest binarySearch() method:" << endl;
    for (auto key : keys) {
        cout << key << "? " << binarySearch(sortedNumbers, key) << endl;
    }

    vector<vector<vector<int>>> input = {
                                            {{2}, {10, 20, 30, 40}},
                                            {{3}, {34, 23, 123, 35, 346, 23, 1, 4, 52, 3262, 3, 213, 4, 1}},
                                            {{3}, {10, 20, 30, 40}},
                                            {{5}, {34, 23, 123, 35, 346, 23, 1, 4, 52, 3262, 3, 213, 4, 1}},
                                            {{2}, {34, 23, 123, 35, 4, 52, 3262, 3, 213, 4, 1}},
                                        };

    cout << "\nTest paintersProblem() method:" << endl;
    for (auto pair : input) {
        cout << paintersProblem (pair[0][0], pair[1]) << endl;
    }

    return 0;
}