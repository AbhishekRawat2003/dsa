#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0) {
                bool left = (i == 0 || flowerbed[i - 1] == 0);
                bool right = (i == size - 1 || flowerbed[i + 1] == 0);

                if (left && right) {
                    flowerbed[i] = 1;
                    n--;

                    if (n == 0)
                        return true;
                }
            }
        }

        return n <= 0;
    }
};

int main() {
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    Solution s;
    cout << (s.canPlaceFlowers(flowerbed, n) ? "true" : "false");
}