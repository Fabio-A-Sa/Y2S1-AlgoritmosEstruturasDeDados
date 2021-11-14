// Created on 11 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int NUM_CASAS = 18;

int sume(long long int attemp) {

    int currentSum = 0, digit;
    while (attemp) {
        digit = attemp % 10;
        attemp = attemp / 10;
        currentSum += digit;
    }
    return currentSum;
}

void showVector(vector<int> digits) {
    for (auto digit : digits) cout << digit << " ";
    cout << endl;
}

void solve (long long int num, int sum) {

    vector<int> digits(NUM_CASAS);
    int casa = digits.size() - 1, digit;
    int currentSum = 0;

    while (sume(num) > sum) num++;
    while (num) {           // Cuidado: tem de ser um número maior
        digit = num % 10;
        digits[casa] = digit;
        casa--;
        num = num / 10;
        currentSum += digit;
    }


    casa = digits.size() - 1;
    int sobra = sum - currentSum;

    while (sobra) {

        int possivel = 9 - digits[casa]; // possível --> o que falta para preencher a casa
        if (sobra >= possivel) {
            digits[casa] += possivel;
            sobra -= possivel;
        } else {
            digits[casa] += sobra;
            sobra = 0;
        }
        casa--;
    }

    long long int result = 0;
    int index = digits.size() - 1;
    int exponent = 0;
    while (index) {
        result = result + digits[index] * pow(10, exponent);
        index--;
        exponent++;
    }
    cout << result << endl;

}

int main() {

    /**

    long int number;
    int sum, lines;

    cin >> lines;
    for (int i = 0 ; i < lines ; i++) {
        cin >> number >> sum;
        cout << solve(number, sum) << endl;
    }
          *
     */
    solve(100000599988, 50); cout << endl;
    solve(100000599989, 50); cout << endl;
    solve(100000599998, 50); cout << endl;
    solve(987654321098, 100); cout << endl;
    solve(12121678909876, 42); cout << endl;
    solve(12121128909876, 42); cout << endl;
    solve(1, 92); cout << endl;

    return 0;
}