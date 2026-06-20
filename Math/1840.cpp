#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxBuilding(int n, vector<vector<int>> &restrictions) {
    sort(restrictions.begin(), restrictions.end());
    for (auto x : restrictions) {
      cout << x[0] << " " << x[1] << endl;
    }
    int height = 0;
    int maxheight = 0;
    if (n == 0) {
      height++;
      return maxheight;
    }
    
    return 0;
  }
};

int main() {
  //   vector<vector<int>> restrictions = {{2, 1}, {4, 1}};
  vector<vector<int>> restrictions = {{5, 3}, {2, 5}, {7, 4}, {10, 3}};
  int n = 5;
  Solution s;
  int maxBuilding = s.maxBuilding(n, restrictions);
  cout << "maximum possible height of the tallest building: " << maxBuilding
       << endl;
  return 0;
}
