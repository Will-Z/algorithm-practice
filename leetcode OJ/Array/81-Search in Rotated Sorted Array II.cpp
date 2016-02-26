//
// Created by Will on 2/9/16.
//
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size())
            return -1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target)
                return i;
        return -1;
    }
};

int main() {
    int a[] = {1};
    vector<int> nums(a,a+1);
    Solution test;
    cout<< test.search(nums, 0);
    return 0;
}