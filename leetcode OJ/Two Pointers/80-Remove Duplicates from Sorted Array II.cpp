//
// Created by Will on 1/22/16.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2)
            return nums.size();
        int fast, slow, count, ball;

        slow = fast = count = 0;
        ball = nums[0];
        while (fast <= nums.size() - 1) {
            while (ball == nums[fast] && fast <=nums.size() - 1) {
                count++;
                if (count <= 2) {
                    nums[slow] = nums[fast];
                    slow++;
                }
                fast++;
               // if (fast <= nums.size() - 1 && nums[fast] != nums[fast - 1])
               //     count = 0;
            }
            if (ball != nums[fast])
                ball = nums[fast];
            count = 0;
        }
/*
        for (int i = 0; i <= slow - 1; i++ )
            cout<<nums[i]<<"   ";
*/
        return slow;


    }
};

int main() {
    int a[] = {1,1,1,2,2,3};
    vector<int> nums(a, a+3);
    Solution test;
    cout<<test.removeDuplicates(nums)<<endl;
    return 0;
}