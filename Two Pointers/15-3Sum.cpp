//
// Created by Will on 1/24/16.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() <= 2)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 1; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            twoSum(nums, i + 1, nums.size() - 1, nums[i]);
        }
        return res;
    }

    void twoSum(vector<int>& nums, int begin, int end, int target) {
        int i, j;
        i = begin;
        j = end;
        while (i < j) {
            if (target + nums[i] + nums[j] == 0) {
                vector<int> v;
                v.push_back(target);
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                res.push_back(v);
                while (i < j && nums[i] == nums[i + 1])
                    i++;
                while (i < j && nums[j] == nums[j - 1])
                    j--;
                i++;
                j--;
            }
            else if(target + nums[i] + nums[j] < 0)
                i++;
            else
                j--;
        }
    }
};

int main() {
    int a[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(a, a+6);
    Solution test;
    vector<vector<int>> res;

    res = test.threeSum(nums);
    for (int i = 0; i <= res.size() - 1; i++) {
        for (int j = 0; j <= res[i].size() - 1; j++)
            cout<<res[i][j]<<"   ";
        cout<<endl;
    }
    return 0;

}