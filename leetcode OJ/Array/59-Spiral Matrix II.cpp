//
// Created by Will on 2/6/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        if (n <= 0)
            return matrix;
        vector<vector<bool>> f(n, vector<bool>(n, false));
        dfs(matrix, f, 0, 0, 1, -1, n);
        return matrix;
    }
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& f,int x, int y, int num, int dir, int n) {
        matrix[x][y] = num;
        f[x][y] = true;
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        int xx, yy;
        if (dir != -1) {
            xx = x + dx[dir];
            yy = y + dy[dir];
            if (xx >= 0 && xx < n && yy >= 0 && yy < n && !f[xx][yy])
                dfs(matrix, f, xx, yy, num + 1, dir, n);
        }
        for (int i = 0; i < 4; i++) {
            xx = x + dx[i];
            yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < n && !f[xx][yy])
                dfs(matrix, f, xx, yy, num + 1, i, n);
        }
    }
};

int main() {
    vector<vector<int>> matrix;
    Solution test;
    matrix = test.generateMatrix(0);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j <matrix[i].size(); j++)
            cout<<matrix[i][j]<<"  ";
        cout<<endl;
    }
    return 0;

}