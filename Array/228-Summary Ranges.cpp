//
// Created by Will on 1/30/16.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (!nums.size())
            return ans;
        int start, end;
        start = nums[0];
        for (int i = 1; i <= nums.size() - 1; i++) {
            if (nums[i] - nums[i - 1] != 1) {
                if (nums[i - 1] != start) {
                    end = nums[i - 1];
                    string s;
                    stringstream ss;
                    ss<<start;
                    s = ss.str();
                    ss.str("");
                    ss<<end;
                    s += "->";
                    s += ss.str();
                    ans.push_back(s);
                }
                else {
                    string s;
                    stringstream ss;
                    ss<<start;
                    s = ss.str();
                    ans.push_back(s);
                }
                start = nums[i];
            }
        }
        if (nums[nums.size() - 1] != start) {
            end = nums[nums.size() - 1];
            string s;
            stringstream ss;
            ss<<start;
            s = ss.str();
            s += "->";
            ss.str("");
            ss<<end;
            s += ss.str();
            ans.push_back(s);
        }
        else {
            string s;
            stringstream ss;
            ss<<start;
            s = ss.str();
            ans.push_back(s);
        }

        return ans;
    }
};

int main() {
    int a[] = {1,3,5,7,9,10};
    vector<int> v(a, a+6);
    Solution test;
    vector<string> s;
    s = test.summaryRanges(v);
   // cout<<s.size()<<endl;

    for (int i = 0; i <= s.size() - 1; i++)
        cout<<s[i]<<endl;

    return 0;

}