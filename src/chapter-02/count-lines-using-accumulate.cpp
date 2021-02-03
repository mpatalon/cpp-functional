#include "functional-cpp/chapter-02/count-lines-using-accumulate.h"

#include <numeric>

namespace chapter02 {

int count_lines(const std::string &s) {
  return std::accumulate(
      s.cbegin(), s.cend(), 0, [](int previous_count, char c) {
        return (c != '\n') ? previous_count : previous_count + 1;
      });
}

}  // namespace chapter02
