//
// Created by Will on 2/17/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if (!candidates.size())
            return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, target, 0, path, ans);
        return ans;
    }
private:
    void dfs(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& ans) {
        if (!target) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target)
                return;
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, path, ans);
            path.pop_back();
        }
    }


};


int main() {
    vector<int> candidates{1,2};
    Solution test;
    vector<vector<int>> ans;
    ans = test.combinationSum(candidates, 7);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j <ans[i].size(); j++)
            cout<<ans[i][j]<<"  ";
        cout<<endl;
    }


    return 0;
}