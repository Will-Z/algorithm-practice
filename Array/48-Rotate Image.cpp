//
// Created by Will on 2/14/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n <= 1)
            return;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                v[j][n - 1 - i] = matrix[i][j];
            }
        matrix = v;
    }
};

int main() {
    vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution test;
    test.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout<<matrix[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}