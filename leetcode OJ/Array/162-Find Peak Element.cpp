//
// Created by Will on 2/16/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (nums[i + 1] < nums[i])
                    return i;
                continue;
            }
            if (i == n - 1) {
                if (nums[i] > nums[i - 1])
                    return i;
                continue;
            }
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }
    }
};

int main() {
    vector<int> nums{5,4,3};
    Solution test;
    cout<<test.findPeakElement(nums);
    return 0;
}