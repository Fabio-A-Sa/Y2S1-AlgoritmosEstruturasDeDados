#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Matrix {

    int rows;
    int columns;
    vector<vector<int>> matrix;

    public:

        Matrix(int rows, int columns, int valueK) {
            this->rows = rows;
            this->columns = columns;
            this->matrix = vector<vector<int>(rows, k)>(columns);
        }

};

class C1 {

    int value;

    public:
        C1(int value);
};

int main () {
    C1 c;
    return 0;
}
