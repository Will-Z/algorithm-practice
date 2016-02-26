//
// Created by Will on 2/7/16.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,int> column, row;
        int n = matrix.size();
        if (!n)
            return;
        int m = matrix[0].size();
        if (!m)
            return;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!matrix[i][j]) {
                    if (row.find(i) == row.end())
                        row.insert(map<int,int>::value_type(i,1));
                    if (column.find(j) == column.end())
                        column.insert(map<int,int>::value_type(j,1));
                }
        for (int i = 0; i < n; i++)
            if (row.find(i) != row.end())
                for (int j = 0; j < m; j++)
                    matrix[i][j] = 0;

        for (int i = 0; i < m; i++)
            if (column.find(i) != column.end())
                for (int j = 0; j < n; j++)
                    matrix[j][i] = 0;
        return;
    }
};

int main() {
    vector<vector<int>> matrix;
    for(int i = 0; i < 1; i++) {
        vector<int> v;
        for (int j = 0; j < 1; j++)
            v.push_back(1);
        matrix.push_back(v);
    }
    Solution test;
    matrix[0][0] = 0;
    test.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++)
            cout<<matrix[i][j]<<"  ";
        cout<<endl;
    }
    return 0;


}