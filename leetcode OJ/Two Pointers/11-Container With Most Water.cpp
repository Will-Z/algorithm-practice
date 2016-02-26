//
// Created by Will on 1/24/16.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1)
            return 0;

        int left, right, area, ans, i, j;
        left = height[0];
        right = height[height.size() - 1];
        ans = 0;
        i = 0;
        j = height.size() - 1;

        while (i < j) {
            area = min(left, right) * (j - i);
            if (area > ans)
                ans = area;
            if (left < right) {
                while (i < j && height[i] <= left)
                    i++;
                if (i < j)
                    left = height[i];
            }
            else {
                while (i < j && height[j] <= right)
                    j--;
                if (i < j)
                    right = height[j];
            }
        }

        return ans;
    }
};

int main() {
    Solution test;
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v(a, a+12);
    cout<<test.maxArea(v);
    return 0;


}