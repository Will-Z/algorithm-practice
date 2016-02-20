//
// Created by Will on 1/30/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len, carry;
        len = digits.size();
        digits[len - 1]++;
        carry = 0;
        for (int i = len - 1; i > 0; i--) {
            int now;
            now = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            digits[i] = now;
        }
        //cout<<"carry  "<<carry<<endl;
        digits[0] += carry;
        if (digits[0] == 10) {
            digits[0] = 1;
            for (int i = 1; i <= digits.size() - 1; i++)
                digits[i] = 0;
            digits.push_back(0);
        }
        return digits;
    }
};

int main() {
    int a[] = {9};
    vector<int> digits(a, a+1);
    Solution test;
    digits = test.plusOne(digits);
    for(int i = 0; i <= digits.size() - 1; i++)
        cout<<digits[i]<<" ";
    cout<<endl;
    return 0;
}