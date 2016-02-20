//
// Created by Will on 1/31/16.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= 1 || k <=0)
            return false;
        map<int,int> elements;
        for (int i = 0; i <= nums.size() - 1; i++) {
            if (elements.find(nums[i]) == elements.end())
                elements.insert(map<int,int>::value_type(nums[i], i));
            else {
                if (i - elements[nums[i]] <= k)
                    return true;
                else
                    elements[nums[i]] = i;
            }
        }
        return false;
    }
};

int main() {
    int a[] = {1,1,1,1,1,1,1};
    vector<int> v(a, a+7);
    Solution test;
    cout<<test.containsNearbyDuplicate(v, 0);
    return 0;
}