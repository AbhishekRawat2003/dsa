// Valid Sudoku
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool isValidsudoku(vector<vector<int>> nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      unordered_set<int> row;
      unordered_set<int> col;
      for (int j = 0; j < n; j++) {
        // row
        if (nums[i][j] != 0) {
          if (row.count(nums[i][j])) {
            return false;
          }
          row.insert(nums[i][j]);
        }

        // col
        if (nums[j][i] != 0) {
          if (col.count(nums[j][i])) {
            return false;
          }
          col.insert(nums[j][i]);
        }
      }
    }

    // 3x3 Box
    for (int row = 0; row < n; row += 3) {
      for (int col = 0; col < n; col += 3) {

        unordered_set<int> box;
        for (int i = row; i < row + 3; i++) {
          for (int j = col; j < col + 3; j++) {
            if (nums[i][j] != 0) {

              if (box.count(nums[i][j])) {
                return false;
              }

              box.insert(nums[i][j]);
            }
          }
        }
      }
    }

    return true;
  }
};
int main() {
  vector<vector<int>> nums = {
      {5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
      {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
      {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
      {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
      {0, 0, 0, 0, 8, 0, 0, 7, 9}};
  Solution s;
  bool result = s.isValidsudoku(nums);
  cout << result << endl;
  return 0;
}
