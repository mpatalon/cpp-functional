
#include "functional-cpp/chapter-01/count-lines-transform.h"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <iterator>

namespace chapter01 {
namespace clt {

int count_lines(const std::string &filename) {
  std::ifstream in(filename);

  // We are creating an iterator over the input stream and
  // passing it to the count algorithm to count the number
  // of newline characters
  return std::count(std::istream_iterator<char>(in >> std::noskipws),
                    std::istream_iterator<char>(), '\n');
}

std::vector<int> count_lines_in_files(const std::vector<std::string> &files) {
  // Since we know the size of the resulting vector, we can
  // preallocate the needed number of elements
  std::vector<int> results(files.size());

  // Instead of using the raw for loop like in the count-lines-stdcount
  // example, we are using the std::transform algorithm to
  // convert the list of file names into a list of line counts
  std::transform(files.cbegin(), files.cend(), results.begin(), count_lines);

  return results;
}

}  // namespace clt
}  // namespace chapter01
