// 3Sum

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  set<vector<int>> uniqueTriplets;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      for (int k = j + 1; k < nums.size(); k++) {

        if (nums[i] + nums[j] + nums[k] == 0) {

          vector<int> triplet = {nums[i], nums[j], nums[k]};

          sort(triplet.begin(), triplet.end());

          uniqueTriplets.insert(triplet);
        }
      }
    }
  }

  for (auto triplet : uniqueTriplets) {
    for (int num : triplet) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}