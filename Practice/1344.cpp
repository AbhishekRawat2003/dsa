#include <iostream>
using namespace std;
class Solution {
public:
  double angleClock(int hour, int minutes) {
     if (hour == 12) hour = 0;
    double hourAngle = 0.5 * (hour * 60 + minutes);
    double minuteAngle = 6.0 * minutes;
    double diff = abs(hourAngle - minuteAngle);
    return min(diff, 360.0 - diff);
  }
};

int main() {
  int h = 12;
  int min = 30;
  Solution s;
  double result = s.angleClock(h, min);
  cout << result << endl;
  return 0;
}