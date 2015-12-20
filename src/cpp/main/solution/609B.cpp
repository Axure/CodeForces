//
// Created by 郑虎 on 2015-12-20.
//
#include <iostream>

int main(int argc, char *argv[]) {

  int n, m;
  int book_count[11] = {};
  int index_;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> index_;
    book_count[index_]++;
  }

  int total_count = 0;
  for (int i = 1; i <= 10; ++i) {
    total_count += book_count[i];
  }
  long long result_count = 0;
  for (int i = 1; i <= 10; ++i) {
    result_count += book_count[i] * (total_count - book_count[i]);
  }
  result_count /= 2;
  std::cout << result_count;
  return 0;
}