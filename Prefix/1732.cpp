// 1732. Find the Highest Altitude
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int prefixSum = 0;
    int res = 0;
    for (int i = 0; i < gain.size(); i++) {
      int sum = prefixSum + gain[i];
      prefixSum = sum;
      cout << sum << endl;
      res = max(res, prefixSum);
    }
    // res = max(res, prefixSum);
    return res;
  }
};

int main() {
  vector<int> gain = {-5, 1, 5, 0, -7};
  Solution s;
  int res = s.largestAltitude(gain);
  cout << res << endl;
  return 0;
}