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

int main () {
    return 0;
}
