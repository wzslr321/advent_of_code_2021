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
  }

  int ans = INT_MAX;
  // yes, this is really awful and slow solution, but the input is small enough to do in
  // in this lazy way ;/
  for (int i = min; i <= max; ++i) {
    int sum = 0;
    for (int j = 0; j < poss.size(); ++j) {
      for (int y = 1; y <= abs(poss[j] - i); ++y) {
        sum += y;
      }
    }
    ans = std::min(ans, sum);
  }

  std::cout << ans << '\n';
}
