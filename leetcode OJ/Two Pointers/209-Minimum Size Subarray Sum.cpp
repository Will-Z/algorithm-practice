//
// Created by Will on 1/23/16.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size()== 0) {
            return 0;
        }

        int sum, len, ans;
        ans = 2147483647;
        for (int i = 0; i <= nums.size() - 1; i++) {
            int j = i;
            sum = 0;
            len = 0;
            while (j <= nums.size() - 1 && sum < s) {
                sum += nums[j];
                len++;
                j++;
            }
            if (sum >= s) {
                if (len <= ans)
                    ans = len;
            }
        }
        if (ans == 2147483647)
            ans = 0;
        return ans;
    }
};
int main() {
    int a[] = {2,2,2,2,2,2};
    vector<int> nums(a, a+6);
    Solution test;
    cout<<test.minSubArrayLen(100, nums);
    //cout<<nums.size()<<endl;


    return 0;
}