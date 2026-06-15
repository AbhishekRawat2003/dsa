#include <iostream>
#include <vector>
using namespace std;

vector<int> productOfArrayExceptItself(vector<int> nums)
{
    int n = nums.size();
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                product *= nums[j];
        }
        result.push_back(product);
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = productOfArrayExceptItself(nums);
    for (auto val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}