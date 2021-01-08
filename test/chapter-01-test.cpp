#include <gtest/gtest.h>
#include <functional-cpp/chapter-01/count-lines-stdcount.h>
#include <functional-cpp/chapter-01/count-lines-transform.h>

TEST(chapter_01_test, EmptyListTest) {
  ASSERT_TRUE(chapter01::cls::count_lines_in_files({}).empty());
  ASSERT_TRUE(chapter01::clt::count_lines_in_files({}).empty());
}

TEST(chapter_01_test, CompareResultTest) {
  ASSERT_EQ(chapter01::cls::count_lines_in_files({"chapter-01-test.cpp"}),
            chapter01::clt::count_lines_in_files({"chapter-01-test.cpp"}));
}
