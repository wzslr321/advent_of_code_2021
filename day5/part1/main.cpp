#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>

struct cords {
  int x1;
  int x2;
  int y1;
  int y2;
};

std::vector<cords> get_input();

int main() {
  auto data = get_input();

  std::map<int, int> grid;
  for (size_t i = 0; i < 1000; ++i) {
    grid[i] = 0;
  }

  for (size_t i = 0; i < data.size(); ++i) {
    int st = data[i].x1, nd = data[i].y1, rd = data[i].x2, th = data[i].y2;
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

std::vector<cords> get_input() {
  std::vector<cords> lines;
  while (std::cin) {
    cords c;
    char tmp;
    std::cin >> c.x1;
    if (c.x1 == 997) break;
    std::cin >> tmp >> c.y1 >> tmp >> tmp >> c.x2 >> tmp >> c.y2;
    lines.push_back(c);
  }

  return lines;
}
