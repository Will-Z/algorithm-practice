//
// Created by Will on 2/14/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (!n)
            return false;
        int m = matrix[0].size();
        if (!m)
            return false;
        if (target < matrix[0][0] || target > matrix[n - 1][m - 1])
            return false;

        int left, right, mid;
        left = 0, right = n - 1;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (matrix[mid][0] == target)
                return true;
            if (matrix[mid][0] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        int row = mid;
        while (matrix[row][0] > target)
            row--;

        left = 0; right = m - 1;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (matrix[row][mid] == target)
                return true;
            if (matrix[row][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (matrix[row][mid] == target)
            return true;
        else
            return false;
    }
};

int main() {
    vector<vector<int>> matrix{{1,2},{5,7},{8,9},{10,11},{13,16}};
    Solution test;
    cout<<test.searchMatrix(matrix, 15)<<endl;
/*
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout<<matrix[i][j]<<"  ";
        cout<<endl;
    }
*/
    return 0;
}