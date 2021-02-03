
#include "functional-cpp/chapter-02/average-score.h"

#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

namespace chapter02 {

#if 0
// Imperative version
double average_score(const std::vector<int> &scores) {
  int sum = 0;

  for (int score : scores) {
    sum += score;
  }

  return sum / (double)scores.size();
}

double average_score(const std::vector<int> &scores) {
  return std::accumulate(scores.cbegin(), scores.cend(), 0) /
         (double)scores.size();
}
#endif

double average_score(const std::vector<int> &scores) {
  return std::reduce(std::execution::par, scores.cbegin(), scores.cend(), 0) /
         (double)scores.size();
}

double scores_product(const std::vector<int> &scores) {
  return std::accumulate(scores.cbegin(), scores.cend(), 1,
                         std::multiplies<int>());
}

}  // namespace chapter02
