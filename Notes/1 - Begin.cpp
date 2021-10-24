#include <iostream>
#include <vector>
using namespace std;

int main () {
    cout << "Hello world!" << endl;
    return 0;
}

long sum (int n)
    long sum = 0;
    int k = 1;
    while (k <= n) {
        sum += k;
        k++;
    }
    return sum;
}