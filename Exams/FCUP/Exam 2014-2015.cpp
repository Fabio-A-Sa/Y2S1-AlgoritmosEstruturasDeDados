#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Rectangle {

    private:
        int x0;
        int y0;
        int x1;
        int y1;

    public:

        Rectangle(int x0, int y0, int x1, int y1) {
            this->x0 = x0;
            this->y0 = y0;
            this->x1 = x1;
            this->y1 = y1;
        }

        int area() {
            return abs(x1-x0) * abs(y1-y0);
        }

        int perimeter() {
            return 2 * (abs(x1-x0) + abs(y1-y0));
        }

        void rotate90() {
            this->x1 = -abs(x1-x0);
            this->y1 = abs(y1-y0);
        }

        int compareTo(Rectangle r) {
            if (this->x0 < r.x0 && this->x1 < r.x1) return 0;
            else if (this->y1 < r.y1 && this->y0 < r.y0) return -1;
            return 1;
        }
};

// Complexity: O(log(n)) --> Binary search
public int binarySearch(int[] values, int val, int left = 0, int right = sizeof(values)/sizeof(values[0])) {

    if (left == right) return left;
    else {
        int middle = (left + (right - left)) / 2;
        if (values[middle] == val) return middle;
        else if (values[middle] < val) return binarySearch(values, val, middle, right);
        return binarySearch(values, val, left, middle);
    }
}

// Complexidade O(n*n) --> menos eficiente que QuickSort, IntroSort, MergeSort, que são todos O(n*log(n))
void minSelectionSort (int[] values) {

    int size = sizeof(values) / sizeof(values[0]);
    for (int i = 1 ; i < size ; i++ ) {
        int temp = values[i], j;
        for (j = i ; j > 0 && temp < values[j-1] ; j-- ) {
            numbers[j] = numbers[j-1];
        }
        numbers[j] = temp;
    }
}

int main () {
    return 0;
}
