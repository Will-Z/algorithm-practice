//
// Created by Will on 2/15/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return true;
        int reach = 0;
        for (int i = 0; i < n; i++) {
            if (i <= reach) {
                reach = max(reach, i + nums[i]);
                if (reach == n - 1)
                    return true;
            }
            else
                return false;
        }
    }
};

int main() {
    vector<int> nums{3,2,1,0,4};
    Solution test;
    cout<<test.canJump(nums);
    return 0;
}