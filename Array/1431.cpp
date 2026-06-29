#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int maxCandies = 0;
    vector<bool> ans;
    for (auto val : candies) {
      maxCandies = max(val, maxCandies);
    }
    for (int i = 0; i < candies.size(); i++) {
      if (candies[i] + extraCandies >= maxCandies) {
        ans.push_back(true);
      } else {
        ans.push_back(false);
      }
    }
    return ans;
  }
};

int main() {
  vector<int> candies = {2, 3, 5, 1, 3};
  int extraCandies = 3;
  Solution s;
  vector<bool> result = s.kidsWithCandies(candies, extraCandies);
  for (auto val : result) {
    cout << val << " ";
  }

  return 0;
}