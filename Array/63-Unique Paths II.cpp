//
// Created by Will on 2/3/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n, m;
        n = obstacleGrid.size();
        if (n == 0)
            return 0;
        m = obstacleGrid[0].size();
        if (m == 0)
            return 0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
            return 0;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i <= n - 1; i++) {
            for (int j = 0; j <= m - 1; j++) {
                if (i == 0 && j == 0) {
                    ans[i][j] = 1;
                    continue;
                }
                if (obstacleGrid[i][j] == 1) {
                    ans[i][j] = 0;
                    continue;
                }
                int a, b;
                if (i - 1 < 0)
                    a = 0;
                else
                    a = ans[i - 1][j];
                if (j - 1 < 0)
                    b = 0;
                else
                    b = ans[i][j - 1];
                ans[i][j] = a + b;
            }
        }
        return ans[n - 1][m - 1];
    }
};
int main() {
    Solution test;
    vector<vector<int>> v;
    cout<<test.uniquePathsWithObstacles(v);
    return 0;
}