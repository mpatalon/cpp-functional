
#include "functional-cpp/chapter-01/count-lines-stdcount.h"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <iterator>

namespace chapter01 {
namespace cls {

/**
 * This function opens a file specified by the filename argument,
 * and counts the number of lines in said file
 */
int count_lines(const std::string &filename) {
  std::ifstream in(filename);
  in.unsetf(std::ios_base::skipws);

  // We are creating an iterator over the input stream and
  // passing it to the count algorithm to count the number
  // of newline characters
  return std::count(std::istream_iterator<char>(in),
                    std::istream_iterator<char>(), '\n');
}

/**
 * Given a list of files, this function returns a list of
 * line counts for each of them
 */
std::vector<int> count_lines_in_files(const std::vector<std::string> &files) {
  std::vector<int> results;

  for (const auto &file : files) {
    results.push_back(count_lines(file));
  }

  return results;
}

}  // namespace cls
}  // namespace chapter01
