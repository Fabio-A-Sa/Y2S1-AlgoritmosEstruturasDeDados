#include "funSearchProblem.h"

FunSearchProblem::FunSearchProblem() {}

int FunSearchProblem::facingSun(const vector<int> & values) {

    if (!values.empty()) {
        int result = 1, maxHeight = values[0];
        for (int i = 1 ; i < values.size() ; i++ ) {
            if (maxHeight < values[i]) {
                maxHeight = values[i];
                result++;
            }
        }
        return result;
    }
    return 0;
}

int FunSearchProblem::squareR(int num) {

    if (num > 0) {

        int left = 1, right = num, middle;

        while (right - left > 1) {

            middle = (right + left) / 2;
            if (middle*middle > num) {
                right = middle;
            } else if (middle*middle < num) {
                left = middle;
            } else {
                return middle;
            }
        }
        return left;

    } else {
        cout << "Invalid number" << endl;
        return 0;
    }
}

// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    return 0;
}

// TODO
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    return 0;
}

