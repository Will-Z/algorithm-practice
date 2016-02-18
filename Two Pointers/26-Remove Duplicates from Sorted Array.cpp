//
// Created by Will on 1/21/16.
//


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())
            return 0;
        if (nums.size() == 1)
            return 1;

        int   fast, slow;
        slow = 0;
        fast = 1;
        while (fast <= nums.size() - 1) {
            while (nums[fast] == nums[slow] && fast < nums.size() -1)
                fast++;
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }

     //   for(int i = 0; i <= slow; i++)
      //      cout<<nums[i]<<"   ";


        return slow+1;
    }
};

int main() {
    Solution test;
    int a[6] = {1,1,2,3,3,4};
    vector<int> nums(a, a+3);

    //for(int i = 0; i <= nums.size() - 1; i++)
     //   cout<<nums[i]<<"  ";
    cout<<test.removeDuplicates(nums)<<endl;


    return 0;

}