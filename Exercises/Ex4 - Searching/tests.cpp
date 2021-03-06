// Created on November, 2021
// @author: Fábio Araújo de Sá

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSearchProblem.h"

using testing::Eq;

TEST(test, facingsun){

    FunSearchProblem problem;
    vector<int> alturas = {12, 3, 45, 45, 56, 23, 89, 10, 100, 25, 67};
    EXPECT_EQ(5, problem.facingSun(alturas));
    alturas = {12, 3, 45, 45, 56, 23, 89, 10, 100, 25, 67, 1002, 1002};
    EXPECT_EQ(6, problem.facingSun(alturas));
}

TEST(test, squareR){

    FunSearchProblem problem;
    EXPECT_EQ(3, problem.squareR(10));
    EXPECT_EQ(10, problem.squareR(102));
    EXPECT_EQ(13, problem.squareR(169));
    EXPECT_EQ(13, problem.squareR(170));
    EXPECT_EQ(0, problem.squareR(-2));
    EXPECT_EQ(2, problem.squareR(8));
    EXPECT_EQ(1, problem.squareR(1));
}

TEST(test, missingvalue){

    FunSearchProblem problem;
    vector<int> numbers;

    numbers = {7, 0, 4, 2, 3, -6, 7, 8, 20, 1, -1, 5};
    EXPECT_EQ(6, problem.smallestMissingValue(numbers));
    numbers.clear();
    EXPECT_EQ(0, problem.smallestMissingValue(numbers));
    numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 14};
    EXPECT_EQ(12, problem.smallestMissingValue(numbers));
    numbers = {-1, 2, 4, 5, 6, 7, 9, 10, 11, 14, 3};
    EXPECT_EQ(1, problem.smallestMissingValue(numbers));
}

TEST(test, minPages){

    FunSearchProblem problem;
    vector<int> numbers;

    numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(10, problem.minPages(numbers, 10));
    numbers = {10, 20, 34, 42, 42, 63, 78, 98, 102, 123};
    EXPECT_EQ(123, problem.minPages(numbers, 9));
    numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(-1, problem.minPages(numbers, 11));
}
