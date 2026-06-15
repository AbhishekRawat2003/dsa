#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>

int main()
{
    vector<int> nums = {3, 2, 3,2,2};
    int num = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < num; i++)
    {
        mp[nums[i]]++;
    }
    int majorityElement = -1;
    for (auto it : mp)
    {
        if (it.second > num / 2)
        {
            majorityElement = it.first;
            break;
        }
    }
    cout << majorityElement << endl;
    // for(int i=0; i<num; i++)
    // {
    //     int count = 0;
    //     for(int j=0; j<num; j++)
    //     {
    //         if(nums[i] == nums[j])
    //         {
    //             count++;
    //         }
    //     }
    //     if(count > num/2)
    //     {
    //         cout << nums[i] << endl;
    //         break;
    //     }
    // }
}