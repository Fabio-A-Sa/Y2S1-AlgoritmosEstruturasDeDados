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
            this->matrix = vector<vector<int>(rows)>(columns);
        }


};

int main () {
    return 0;
}
