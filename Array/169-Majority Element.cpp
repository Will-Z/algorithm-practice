//
// Created by Will on 1/31/16.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        map<int,int> elements;
        int maxNum = 0, maxLen = 0;
        for (auto i : nums) {
            if (elements.find(i) == elements.end()) {
                elements.insert(map<int,int>::value_type (i, 1));
            }
            else {
                elements[i] += 1;
                if (elements[i] > maxLen) {
                    maxLen = elements[i];
                    maxNum = i;
                }
            }
        }
        return maxNum;
    }
};

int main() {
/*
    map<int,int> mStudent;
    mStudent.insert(map<int,int>::value_type (1, 11));
    mStudent.insert(map<int,int>::value_type (2, 22));
    mStudent.insert(map<int,int>::value_type (3, 33));

    mStudent[1] += 1;

    map<int,int>::iterator iter;
    for(iter = mStudent.begin(); iter != mStudent.end(); iter++)
        cout<<iter->first<<"   "<<iter->second<<endl;

*/
    int a[] = {2,2};
    vector<int> v(a, a+2);
    Solution test;
    int ans;
    ans = test.majorityElement(v);
    cout<<ans<<endl;
    return 0;



}