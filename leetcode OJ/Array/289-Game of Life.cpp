//
// Created by Will on 2/16/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if (!n)
            return;
        int m = board[0].size();
        if (!m)
            return;
        vector<vector<int>> f(n, vector<int>(m, 0));
        const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int cell = 0;
                for (int k = 0; k < 8; k++) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                        if (board[xx][yy])
                            cell++;
                    }
                }
                if (board[i][j]) {
                    if (cell == 2 || cell == 3)
                        f[i][j] = 1;
                    else
                        f[i][j] = 0;
                }
                else {
                    if (cell == 3)
                        f[i][j] = 1;
                    else
                        f[i][j] = 0;
                }
            }
        board = f;
    }
};

int main() {
    vector<vector<int>> board{{0,1,1,0},{0,0,0,1},{0,1,0,0},{0,0,1,0}};
    Solution test;
    test.gameOfLife(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j <board[i].size(); j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}