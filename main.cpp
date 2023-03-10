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

// https://projecteuler.net/problem=6
// Sum of square is 1^2 + 2^2 + ... + n^2
// Same as 1/6 * n * (n+1) * (2n+1)
//
// Square of sum is (1 + 2 + ... + n)^2
// Same as 1/4 * n^2 * (n+1)^2
//
// Diff will be:
// 1/12 * n * (n + 1) * (3*n^2 - n - 2)
// task5(100)
long long task5(long long n){
  return n * (n+1) * (3*n*n - n - 2) / 12;
}

//https://projecteuler.net/problem=7
long long task6(){
  int counter = 6;
  long long i = 13;
  while(counter < 10001){
    i++;
    bool prime = 1;
    for (long long j = 2; j*j <= i; j++){
      if (i % j == 0){
        prime = 0;
        break;
      }
    }
    counter += prime;
  }
  return i;
}

// https://projecteuler.net/problem=10
// The best solution would be the sieve of Eratosthenes
long long task7(){
  long long sum = 0;
  vector<int> prime(2e6 + 1, true);
  prime[0] = false;
  prime[1] = false;

  for (int i = 2; i < prime.size(); i++) {
      if (prime[i] && i * i < prime.size()) {
        sum += i;
          for (int j = i * i; j < prime.size(); j += i) {
              prime[j] = false;
          }
      }
  }
  return sum;
}

// https://projecteuler.net/problem=14
long long chain(long long x){
  for (long long i = 1; x > 1; i++){
    if (x%2 == 0) x/=2;
    else x = 3*x + 1;
  }
}

long long task8(){
  long long max_leng = 0, ans = 0;
  for (long long i = 1; i < 1e6) {
    long long temp = chain(i);
    if (temp > max_leng){
      max_leng = temp;
      ans = i;
    }
  }
  return ans;
}

// https://projecteuler.net/problem=15
// Binomial coefficient (2n,n)
long long task9(){
  long long c = 1
  for (int i = 1; i <= n; i++)
    c = c * (n + i) / i;
  return c;
}
// https://projecteuler.net/problem=20
// Task 10: python brute force solution, why not?
//
// import math
// print(sum(map(int, str(math.factorial(100)))))

int main() {}