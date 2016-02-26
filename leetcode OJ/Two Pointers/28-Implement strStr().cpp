//
// Created by Will on 1/21/16.
//

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length())
            return -1;
        int n, m, flag;
        n = haystack.length();
        m = needle.length();


        for (int i = 0; i <= n - m; i++) {
            flag = 1;
            for(int j = 0; j <= m-1; j ++) {
                if(haystack[i + j] != needle[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                return i;
        }
        return -1;

    }
};


int main() {
    Solution test;
    string a = "abc12345";
    string b = "45";


    cout<<test.strStr(a, b)<<endl;

    return 0;

}