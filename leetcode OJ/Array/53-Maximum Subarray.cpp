//
// Created by Will on 2/14/16.
//
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        for (int i = 1; i < n; i++)
            if (f[i - 1] + nums[i] > nums[i])
                f[i] = f[i - 1] + nums[i];
            else
                f[i] = nums[i];
        int ans = f[0];
        for (int i = 1; i < n; i++)
            if (f[i] > ans)
                ans = f[i];
        return ans;

    }
};

int main() {
    int a[] = {1};
    vector<int> nums(a, a + 1);
    Solution test;
    cout<<test.maxSubArray(nums);
    return 0;
}