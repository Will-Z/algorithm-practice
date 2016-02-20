//
// Created by Will on 2/3/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1,vector<int>());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            int n = ans.size();
            for (int j = 0; j < n; j++) {
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
        }
        return ans;
    }
};
int main(){
    vector<vector<int>> v;
    int a[] = {1, 2, 3};
    vector<int> nums;
    Solution test;
    v = test.subsets(nums);
    for (int i = 0; i < v.size(); i++){
        if (!v[i].size())
            cout<<"[]";
        else
            for (int j = 0; j < v[i].size(); j++)
                cout<<v[i][j]<<"    ";
        cout<<endl;
    }
    return 0;
}
