// 1498. Number of Subsequences That Satisfy the Given Sum Condition

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numSubseq(vector<int> &nums, int target) {
    int count = 0;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int sum = nums[left] + nums[right];
      cout << "sum: " << sum << endl;
      if (nums[left] + nums[right] <= target) {
        count++;
      }
      right--;
    }
    return count;
  }
};
int main() {
  vector<int> nums = {3, 5, 6, 7};
  int target = 9;

  Solution s;
  int result = s.numSubseq(nums, target);
  cout << result << endl;
  return 0;
}