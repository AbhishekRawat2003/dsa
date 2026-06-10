#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums)
{
    if(nums.size() == 0)
        return 0;

    sort(nums.begin(), nums.end());

    int longest = 1;
    int count = 1;

    for(int i = 0; i < nums.size(); i++)
    {
        // Ignore duplicates
        if(nums[i] == nums[i - 1])
        {
            continue;
        }

        // Consecutive sequence
        else if(nums[i] == nums[i - 1] + 1)
        {
            count++;
        }

        // Sequence broken
        else
        {
            count = 1;
        }

        longest = max(longest, count);
    }

    return longest;
}

int main()
{
    // vector<int> nums = {1,0,1,2};
    // vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    // vector<int> nums = {100, 4, 200, 1, 3, 2};
    vector<int> nums = {1, 2, 6, 7, 8};

    int result = longestConsecutive(nums);

    cout << "RESULT: " << result << endl;

    return 0;
}
// TC: O(n log n)

// 👇 optimal solution

// #include <iostream>
// #include <vector>
// #include <unordered_set>

// using namespace std;

// int longestConsecutive(vector<int>& nums)
// {
//     unordered_set<int> st(nums.begin(), nums.end());

//     int longest = 0;

//     for(int num : st)
//     {
//         // Start of sequence
//         if(st.find(num - 1) == st.end())
//         {
//             int currentNum = num;
//             int count = 1;

//             while(st.find(currentNum + 1) != st.end())
//             {
//                 currentNum++;
//                 count++;
//             }

//             longest = max(longest, count);
//         }
//     }

//     return longest;
// }

// int main()
// {
//     vector<int> nums = {100,4,200,1,3,2};

//     cout << longestConsecutive(nums);

//     return 0;
// }