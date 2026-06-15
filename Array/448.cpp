#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int num : nums)
    {
        mp[num]++;
    }
    for (int i = 1; i <= nums.size(); i++)
    {
        if (mp[i] == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1, 7};
    vector<int> ans = findDisappearedNumbers(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}