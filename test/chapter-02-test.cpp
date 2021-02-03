#include <gtest/gtest.h>
#include <functional-cpp/chapter-02/average-score.h>
#include <functional-cpp/chapter-02/count-lines-using-accumulate.h>
#include <functional-cpp/chapter-02/move-selected.h>
#include <functional-cpp/chapter-02/filter-and-transform-combined.h>
#include <functional-cpp/common/person.h>

namespace {}  // namespace

TEST(chapter_02_test, AverageScoreTest) {
  ASSERT_EQ(2.5, chapter02::average_score({1, 2, 3, 4}));
}

TEST(chapter_02_test, ScoresProductTest) {
  ASSERT_EQ(24.0, chapter02::scores_product({1, 2, 3, 4}));
}

TEST(chapter_02_test, CountLinesUsingAccumulateTest) {
  ASSERT_EQ(3, chapter02::count_lines("an ancient pond \n"
                                      "a frog jumps in \n"
                                      "the splash of water\n"));
}

TEST(chapter_02_test, MoveSelectedTest) {
  std::vector<chapter02::list_item> input{{"David", true},   {"Jane", false},
                                          {"Martha", false}, {"Peter", false},
                                          {"Rose", true},    {"Tom", true}};
  chapter02::move_selected_to(input.begin(), input.end(), input.begin() + 3);

  std::vector<chapter02::list_item> output{{"Jane", false}, {"Martha", false},
                                           {"David", true}, {"Rose", true},
                                           {"Tom", true},   {"Peter", false}};
  ASSERT_EQ(output, input);
}

TEST(chapter_02_test, NamesForTest) {
  std::vector<person_t> input{
      {"David", person_t::male},    {"Jane", person_t::female},
      {"Martha", person_t::female}, {"Peter", person_t::male},
      {"Rose", person_t::female},   {"Tom", person_t::male}};

#ifdef USE_TAIL_RECURSIVE_IMPLEMENTATION
  auto names =
      chapter02::names_for(input.begin(), input.end(), chapter02::is_female);
#else
  auto names = chapter02::names_for(input, chapter02::is_female);
#endif

  std::vector<std::string> output{"Jane", "Martha", "Rose"};
  ASSERT_EQ(output, names);
}
