#include <cctype>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

std::vector<int> get_input();

int main() {
  auto data = get_input();

  std::map<int, int> grid;
  for (size_t i = 0; i < 100; ++i) {
    grid[i] = 0;
  }

  for (size_t i = 0; i < data.size() - 5; i += 4) {
    int st = data[i], nd = data[i + 1], rd = data[i + 2], th = data[i + 3];
    if (st == rd) {
      int start = std::min(nd, th);
      int end = std::max(nd, th);
      while (start <= end) {
        ++grid[st + start * 10];
        ++start;
      }
    }
    if (nd == th) {
      int start = std::min(st, rd) + 10 * nd;
      int end = std::max(st, rd) + 10 * nd;
      while (start <= end) {
        ++grid[start];
        ++start;
      }
    }
  }

  int answer = 0;
  for (const auto &[key, value] : grid) {
    if (value >= 2) ++answer;
    if (key > 0 && key % 10 == 0) std::cout << '\n';
    std::cout << ' ' << value << ' ';
  }

  std::cout << "\nanswer: " << answer << '\n';
  return 0;
}

std::vector<int> get_input() {
  std::vector<int> lines;
  while (std::cin) {
    std::string data;
    std::getline(std::cin, data);
    if (data == "997") break;
    for (size_t i = 0; i < data.size(); ++i) {
      if (std::isdigit(data[i])) lines.push_back(data[i] - 48);
    }
  }

  return lines;
}
