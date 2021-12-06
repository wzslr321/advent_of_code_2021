#include <iostream>
#include <vector>

int main() {

  std::vector<int> fishes;
  long long answer = 0LL;
  while (std::cin) {
    int fish;
    char tmp;
    std::cin >> fish >> tmp;
    fishes.push_back(fish);
    ++answer;
    if (tmp == 'x') break;
  }
  for (int y = 0; y < 80; ++y) {
    for (int i = 0; i < fishes.size(); ++i) {
      --fishes[i];
      if (fishes[i] < 0) {
        fishes[i] = 6;
        fishes.push_back(9);
        ++answer;
      }
    }
  }

  std::cout << answer << '\n';

  return 0;
}
