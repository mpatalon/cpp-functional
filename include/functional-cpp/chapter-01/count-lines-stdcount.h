
#include <string>
#include <vector>

namespace chapter01 {
namespace cls {

/**
 * This function opens a file specified by the filename argument,
 * and counts the number of lines in said file
 */
int count_lines(const std::string &filename);

/**
 * Given a list of files, this function returns a list of
 * line counts for each of them
 */
std::vector<int> count_lines_in_files(const std::vector<std::string> &files);

}  // namespace cls
}  // namespace chapter01
