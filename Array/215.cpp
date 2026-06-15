#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> pq; // max heap
    for (int num : nums) {
      pq.push(num);
    }
    for (int i = 1; i < k; i++) {
      pq.pop();
    }
    return pq.top();
  }
};

int main() {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  Solution s;
  int result = s.findKthLargest(nums, k);
  cout << "Kth Largest Element in an Array: " << result << endl;
  return 0;
}