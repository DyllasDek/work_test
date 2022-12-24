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

// https://projecteuler.net/problem=4
/*
Our output between 100 and 999. Palindrome will be between 10000 and 998001.
As we looking for largest one, we assume that our N^2 palindrome will be 6 digits.
So we have:
abccba = 100000a + 10000b + 1000c + 100c + 10b + a =
= 100001a + 10010b + 1100c =
= 11 * (9091a + 910b + 100c)

Now we are looking such X,Y that:
X * Y == 11 * (9091a + 910b + 100c) && X*Y <= 999^2
*/
bool isPal(int x) {
    string s = to_string(x);
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

int task3(){
    int ans = 0;
    for (int X = 990; X >= 100; X-=11){
        for (int Y = 999; Y >= 100; Y--){
            if (X*Y > ans && isPal(X*Y)){ 
                ans = X*Y;
                break;
            } else if (X*Y < ans){
                break;
            }
        }
    }
    return ans;
}

// https://projecteuler.net/problem=5
// The numbers 11-20 are divisible by the numbers 1-10, so we can check only first gap.
long long task4(){
  int ans = 2520;
  bool found = false;
  while(!found){
    ans += 2520;
    bool checked = true;
    for (int j = 11; j < 21; j++){
      if (ans % j !=  0){
        checked = false;
        break;
      }
    }
    if (checked) found = true;
  }

  return ans;
}

int main() {}