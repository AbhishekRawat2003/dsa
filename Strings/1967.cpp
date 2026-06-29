#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  int maximunStrings(vector<string> pattern, string word) {
    int ans = 0;
    for (int i = 0; i < pattern.size(); i++) {
      if (word.find(pattern[i])!= string::npos)
        ans++;
    }

    return ans;
  }
};

int main() {
  vector<string> pattern = {"a", "ab", "abc", "d"};
  string word = "abc";
  Solution s;
  int res = s.maximunStrings(pattern, word);
  cout << res << endl;
  return 0;
}
