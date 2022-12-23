#include <iostream>

using namespace std;

// https://projecteuler.net/problem=1
// Best solution for this task is Gauss summation formula
int task1() {
  const int num = 999;
  int th = num / 3;
  int fi = num / 5;
  int fif = num / 15;
  return 0.5 * (3 * th * (th + 1) + 5 * fi * (fi + 1) - 15 * fif * (fif + 1));
}

int main() {}