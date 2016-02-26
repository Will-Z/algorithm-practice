//
// Created by Will on 1/30/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows <= 0)
            return ans;
        for (int i = 0; i <= numRows - 1; i++) {
            vector<int> v;
            for (int j = 0; j <= i; j++) {
                int now, a1, a2;
                if (i == 0 && j == 0)
                    now = 1;
                else {
                    if (j - 1 < 0)
                        a1 = 0;
                    else
                        a1 = ans[i - 1][j - 1];
                    if (j > ans[i - 1].size() - 1)
                        a2 = 0;
                    else
                        a2 = ans[i - 1][j];
                    now = a1 + a2;
                }

                v.push_back(now);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> a;
    Solution test;
    a = test.generate(5);
    for (int i = 0; i <= a.size() - 1; i++) {
        for(int j = 0; j <= a[i].size() - 1; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}







