//
// Created by Will on 1/24/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;
        int len = height.size();
        int left[len], right[len];
        left[0] = 0;
        for (int i = 1; i <= len - 1; i++)
            left[i] = max(left[i - 1], height[i - 1]);
        right[len - 1]  = 0;
        for (int i = len - 2; i >= 0; i--)
            right[i] = max(right[i + 1], height[i + 1]);
        int ans = 0;
        for (int i = 0; i <= len - 1; i++)
            if (height[i] < min(left[i], right[i]))
                ans += min(left[i], right[i]) - height[i];

        return ans;
    }
};

int main() {
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v(a, a+1);
    Solution test;
    cout<<test.trap(v)<<endl;
    return 0;
}






