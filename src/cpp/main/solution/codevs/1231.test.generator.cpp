#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
  ofstream input;
  input.open("1231.1.in.txt");
  int n = 5;
  int m = 10;
  input << n << " " << m << endl;
  srand(time(0));
  for (int i = 1; i <= n - 1; ++i) {
    input << i << " " << i + 1 << " " << (rand() % m) + 1 << endl;
  }
  input << n << " " << 1 << " " << (rand() % m) + 1 << endl;
  for (int i = n + 1; i <= m; ++i) {
    int a = (rand() % n) + 1;
    int b = (rand() % n) + 1;
    while (b == a) {
      b = (rand() % n) + 1;
    }
    input << a << " " << b << " " << (rand() % m) + 1 << endl;
  }

  input.close();


  return 0;
}