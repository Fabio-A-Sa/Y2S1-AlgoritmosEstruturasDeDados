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

    numbers = {0, 1, 2, 3, 4, 6, 7, 8, 20, -4};
    EXPECT_EQ(3, problem.smallestMissingValue(numbers));
    numbers = {-3, 0, 4, 2, 4, 6, 5, 7, 12, -5, 3, 1, 0, 8, 2, 5, 3, 9, 10, 3, 6, 2, 12};
    EXPECT_EQ(11, problem.smallestMissingValue(numbers));

}

TEST(test, minPages){

}
