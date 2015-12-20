//
// Created by 郑虎 on 2015-12-20.
//

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {

  int n, m;
  std::cin >> n >> m;

  std::vector<int> sizes;
  int size_;
  for (int i = 0; i < n; ++i) {
    std::cin >> size_;
    sizes.push_back(size_);
  }
  std::sort(sizes.rbegin(), sizes.rend());

  for (int i = 0; i < n; ++i) {
    m -= sizes.at(i);
    if (m <= 0) {
      std::cout << i + 1;
      break;
    }
  }

  return 0;
}