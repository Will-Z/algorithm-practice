//
// Created by Will on 1/24/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> res;
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 1; i++) {
            twoSum(nums, i + 1, nums.size() - 1, nums[i], target);
        }
        int ans = res[0];
        for (int i = 1; i <= res.size() - 1; i++)
            if (abs(ans - target) > abs(res[i] - target))
                ans = res[i];
        return ans;
    }

    void twoSum(vector<int>& nums, int begin, int end, int first, int target) {
        int i, j, sum;
        i = begin;
        j = end;
        while (i < j) {
                sum = first + nums[i] + nums[j];
                res.push_back(sum);

                if(sum < target)
                    i++;
                else
                    j--;
        }
    }
};

int main() {
    Solution test;
    int a[] = {13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,
            -9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,
            3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,
            0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6};

    vector<int> nums(a, a+118);
    cout<<test.threeSumClosest(nums, -59);
    return 0;
}