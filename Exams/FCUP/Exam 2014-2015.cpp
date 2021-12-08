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
};

int main () {


    return 0;
}
