//
// Created by Will on 2/3/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n ==0)
            return 0;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i <= m - 1; i++) {
            for (int j = 0; j <= n - 1; j++) {
                if (i == 0 && j == 0) {
                    grid[i][j] = 1;
                    continue;
                }
                int a, b;
                if (i - 1 < 0)
                    a = 0;
                else
                    a = grid[i - 1][j];
                if (j - 1 < 0)
                    b = 0;
                else
                    b = grid[i][j - 1];
                grid[i][j] = a + b;
            }
        }
/*
        for (int i = 0; i <= m - 1; i++) {
            for (int j = 0; j <= n - 1; j++)
                cout<<grid[i][j]<<"  ";
            cout<<endl;
        }
*/
        return grid[m - 1][n - 1];
    }
};

int main() {
    Solution test;
    cout<<test.uniquePaths(100,1)<<endl;
    return 0;
}