//
// Created by Will on 2/6/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if (!n)
            return ans;
        int m = matrix[0].size();
        if (!m)
            return ans;
        vector<vector<bool>> f(n, vector<bool>(m, false));
        dfs(f, matrix, ans, 0, 0, -1);
        return ans;

    }
    void dfs(vector<vector<bool>>& f, vector<vector<int>>& matrix, vector<int>& ans, int x, int y, int dir) {
        f[x][y] = true;
        ans.push_back(matrix[x][y]);
        const int dy[] = {1, 0, -1, 0};
        const int dx[] = {0, 1, 0, -1};
        if (dir != -1) {
            int xx, yy;
            xx = x + dx[dir];
            yy = y + dy[dir];
            if (xx >= 0 && xx <= matrix.size() - 1 && yy >= 0 && yy <= matrix[0].size() - 1 && !f[xx][yy])
                dfs(f, matrix, ans, xx, yy, dir);

        }
        for (int i = 0; i < 4; i++) {
            int xx, yy;
            xx = x + dx[i];
            yy = y + dy[i];
            if (xx >= 0 && xx <= matrix.size() - 1 && yy >= 0 && yy <= matrix[0].size() - 1 && !f[xx][yy])
                dfs(f, matrix, ans, xx, yy, i);
        }

    }
};
int main() {
    vector<vector<int>> matrix;
  /*
    int x = 0;
    for (int i = 0; i < 3; i++) {
        vector<int> v;
        for (int j = 0; j < 3; j++) {
            x++;
            v.push_back(x);
        }
        matrix.push_back(v);
    }
*/
    vector<int> v;
    v.push_back(1);
    matrix.push_back(v);
    v.clear();
    v.push_back(2);
    matrix.push_back(v);
/*
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout<<matrix[i][j]<<"   ";
        cout<<endl;
    }
*/


    Solution test;
    vector<int> ans;
    ans = test.spiralOrder(matrix);
    for (int i = 0; i <ans.size(); i++)
        cout<<ans[i]<<"  ";

    return 0;
}