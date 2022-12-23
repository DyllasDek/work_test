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

 
// https://projecteuler.net/problem=2
// Solved without memorizing all the Fibonacci numbers (without DP). The time complexity limit is O(n)
long long task2(long long n){
  if (n < 2) return 0ll;
  long long fib1 = 1ll;
  long long fib2 = 1ll;
  long long fib3 = 2ll;
  // as we assume that first 2 elements are 1
  long long sum = -1ll;
  while(fib1 <= n){
    sum += fib1 + fib2;
    
    fib1 = fib2 + fib3;
    fib2 = fib1 + fib3;
    fib3 = fib1 + fib2;
  }
  return sum;
}


int main() {}