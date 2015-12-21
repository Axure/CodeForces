#include <iostream>

using namespace std;

void raw_solution() {
  int numbers[100000];
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> numbers[i];
  }
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (numbers[i] % numbers[j] == 0 && i != j) {
        count += 1;
      }
    }
  }

  cout << count;
}

int main(int argc, char *argv[]) {

  raw_solution();

  return 0;
}