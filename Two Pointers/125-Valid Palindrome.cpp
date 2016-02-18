//
// Created by Will on 1/20/16.
//


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (!s.length())
            return true;

        int head, tail;
        bool have;

        have = 0;
        for(int i = 0; i <= s.length() - 1; i++)
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9') {
                have = 1;
                break;
            }

        if (!have)
            return true;
            head = 0;
            tail = s.length() - 1;

            while (head < tail) {
                while (!(s[head] >= 'a' && s[head] <= 'z' || s[head] >= 'A' && s[head] <= 'Z' ||
                         s[head] >= '0' && s[head] <= '9') && head < s.length() - 1) {
                    head++;
                }
                while (!(s[tail] >= 'a' && s[tail] <= 'z' || s[tail] >= 'A' && s[tail] <= 'Z' ||
                         s[tail] >= '0' && s[tail] <= '9') && tail > 0) {
                    tail--;
                }
                if (s[head] == s[tail] ||  !(s[head] >= '0' && s[head] <= '9') && !(s[tail] >= '0' && s[tail] <= '9') && abs(s[head] - s[tail]) == 32) {
                    head++;
                    tail--;
                } else
                    return false;

            }
            return true;

    }
};

int main() {

    string s = "race a car";
    Solution test;
    cout<<test.isPalindrome(s)<<endl;


/*
    string s = "P0";
    int a, b;
    a = s[0];
    b = s[1];
    cout<<a<<"  "<<b<<endl;

*/
    return 0;
}