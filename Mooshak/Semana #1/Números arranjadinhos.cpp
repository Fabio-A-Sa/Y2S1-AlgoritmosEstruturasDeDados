// Created on 11 November, 2021
// author: Fábio Araújo de Sá, up202007658 

#include <iostream>
using namespace std;

bool match (long int attemp, int sum) {

    int currentSum = 0, digit;
    while (attemp) {
        digit = attemp % 10;
        attemp = attemp / 10;
        currentSum += digit;
    }
    return currentSum == sum;
}

int main() {

    long int number;
    int sum, lines;

    cin >> lines;
    for (int i = 0 ; i < lines ; i++) {
        cin >> number >> sum;
        while (!match(number + 1, sum)) number++;
        cout << number + 1 << endl;
    }

    return 0;
}