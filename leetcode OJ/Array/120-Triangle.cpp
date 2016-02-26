//
// Created by Will on 2/3/16.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n;
        n = triangle.size();
        if (!n)
            return 0;
        vector<vector<int>> f(n, vector<int>(n, 0));
        f[0][0] = triangle[0][0];
        for (int i = 1; i <= n - 1; i++)
            for (int j = 0; j <= i; j++) {
                if (j - 1 < 0) {
                    f[i][j] = f[i - 1][j] + triangle[i][j];
                    continue;
                }
                if (i == j) {
                    f[i][j] = f[i - 1][j - 1] +triangle[i][j];
                    continue;
                }
                f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + triangle[i][j];

            }
        const int maxInt = 2147483647;
        int ans = maxInt;
        for (int i = 0; i <= n - 1; i++)
            if (f[n - 1][i] < ans)
                ans = f[n - 1][i];
        return ans;
    }
};
int main() {
    vector<int> v0, v1, v2, v3;
    vector<vector<int>> triangle;

    v0.push_back(2);
    /*
    v1.push_back(3);
    v1.push_back(4);
    v2.push_back(6);
    v2.push_back(5);
    v2.push_back(7);
    v3.push_back(4);
    v3.push_back(1);
    v3.push_back(8);
    v3.push_back(3);
    triangle.push_back(v0);
    triangle.push_back(v1);
    triangle.push_back(v2);
    triangle.push_back(v3);
    */
    triangle.push_back(v0);
    Solution test;
    cout<<test.minimumTotal(triangle)<<endl;
    return 0;
}