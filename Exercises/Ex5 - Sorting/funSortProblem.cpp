#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}

template<class F>
void swapElements(F &p1, F &p2) {
    F temp = p1;
    p1 = p2;
    p2 = temp;
}

void showVector(vector<unsigned> v) {
    for (auto number : v) cout << number << " ";
    cout << endl;
}

void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {

    if (products.size() > k) {

        // Sort vector based on Selection Sort Algorithm and operator < implemented in class Product
        for (int i = 0 ; i < products.size() ; i++ ) {
            int min = i;
            for (int j = i+1 ; j < products.size() ; j++ ) {
                if (products[j] < products[min]) min = j;
            }
            swapElements(products[i], products[min]);
        }

        // Buy all first k products
        products.erase(products.begin() + k, products.end());
    }
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {

    if (values.size() >= nc) {

        // Sorting chocolate vector using Selection Sort Algorithm
        vector<unsigned> v = values;

        for (int i = 0 ; i < v.size() ; i++ ) {
            int min = i;
            for (int j = i+1 ; j < v.size() ; j++ ) {
                if (v[j] < v[min]) min = j;
            }
            swapElements(v[i], v[min]);
        }

        // Get minimum difference in [i,i+nc]
        int minDiff = INT_MAX, currentDiff;
        for (int i = 0 ; i < v.size() - nc + 1; i++) {
            currentDiff = v[i+nc-1] - v[i];
            if (currentDiff < minDiff) minDiff = currentDiff;
        }
        return minDiff;

    } else return -1;

    // Time complexity: O(n^2)
    // Space complexity: O(n), clone of initial vector to swap values if necessary
}

// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    return 0;
}


// TODO

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

}

