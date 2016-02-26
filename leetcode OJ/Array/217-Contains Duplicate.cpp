//
// Created by Will on 1/31/16.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1)
            return false;
        map<int,int> elements;
        for (auto item : nums) {
            if (elements.find(item) == elements.end()) {
                elements.insert(map<int,int>::value_type (item, 1));
            }
            else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int a[] = {1,1,1,1,1};
    vector<int> v(a, a+5);
    bool flag;
    Solution test;
    cout<<test.containsDuplicate(v)<<endl;
    return 0;

}