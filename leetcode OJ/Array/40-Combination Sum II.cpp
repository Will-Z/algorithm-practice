//
// Created by Will on 2/17/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if (!candidates.size())
            return ans;

        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, -1, path, ans);


        if (ans.size() >= 1) {
            vector<vector<int>> res;
            vector<int> v;

            sort(ans.begin(), ans.end());
            v = ans[0];
            res.push_back(v);
            for (int i = 0; i < ans.size(); i++)
                if (ans[i] != v) {
                    v = ans[i];
                    res.push_back(v);
                }
            return res;
        }
        else
            return ans;

    }
private: void dfs(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& ans) {
        if (!target) {
            ans.push_back(path);
            return;
        }
        for (int i = start + 1; i < candidates.size(); i++) {
            if (candidates[i] > target)
                return;
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, path, ans);
            path.pop_back();
        }
    }
};

int main() {

    vector<int> candidates{10,1,2,7,6,1,5};
    vector<vector<int>> ans;
    Solution test;
    ans = test.combinationSum2(candidates, 8);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout<<ans[i][j]<<"  ";
        cout<<endl;
    }

    return 0;
}