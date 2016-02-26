//
// Created by Will on 2/14/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0])
            return 0;
        if (nums[n - 1] == n - 1)
            return n;
        for (int i = 0; i < n; i++)
            if (nums[i] != i)
                return i;
    }
};

int main() {
    vector<int> nums{0,1,2,3};
    Solution test;
    cout<<test.missingNumber(nums)<<endl;
    return 0;
}