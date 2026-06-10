// sort an array with 0,1,2
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};
    for(int i=0;i<nums.size();i++){
        if(nums[i]>nums[i+1]){
            swap(nums[i],nums[i+1]);
            i=0;
        }
    }

    for(auto val:nums){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}