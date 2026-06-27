#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int check(long long num, unordered_map<int, int>& mp) {
        if (!mp.count(num)) {
            return 0;
        }

        long long sq = num * num;
        if (sq > INT_MAX || !mp.count(sq)) {
            int c = mp[num];
            return 1;
        }

        int c = mp[num];
        if (c < 2) {
            return 1;
        }
        return 2 + check(sq, mp);
    }

    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_set<int> seen;

        for (int x : nums) {
            mp[x]++;
            seen.insert(x);
        }

        int maxi = 0;

        if (mp.count(1)) {
            int c = mp[1];
            maxi = (c % 2 != 0) ? c : c - 1;
        }

        for (int x : seen) {
            if (x == 1)
                continue;

            int currentLen = check(x, mp);
            maxi = max(maxi, currentLen);
        }

        return maxi;
    }
};

int main() {
  Solution s;

  vector<int> n1 = {5,4,1,2,2};
  cout << s.maximumLength(n1) << endl;  // expected: 3

  vector<int> n2 = {1,1,1,1,1,1,1,2,4,16};
  cout << s.maximumLength(n2) << endl;  // expected: 7

  vector<int> n3 = {
      995,604,325,556516,409600,34596,780,625681,
      50625,556516,942,942,18496,37,567,18496,
      662,262144,567,38,178084,328329,1874161,990025,
      364816,908209,342102016,15,887364,573,217,150544,
      105625,186,1369,17956,321489,422,217,38,
      105625,225,15,342102016,34596,262144,1369,908209,
      1874161,990025,388,328329,910116,438244,342102016,954,
      321489,608400,37,225,2085136,791,134,134,
      1444,18496,388,325,17956,995,136,791,
      887364,18496,910116,512,409600,422,953,953,
      780,1444,746,662,150544,625681,342102016,640,
      746,573,954,322417936,47089,178084,322417936,608400,
      47089,364816,2085136,136,512,50625,438244,136,
      640,604,186,136};
  cout << s.maximumLength(n3) << endl;  // expected: 5
}