//
// Created by Will on 2/15/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (!n)
            return 0;
        int maxMul, minMul,ans;
        ans = maxMul = minMul = nums[0];
        for (int i = 1; i < n ;i++) {
            int a, b;
            a = maxMul * nums[i];
            b = minMul * nums[i];
            maxMul = max(max(a, b), nums[i]);
            minMul = min(min(a, b), nums[i]);
            ans = max(ans, maxMul);
        }
        return ans;
    }
};
int main() {
    vector<int> nums{-2,3,-4};
    Solution test;
    cout<<test.maxProduct(nums)<<endl;
    return 0;
}