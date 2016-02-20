//
// Created by Will on 2/7/16.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (!nums.size())
            return 0;
        if (target < nums[0])
            return 0;
        if (target > nums[nums.size() - 1])
            return nums.size();

        for (int i = 0; i <= nums.size() - 1; i++)
            if (nums[i] == target)
                return i;
        for (int i = 0; i <= nums.size() - 2; i++) {
            if (target > nums[i] && target < nums[i + 1])
                return i + 1;
        }
    }
};

int main() {
    int a[] = {1,3,5,7};
    vector<int> nums(a, a + 4);
    Solution test;
    cout<<test.searchInsert(nums, 8)<<endl;
    return 0;
}