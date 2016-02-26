//
// Created by Will on 2/14/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (!n)
            return 0;
        int m = grid[0].size();
        if (!m)
            return 0;
        vector<vector<int>> f(n,vector<int>(m, 0));
        f[0][0] = grid[0][0];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (i || j) {
                    if (!i) {
                        f[i][j] = f[i][j - 1] + grid[i][j];
                        continue;
                    }
                    if (!j) {
                        f[i][j] = f[i - 1][j] + grid[i][j];
                        continue;
                    }
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
                }
        return f[n - 1][m - 1];

    }
};

int main(){
    vector<vector<int>> grid{{1,1,1,1},{2,1,2,0},{2,2,2,1}};
    Solution test;
    cout<<test.minPathSum(grid)<<endl;

    return 0;
}