//
// Created by Will on 1/21/16.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       if (!nums.size())
           return;
        int slow, fast, zero;

        slow = fast = zero =  0;
        while (fast <= nums.size() - 1) {
            while (!nums[fast] && fast < nums.size() - 1) {
                fast++;
                zero++;
            }
            if (nums[fast]) {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            } else
                fast++;
        }
        for (int i = slow; i <= nums.size() - 1; i++)
            nums[i] = 0;

       // for (int i = 0; i <= nums.size() - 1; i++)
         //   cout<<nums[i]<<"    ";
    }
};


int main() {
    Solution test;
    int a[] = {1, 2, 3, 4, 5};
    vector<int> nums(a, a+5);

/*
    for (int i = 0; i <= nums.size() - 1; i++)
        cout<<nums[i]<<"   ";
    cout<<endl;
*/
    test.moveZeroes(nums);
    return 0;
}