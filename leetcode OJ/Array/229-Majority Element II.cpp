//
// Created by Will on 2/15/16.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if (!n)
            return ans;
        if (n == 1) {
            ans.push_back(nums[0]);
            return ans;
        }
        map<int, int> elements;
        map<int, int> res;
        for (int i = 0; i < n; i++) {
            if (elements.find(nums[i]) == elements.end())
                elements.insert(map<int,int>::value_type(nums[i],1));
            else
                elements[nums[i]]++;
            if (elements[nums[i]] > n / 3 && res.find(nums[i]) == res.end())
                    res.insert(map<int,int>::value_type(nums[i],1));

        }
        map<int,int>::iterator iter;
        for (iter = res.begin(); iter != res.end(); iter++)
            ans.push_back(iter->first);
        return ans;
    }
};

int main() {
    vector<int> nums{1,2};
    Solution test;
    vector<int> ans;
    ans = test.majorityElement(nums);
    for (int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<endl;

    return 0;
}