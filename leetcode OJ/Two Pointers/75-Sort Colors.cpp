//
// Created by Will on 1/21/16.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1)
            return;

        int zero, one, two, count;
        zero = 0;
        one = 0;
        two = 0;
        for (int i = 0; i <= nums.size() - 1; i++)
            if (nums[i] == 0)
                zero++;
            else if (nums[i] == 1)
                one++;
            else if (nums[i] == 2)
                two++;

        count = 0;
        while (zero) {
            nums[count] = 0;
            zero--;
            count++;
        }
        while (one) {
            nums[count] = 1;
            one--;
            count++;
        }
        while (two) {
            nums[count] = 2;
            two--;
            count++;
        }


        for (int i = 0; i <= nums.size() -1; i++)
            cout<<nums[i]<<"   ";



    }
};

int main() {
    Solution test;
    int a[] = {1, 0};
    vector<int> nums(a, a+2);
    test.sortColors(nums);
    return 0;
}



