// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
// Example 2:

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]]

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>>
            minHeap;

        // Distance calculate karke heap mein store karo
        for (auto &point : points)
        {
            int x = point[0];
            int y = point[1];

            int dist = x * x + y * y;

            minHeap.push({dist, point});
        }

        // k closest points nikaalo
        vector<vector<int>> ans;

        while (k--)
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums = {{1, 3}, {-2, 2}};
    int k = 1;
    vector<vector<int>> result = s.kClosest(nums, k);
    for (const auto &row : result)
    {
        cout << "[ ";
        for (int x : row)
        {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
