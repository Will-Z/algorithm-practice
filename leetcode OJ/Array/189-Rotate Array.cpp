//
// Created by Will on 1/30/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size())
            k = k % nums.size();
        if (nums.size() <= 1 || k == 0)
            return;
        vector<int> v = nums;
        for (int i = 0; i <= k - 1; i++)
            nums[i] = v[i + nums.size() - k];
        for (int i = k; i <= nums.size() - 1; i++)
            nums[i] = v[i - k];
    }
};

int main() {
    int a[] = {1,2,3,4,5,6,7};
    vector<int> v(a, a+7);
    Solution test;
    test.rotate(v, 8);
    cout<<v.size()<<endl;
    return 0;

}