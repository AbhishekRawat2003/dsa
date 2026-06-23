// Climb Stairs
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  // // memoization
  //   int climbStairs(int n, vector<int> &dp) {
  //    if (n <= 2)
  //       return n;
  //     if (dp[n] != -1)
  //       return dp[n];
  //     return dp[n] = climbStairs(n - 1,dp) + climbStairs(n - 2,dp);
  //   }

  // Tabulation (efficient than memoization technique.)
  int climbStairs(int n) {
    if (n <= 2)
      return n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
int main() {
  int n = 5;
  Solution s;
  // memoization
  // vector<int> dp(n + 1, -1);
  // int res = s.climbStairs(n, dp);
  // cout << res << endl;

  // Tabulation
  int res = s.climbStairs(n);
  cout << res << endl;

  return 0;
}