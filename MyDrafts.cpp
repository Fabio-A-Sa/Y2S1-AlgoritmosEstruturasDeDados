// Created on October, 2021

#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

template <class Number>
Number squareRoot (Number n) { return sqrt(n); }

// invariant: em cada iteração, sum = 1+2+…+(k-1)
// variant: n + 1 - k, pois o valor máximo de K será n + 1 e K é incrementado a cada iteração

long sum (int n) {
    long sum = 0;
    int k = 1;
    while (k <= n) {
        sum += k;
        k++;
    }
    return sum;
}

int main () {

    double x = 25.651;
    double result = squareRoot(25.651);
    cout << "\n\nPreconditions and postconditions\n" << endl;
    cout << "X = " << x << endl << "Result = squareRoot(X) = " << result << endl;
    cout << "Preconditions: x >= 0\nPostconditions: result >= 0 && pow(result, 2) == x\n" << endl;

    cout << "Parcial correctness:\n\t- Com as pré-condições correctas, caso o algoritmo termine então está correcto;" << endl;
    cout << "\t- Detetar a invariante do ciclo e provar a veracidade para o início, meio e fim;\n" << endl;
    cout << "Total correctness:\n\t- Com as pré-condições correctas provar que o algoritmo termina;" << endl;
    cout << "\t- Detetar a invariante do ciclo e provar a veracidade para o início, meio e fim;" << endl;
    cout << "\t- Detetar a variante do ciclo e provar que é uma expressão inteira, não-negativa e decrescente;\n\n" << endl;

    return 0;
}

template <class Comparable>
Comparable maxSubSum1(const vector<Comparable> &a)
{
    Comparable maxSum = 0;
    for (int i = 0 ; i < a.size() ; i++)
        for (int j = i; j < a.size(); j++)
        {
            Comparable thisSum = 0;
            for (int k = i; k <= j; k++)
                thisSum += a[k];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    return maxSum;
}

template <class Comparable>
Comparable maxSubSum2(const vector<Comparable> &a)
{
    Comparable maxSum = 0;
    for (int i = 0 ; i < a.size() ; i++)
    {
        Comparable thisSum = 0;
        for (int j = i; j < a.size(); j++)
        {
            thisSum += a[j];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

template <class Comparable>
Comparable maxSubSum3(const vector<Comparable> &a)
{
    Comparable thisSum = 0; Comparable maxSum = 0;
    for (int i=0 ; i < a.size() ; i++ )
    {
        thisSum += a[i];
        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}

int main () {

    srand(time(NULL));
    vector<int> numbers = { -3, 1, -8, 4, -1, 2, 1, -5, 5, -3, 1, 10, 2, 4, 5, -8, 4, -1, 2, 1,
                            -5, 5, -3, 1, -8, 4, -1, 2, 1, -5, 5, -3, 1, -8, 4, -1, 2, 1, -5, 5, -3 };

    time_t t0, t1, t2, t3, t4, t5;
    int a1, a2, a3;

    t0 = time(nullptr);
    a1 = maxSubSum1(numbers);
    t1 = time(nullptr); t1 = t1 - t0;

    t2 = time(nullptr);
    a2 = maxSubSum2(numbers);
    t3 = time(nullptr); t3 = t3 - t2;

    t4 = time(nullptr);
    a3 = maxSubSum3(numbers);
    t5 = time(nullptr); t5 = t5 - t4;

    cout << "\n\nBig-O Notation\n" << endl;
    cout << "First algorithm\nResult = " << a1 << " in " << t1 << " seconds\nTime complexity: O(n^3)\nSpace complexity: 1\n" << endl;
    cout << "Second algorithm\nResult = " << a2 << " in " << t3 << " seconds\nTime complexity: O(n^2)\nSpace complexity: 1\n" << endl;
    cout << "Third algorithm\nResult = " << a3 << " in " << t5 << " seconds\nTime complexity: O(n)\nSpace complexity: 1\n" << endl;

    return 0;
    