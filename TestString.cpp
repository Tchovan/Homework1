#include "String.h"

#include <gtest/gtest.h>

class TestString : public ::testing::Test {};

TEST_F(TestString, TestEmptyConstructor) {
  String a;

  EXPECT_EQ(0, a.size());
  ASSERT_TRUE(a.ptr() != nullptr);
  EXPECT_STREQ("", a.ptr());
}

TEST_F(TestString, TestConstructor) {
  String a("This is a string");

  EXPECT_EQ(16, a.size());
  ASSERT_TRUE(a.ptr() != nullptr);
  EXPECT_STREQ("This is a string", a.ptr());
}

TEST_F(TestString, TestPartialStringConstructor) {
  String a("This is a string", 5);

  EXPECT_EQ(5, a.size());
  ASSERT_TRUE(a.ptr() != nullptr);
  EXPECT_STREQ("This ", a.ptr());
}

TEST_F(TestString, TestCopyConstructor) {
  String a("This is a string");
  String b(a);

  EXPECT_EQ(16, b.size());
  ASSERT_TRUE(a.ptr() != b.ptr());
  EXPECT_STREQ("This is a string", b.ptr());
}

TEST_F(TestString, TestClear) {
  String a("This is a string");

  a.clear();
  EXPECT_STREQ("", a.ptr());
  EXPECT_EQ(0, a.size());
}

TEST_F(TestString, TestEqualTrue) {
  String a("This is a string");
  String b("This is a string");

  EXPECT_TRUE(a == b);
}

TEST_F(TestString, TestEqualFalse) {
  String a("This is a string");
  String b("This is a different string");

  EXPECT_FALSE(a == b);
}

TEST_F(TestString, TestAssignment) {
  String a("This is a string");
  String b;

  b = a;

  EXPECT_TRUE(a == b);
  EXPECT_TRUE(a.ptr() != b.ptr());
  EXPECT_EQ(16, b.size());
  EXPECT_STREQ("This is a string", b.ptr());
}

TEST_F(TestString, TestConcat) {
  String a;
  a += String("This ");
  a += String("is ");
  a += String("a ");
  a += String("string");

  EXPECT_EQ(16, a.size());
  ASSERT_TRUE(a.ptr() != nullptr);
  EXPECT_STREQ("This is a string", a.ptr());
}

TEST_F(TestString, TestTokenize) {
  String a("This is a string");

  std::vector<String> tokens = a.tokenize(' ');

  ASSERT_EQ(4, tokens.size());
  EXPECT_STREQ("This", tokens[0].ptr());
  EXPECT_STREQ("is", tokens[1].ptr());
  EXPECT_STREQ("a", tokens[2].ptr());
  EXPECT_STREQ("string", tokens[3].ptr());
}

TEST_F(TestString, TestTrim) {
  String a(" Example ");
  String b = a.trim();
  EXPECT_EQ(7, b.size());
  EXPECT_STREQ("Example", b.ptr());
}

TEST_F(TestString, TestTrimAllSpace) {
  String a("    ");
  String b = a.trim();
  EXPECT_EQ(0, b.size());
  EXPECT_STREQ("", b.ptr());
}

TEST_F(TestString, TestTrimEmpty) {
  String a("");
  String b = a.trim();
  EXPECT_EQ(0, b.size());
  EXPECT_STREQ("", b.ptr());
}
