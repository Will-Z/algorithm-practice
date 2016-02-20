//
// Created by Will on 2/14/16.
//
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = lower_bound(nums, target);
        int right = upper_bound(nums, target);

        if (nums[left] != target)
            return vector<int>{-1, -1};
        if (nums[right] != target)
            return vector<int>{left, right - 1};
        return vector<int>{left, right};
    }
private:
    int lower_bound(vector<int> &nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >>1;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    int upper_bound(vector<int> &nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main() {
    int a[] = {0, 0, 0, 0, 0};
    vector<int> nums(a, a + 5);
    Solution test;
    vector<int> ans = test.searchRange(nums, 3);
    cout<<ans.size()<<endl;
    cout<<ans[0]<<"    "<<ans[1]<<endl;
    return 0;
}