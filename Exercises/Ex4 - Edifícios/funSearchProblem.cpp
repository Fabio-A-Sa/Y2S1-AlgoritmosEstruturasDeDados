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

// TODO
int FunSearchProblem::squareR(int num) {
    return 0;
}

// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    return 0;
}

// TODO
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    return 0;
}

