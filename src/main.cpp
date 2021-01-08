#include <functional>
#include <iostream>
#include <ranges>
#include <vector>
#include <string>


int main() {
  std::string s;

  std::vector myvector{3, 1, 2, 9, 4, 8, 7, 5, 6};
  for (auto i : myvector) {
    std::cout << i << ' ';
  }

  auto greater_than_five = [](int i) { return i > 5; };
  auto next_number = [](int i) { return i + 1; };

  auto filtered = myvector | std::ranges::views::filter(greater_than_five) |
                  std::views::transform(next_number);

  for (auto i : filtered) {
    std::cout << i << ' ';
  }

  return 0;
}
