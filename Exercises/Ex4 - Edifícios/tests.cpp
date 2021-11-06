#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSearchProblem.h"

using testing::Eq;

TEST(test, facingsun){


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

}

TEST(test, minPages){

}
