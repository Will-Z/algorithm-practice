//
// Created by Will on 1/30/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if (rowIndex < 0)
            return ans;
        if (rowIndex == 0) {
            ans.push_back(1);
            return ans;
        }
        vector<int> pre;
        pre.push_back(1);
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> v;
            for (int j = 0; j <= i; j++) {
                int a1, a2, now;
                if (j - 1 < 0)
                    a1 = 0;
                else
                    a1 = pre[j - 1];
                if(j > pre.size() - 1)
                    a2 = 0;
                else a2 = pre[j];
                now = a1 +a2;
                v.push_back(now);
            }
            pre = v;
        }
        return pre;
    }
};

int main() {
    vector<int> v;
    Solution test;
    v = test.getRow(1);
    for (int i = 0; i <= v.size() - 1; i++)
        cout<<v[i]<<" ";
    return 0;
}