#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  std::vector<int> poss;
  int min = INT_MAX;
  int max = INT_MIN;
  while (std::cin) {
    int n;
    char tmp;
    std::cin >> n >> tmp;
    poss.push_back(n);
    min = std::min(min, n);
    max = std::max(max, n);
    if (tmp == 'x') break;
  }

  int sum = 0;
  int ans = INT_MAX;
  for (int i = min; i <= max; ++i) {
    for (int j = 0; j < poss.size(); ++j) {
      sum += abs(poss[j] - i);
    }
    ans = std::min(ans, sum);
    sum = 0;
  }

  std::cout << ans << '\n';
}
