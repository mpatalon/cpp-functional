#include <string>
#include <vector>
#include <algorithm>

namespace chapter02 {

typedef std::pair<std::string, bool> list_item;

bool is_selected(const list_item &item) { return item.second; }

bool is_not_selected(const list_item &item) { return !item.second; }

template <typename It>
void move_selected_to(It first, It last, It destination) {
  std::stable_partition(first, destination, is_not_selected);
  std::stable_partition(destination, last, is_selected);
}

template <typename It>
void move_selected_to2(It first, It destination) {
  std::stable_partition(first, destination, is_not_selected);
}

}  // namespace chapter02
