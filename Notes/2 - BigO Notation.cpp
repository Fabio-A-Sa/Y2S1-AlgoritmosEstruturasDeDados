// Created on October, 2021
// @author: Fábio Araújo de Sá
// Theorical Lecture 3, 26/10/2021, BigO Notation

#include <iostream>
#include <vector>
using namespace std;

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
    cout << "\n\nBig-O Notation\n" << endl;
    vector<int> numbers = {-3, 1, -8, 4, -1, 2, 1, -5, 5, -3, 1, 10, 2, 4, 5, -8, 4, -1, 2, 1,
                           -5, 5, -3, 1, -8, 4, -1, 2, 1, -5, 5, -3, 1, -8, 4, -1, 2, 1, -5, 5, -3,
                            1, -8, 4, -1, 2, 1, -5, 5, -3, 1, -8, 4, -1, 2, 1, -5, 5, -3, 1, -8};
    cout << "First algorithm\nResult = " << maxSubSum1(numbers) << "\nTime complexity: O(n^3)\nSpace complexity: n + n + n = 3n\n" << endl;
    cout << "Second algorithm\nResult = " << maxSubSum2(numbers) << "\nTime complexity: O(n^2)\nSpace complexity: n + n = 2n\n" << endl;
    cout << "First algorithm\nResult = " << maxSubSum1(numbers) << "\nTime complexity: O(n)\nSpace complexity: n\n" << endl;
    return 0;
}