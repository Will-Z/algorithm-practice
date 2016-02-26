//
// Created by Will on 2/14/16.
//
#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return;
        int p1 = n - 1;
        while (p1 - 1 >= 0 && nums[p1 - 1] >= nums[p1])
            p1--;
        if (!p1) {
            sort(nums.begin(), nums.end());
            return;
        }
        p1--;
        int i;
        for (i = n - 1; i > p1; i--)
            if (nums[i] > nums[p1]) {
                int x;
                x = nums[i];
                nums[i] = nums[p1];
                nums[p1] = x;
                break;
            }
        sort (nums.begin() + p1 + 1, nums.end());
        return;
    }
};

int main() {

    int a[] = {2,3,1};
    Solution test;
    vector<int> v(a,a + 3);
    test.nextPermutation(v);

/*
    vector<int> v{7,6,5,4,3,2,1,0};
    sort(v.begin()+1, v.end());
*/
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;


    return 0;


}