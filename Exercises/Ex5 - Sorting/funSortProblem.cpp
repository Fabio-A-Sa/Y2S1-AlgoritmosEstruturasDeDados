#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}

void swapProducts(Product &p1, Product &p2) {
    Product temp = p1;
    p1 = p2;
    p2 = temp;
}

void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {

    if (products.size() > k) {

        // Sort vector based on Selection Sort Algorithm and operator < implemented in class Product
        for (int i = 0 ; i < products.size() ; i++ ) {
            int min = i;
            for (int j = i+1 ; j < products.size() ; j++ ) {
                if (products[j] < products[min]) min = j;
            }
            swapProducts(products[i], products[min]);
        }

        // Buy all first k products
        products.erase(products.begin() + k, products.end());
    }
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    return 0;
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    return 0;
}


// TODO

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

}

