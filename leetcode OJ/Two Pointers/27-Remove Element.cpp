//
// Created by Will on 1/21/16.
//


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        if (!nums.size())
            return 0;
        int remove = 0;

        for(int i = 0; i <= nums.size() - 1; i++) {
            if (nums[i] == val)
                remove++;
            else
                nums[i-remove] = nums[i];
        }

        for (int i = 0; i <= nums.size() - 1; i++)
            cout<<nums[i]<<"   ";
        cout<<endl;

        return nums.size() - remove;
    }
};

int main() {
    Solution test;
    int a[5] = {0, 1, 2, 2, 4};
    vector<int> nums;
/*
    for(int i = 0; i <= 4; i++)
        cout<<nums[i]<<"   ";
    cout<<endl;
*/


    cout<<"ans"<<test.removeElement(nums, 2)<<endl;
    return 0;




 }