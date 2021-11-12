// Created on November, 2021
// @author: Fábio Araújo de Sá

#ifndef SRC_FUNSP_H_
#define SRC_FUNSP_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * The class with methods using sequential search and binary search algorithms
 */
class FunSearchProblem {

    public:

        /**
         * A default constructor of class FunSearchProblem. No arguments needed.
         */
        FunSearchProblem();

        /**
         * A function that determines a smallest missing integer positive value in vector
         * @param values a vector of integer numbers passed by reference
         * @return an smallest integer missing number in vector
         */
        static int smallestMissingValue(const vector<int> & values);

        /**
         * A functions that determines the number of buildings facing the sun based on their height
         * @param values a vector of integer numbers (heights) passed by reference
         * @return an integer number of buildings that are facing the sun
         */
        static int facingSun(const vector<int> & values);

        /**
         * A function that returns an integer number that is the square root of a given number, if this number is a perfect
         * square, or an integer approximated number closer to the real square root, using Binary Search algorithm.
         * @param num an integer number passed by value
         * @return a integer square root (total or partial) of a given number
         */
        static int squareR(int num);

        /**
         * A function that returns a minimum pages of a given library based on students distribution
         * using Binary Search algorithm.
         * @param values a vector of integer numbers (number of pages in each book) passed by reference
         * @param numSt an integer number of students available passed by value
         * @return a integer number of minimum pages allocated for each student
         */
        static int minPages(const vector<int> & values, int numSt);
};

#endif