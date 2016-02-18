//
// Created by Will on 1/24/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() <= 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 1; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j <= nums.size() - 1; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

               // if(i == 0 && j == 1)
                 //   cout<<"!!!"<<nums[i]<<"   "<<nums[j]<<endl;

                twoSum(nums, j + 1, nums.size() - 1, nums[i], nums[j], target);

            }
        }
        return res;
    }

    void twoSum(vector<int>& nums, int begin, int end, int t1, int t2, int target) {
        int i, j;
        i = begin;
        j = end;
        while (i < j) {
            if (t1 + t2 + nums[i] + nums[j] == target) {
                vector<int> v;
                v.push_back(t1);
                v.push_back(t2);
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
            else if(t1 + t2 + nums[i] + nums[j] < target)
                i++;
            else
                j--;
        }
    }
};
int main() {
    int a[] = {1, 0, -1, 0, -2, 2};
    vector<int> nums(a, a + 6);
    Solution test;
    vector<vector<int>> res;

    res = test.fourSum(nums, 0);


    for (int i = 0; i <= res.size() - 1; i++) {
        for (int j = 0; j <= res[i].size() - 1; j++)
            cout<<res[i][j]<<"   ";
        cout<<endl;
    }
    return 0;

}