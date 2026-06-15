#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;

    for (int num : nums)
    {
        freq[num]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto &it : freq)
    {
        pq.push({it.second, it.first});
    }
    vector<int> result;
    while (k--)
    {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}