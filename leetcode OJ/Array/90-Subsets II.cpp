//
// Created by Will on 2/5/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans(1, vector<int>());
        sort(nums.begin(), nums.end());
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            int n = ans.size();
            for (int j = 0; j < n; j++) {
                if (i == 0 || nums[i] != nums[i - 1] || j >= pre) {
                    ans.push_back(ans[j]);
                    ans.back().push_back(nums[i]);
                }
            }
            pre = n;
        }
        return ans;
    }
};

int main() {
    int a[] = {1,2,2,2};
    vector<int> nums;
    Solution test;
    vector<vector<int>> ans;
    ans = test.subsetsWithDup(nums);
        for (int i = 0; i < ans.size(); i++) {
            if (!ans[i].size())
                cout<<"[]";
            else
                for (int j = 0; j < ans[i].size(); j++)
                    cout<<ans[i][j]<<"  ";
            cout<<endl;
        }
    return 0;
}