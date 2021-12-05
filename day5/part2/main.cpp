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

  for (size_t i = 0; i < data.size(); ++i) {
    int st = data[i].x1, nd = data[i].y1, rd = data[i].x2, th = data[i].y2;
    int start_y = std::min(nd, th);
    int end_y = std::max(nd, th);
    int start_x = std::min(st, rd);
    int end_x = std::max(st, rd);
    if (st == rd) {
      while (start_y <= end_y) {
        ++grid[st + start_y * 1000];
        ++start_y;
      }
    }
    if (nd == th) {
      while (start_x <= end_x) {
        ++grid[start_x + 1000 * nd];
        ++start_x;
      }
    }
    if (abs(st - rd) == abs(nd - th)) {
      bool st_greater = st > rd;
      bool nd_greater = nd > th;
      if (st_greater) {
        while (st >= rd) {
          ++grid[st + nd * 1000];
          --st;
          if (nd_greater)
            --nd;
          else
            ++nd;
        }
      } else {
        while (st <= rd) {
          ++grid[st + nd * 1000];
          ++st;
          if (nd_greater)
            --nd;
          else
            ++nd;
        }
      }
    }
  }

  int answer = 0;
  for (const auto &[key, value] : grid) {
    if (value >= 2) ++answer;
    if (key % 10 == 0) std::cout << '\n';
    std::cout << value << ' ';
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
