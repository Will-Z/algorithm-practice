//
// Created by Will on 1/23/16.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1)
            return s.length();


        int hash[128];
        int len, ans;
        ans = 1;
        for(int i = 0; i <= s.length() - 1; i++) {
            memset(hash, 0, sizeof(int) * 128);
            len = 0;
            for(int j = i; j <= s.length() - 1; j++) {
                if (!hash[int(s[j])]) {
                    len++;
                    hash[int(s[j])] = 1;
                }
                else {
                    if (len > ans)
                        ans = len;
                    break;
                }
            }
            if (len > ans)
                ans = len;
           // cout<<"i:  "<<i<<"    "<<len<<endl;
        }

        return ans;
    }
};
int main() {
    string s = "ab  110134";
    Solution test;

    cout<<test.lengthOfLongestSubstring(s)<<endl;
    return 0;

}