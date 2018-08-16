#include "List.h"

#include <gtest/gtest.h>

class TestList : public ::testing::Test {
 public:
  TestList() {
    // runs before each unit test
    list = new List();
  }

  ~TestList() {
    // runs after each unit test completes
    delete list;
  }

 protected:
  List* list;
};

TEST_F(TestList, TestAdd) {
  ASSERT_EQ(0, list->count());
  list->add(1);
  ASSERT_EQ(1, list->count());
  list->add(2);
  ASSERT_EQ(2, list->count());
}

TEST_F(TestList, TestRemove) {
  list->add(1);
  ASSERT_EQ(1, list->count());
  list->remove(0);
  ASSERT_EQ(0, list->count());
}

TEST_F(TestList, TestGet) {
  list->add(1);
  list->add(2);

  ASSERT_EQ(2, list->count());
  EXPECT_EQ(1, list->get(0));
  EXPECT_EQ(2, list->get(1));
}

TEST_F(TestList, TestRemoveEmpty) {
  ASSERT_EQ(0, list->count());
  EXPECT_THROW(list->remove(0), std::runtime_error);
  ASSERT_EQ(0, list->count());
}

TEST_F(TestList, TestRemoveBadIndex) {
  list->add(1);
  ASSERT_EQ(1, list->count());
  EXPECT_THROW(list->remove(2), std::runtime_error);
  ASSERT_EQ(1, list->count());
}

TEST_F(TestList, TestInsertNotEmpty) {
  list->add(1);
  list->add(2);
  list->insert(3, 1);

  ASSERT_EQ(3, list->count());
  EXPECT_EQ(1, list->get(0));
  EXPECT_EQ(3, list->get(1));
  EXPECT_EQ(2, list->get(2));
}

TEST_F(TestList, TestInsertEmpty) {
  EXPECT_THROW(list->insert(1, 0), std::runtime_error);

  ASSERT_EQ(0, list->count());
}

TEST_F(TestList, TestInsertBadIndex) {
  list->add(1);
  list->add(2);
  EXPECT_THROW(list->insert(3, 4), std::runtime_error);

  ASSERT_EQ(2, list->count());
  EXPECT_EQ(1, list->get(0));
  EXPECT_EQ(2, list->get(1));
}
