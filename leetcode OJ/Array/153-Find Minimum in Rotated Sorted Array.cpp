//
// Created by Will on 2/16/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int ans = nums[0];
        for (int i = 0; i < n; i++)
            if(nums[i] < ans)
                ans = nums[i];
        return ans;
    }
};

int main() {
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    Solution test;
    cout<<test.findMin(nums);
    return 0;
}