// bit manipulation

#include <algorithm>
// #include <bitset>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
  //   string conversion(int a) {
  //     string s = "";
  //     while (a > 0) {
  //       int rem = a % 2;
  //       s.push_back(rem + '0');
  //       a /= 2;
  //     }
  //     while (s.size() < 16) {
  //       s.push_back('0');
  //     }
  //     reverse(s.begin(), s.end());
  //     return s;
  //   }

  //   string Negativeconversion(int a) {
  //     a = abs(a);
  //     string s = "";
  //     while (a > 0) {
  //       int rem = a % 2;
  //       s.push_back(rem + '0');
  //       a /= 2;
  //     }
  //     while (s.size() < 16) {
  //       s.push_back('0');
  //     }
  //     reverse(s.begin(), s.end());

  //     // 1's complement
  //     for (int i = 0; i < s.size(); i++) {
  //       s[i] = (s[i] == '0') ? '1' : '0';
  //     }
  //     // 2's complement (add 1)
  //     for (int i = s.size() - 1; i >= 0; i--) {
  //       if (s[i] == '0') {
  //         s[i] = '1';
  //         break;
  //       } else {
  //         s[i] = '0';
  //       }
  //     }
  //     return s;
  //   }
  //   int Binarytodecimal(string result) {
  //     int n = result.length();

  //     // If MSB is 1, it's a negative number in two's complement
  //     if (result[0] == '1') {
  //         // Convert back: invert bits, add 1, negate
  //         string temp = result;
  //         for (int i = 0; i < n; i++) {
  //             temp[i] = (temp[i] == '0') ? '1' : '0';
  //         }
  //         // add 1
  //         for (int i = n - 1; i >= 0; i--) {
  //             if (temp[i] == '0') {
  //                 temp[i] = '1';
  //                 break;
  //             } else {
  //                 temp[i] = '0';
  //             }
  //         }
  //         int magnitude = 0;
  //         for (int i = 0; i < n; i++) {
  //             magnitude = magnitude * 2 + (temp[i] - '0');
  //         }
  //         return -magnitude;
  //     }

  //     // Positive number — straightforward shift-and-add
  //     int res = 0;
  //     for (int i = 0; i < n; i++) {
  //         res = res * 2 + (result[i] - '0');
  //     }
  //     return res;
  // }
  //   int getSum(int a, int b) {
  //     string stringA = (a < 0) ? Negativeconversion(a) : conversion(a);
  //     string stringB = (b < 0) ? Negativeconversion(b) : conversion(b);

  //     cout << "A = " << stringA << endl;
  //     cout << "B = " << stringB << endl;

  //     int n = stringA.length();
  //     string result(n, '0');
  //     int carry = 0;

  //     // Add right to left (LSB to MSB)
  //     for (int i = n - 1; i >= 0; i--) {
  //       int bitA = stringA[i] - '0';
  //       int bitB = stringB[i] - '0';
  //       int sum = bitA + bitB + carry;

  //       result[i] = (sum % 2) + '0';
  //       carry = sum / 2;
  //     }
  //     // Note: final carry is discarded (16-bit overflow wraps around,
  //     // same as real two's-complement fixed-width arithmetic)
  //     int res = Binarytodecimal(result);
  //     return res;
  //   }

  // // or
  int getSum(int a, int b) {
    if (b == 0) return a;
    int sum = a^b;
    int carry = (a&b)<<1;
    return getSum(sum, carry);
    
  }
};

int main() {
  int a = -12;
  int b = -18;
  Solution s;
  int result = s.getSum(a, b);
  cout << result << endl;
  return 0;
}