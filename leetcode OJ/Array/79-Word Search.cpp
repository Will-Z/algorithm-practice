//
// Created by Will on 2/1/16.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n, m;
        n = board.size();
        if (!n)
            return false;
        m = board[0].size();
        if (!m)
            return false;
        vector<vector<int>> used(n,vector<int>(m, false));
        for (int i = 0; i <= n - 1; i++)
            for (int j = 0; j <= m - 1; j++)
                if(backtracking(board, word, used, i, j, 0))
                    return true;
        return false;
    }
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};
    bool backtracking(vector<vector<char>>& board, string word, vector<vector<int>>& used, int i, int j, int len) {
        if (len == word.length())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || used[i][j])
            return false;
        if (word[len] != board[i][j])
            return false;
        used[i][j] = true;
        for (int k = 0; k <= 3; k++)
            if (backtracking(board, word, used,i + dx[k], j + dy[k], len + 1))
                return true;
        used[i][j] = false;
        return false;
    }
};

int main() {
   /*
    char a[3][4] = {{'A','B','C','E'},
                    {'S','F','C','S'},
                    {'A','D','E','E'}
    };
    int n = 3, m = 4;
    vector<vector<char>> board;
    for (int i = 0; i <= n - 1; i++) {
        vector<char> v;
        for (int j = 0; j <= m - 1; j++)
            v.push_back(a[i][j]);
        board.push_back(v);
    }
    string word = "";

    for (int i = 0; i <= board.size() - 1; i++){
        for (int j = 0; j <= board[i].size() - 1; j++)
            cout<<board[i][j]<<"  ";
        cout<<endl;
    }
*/
    vector<vector<char>> board;
    vector<char> v;
    v.push_back('a');
    string word = "ab";
    Solution test;
    cout<<test.exist(board,word);

    return 0;
}