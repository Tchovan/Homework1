#include "String.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <map>
#include <vector>

class TestContainers : public ::testing::Test {};

TEST_F(TestContainers, TestInsertElements) {
  // start with an empty vector
  std::vector<int> myVec;

  // insert the values 1-10 in order

  EXPECT_THAT(myVec,
              testing::ElementsAreArray({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
}

TEST_F(TestContainers, TestRemove) {
  std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // remove the first 5 elements of myVec

  EXPECT_THAT(myVec, testing::ElementsAreArray({6, 7, 8, 9, 10}));
}

TEST_F(TestContainers, TestRemoveGreaterThan) {
  int src[14] = {-1, 15, 10, 2, 7, 8, 3, 0, 100, -50, 30, 2, 1, 50};

  std::vector<int> myVec;

  // copy the values of src into myVec

  // remove any elements from myVec that are greater than 5

  EXPECT_THAT(myVec, testing::ElementsAreArray({-1, 2, 3, 0, -50, 2, 1}));
}

TEST_F(TestContainers, TestNumberLookup) {
  std::map<int, String> numberToWord{
      {0, "zero"}, {1, "one"}, {2, "two"},   {3, "three"}, {4, "four"},
      {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}};

  std::vector<int> numbers{5, 2, 9, 11, 2, 15, 0};

  // iterate through the numbers vector, and using numberToWord
  // create a string that enumerates them by word
  //(hint: you'll have to use the += operator of the string object,
  // that is the only way you have to concatenate strings together)
  String s;

  EXPECT_STREQ("five,two,nine,not_found,two,not_found,zero", s.ptr());
}

TEST_F(TestContainers, TestSeenCount) {
  std::vector<int> numbers{1, 2, 3, 1, 1, 4, 5, 5, 1, 8, 2, 9};

  std::map<int, int> seen;

  // iterate through the numbers vector, and update the "seen"
  // map so that at the end it has the count of how many times
  // a digit is present in the "numbers" vector

  EXPECT_EQ(4, seen[1]);
  EXPECT_EQ(2, seen[2]);
  EXPECT_EQ(1, seen[3]);
  EXPECT_EQ(1, seen[4]);
  EXPECT_EQ(2, seen[5]);
  EXPECT_EQ(0, seen[6]);
  EXPECT_EQ(0, seen[7]);
  EXPECT_EQ(1, seen[8]);
  EXPECT_EQ(1, seen[9]);
}
