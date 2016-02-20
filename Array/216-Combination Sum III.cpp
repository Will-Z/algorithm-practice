//
// Created by Will on 2/18/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k <= 0 || n <= 0)
            return res;

        vector<int> path;
        dfs(res, path, k, n, 0);
        return res;


    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& path, int k, int n, int start) {
        if (!k && !n) {
            res.push_back(path);
            return;
        }
        if (k <= 0 || n <= 0)
            return;

        for (int i = start + 1; i < 10; i++) {
            if (i > n)
                return;
            path.push_back(i);
            dfs(res, path, k - 1, n - i, i);
            path.pop_back();
        }

    }
};

int main() {
    vector<vector<int>> res;
    Solution test;
    res = test.combinationSum3(1, 9);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j <res[i].size(); j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}