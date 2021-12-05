#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>

std::vector<int> get_input();

int main() {
  auto data = get_input();

  std::map<int, int> grid;
  for (size_t i = 0; i < 1000; ++i) {
    grid[i] = 0;
  }

  for (size_t i = 0; i < data.size() - 5; i += 4) {
    int st = data[i], nd = data[i + 1], rd = data[i + 2], th = data[i + 3];
    if (st == rd) {
      int start = std::min(nd, th);
      int end = std::max(nd, th);
      while (start <= end) {
        ++grid[st + start * 1000];
        ++start;
      }
    }
    if (nd == th) {
      int start = std::min(st, rd) + 1000 * nd;
      int end = std::max(st, rd) + 1000 * nd;
      while (start <= end) {
        ++grid[start];
        ++start;
      }
    }
  }

  int answer = 0;
  for (const auto &[key, value] : grid) {
    if (value >= 2) ++answer;
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
    std::string number_str;
    for (size_t i = 0; i < data.size(); ++i) {
      if (std::isdigit(data[i])) number_str.push_back(data[i]);
      if (data[i] == ',') {
        lines.push_back(std::stoi(number_str));
        number_str = "";
      }
      if (data[i] == ' ' && data[i - 1] == '>') {
        lines.push_back(std::stoi(number_str));
        number_str = "";
      }
      if (i == data.size() - 1) {
        lines.push_back(std::stoi(number_str));
        number_str = "";
      }
    }
  }

  return lines;
}
