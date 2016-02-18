//
// Created by Will on 1/21/16.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (n > 0) {
            if (m > 0 && nums1[m - 1] > nums2 [n - 1]) {
                nums1[m + n - 1] = nums1[m - 1];
                m--;
            } else {
                nums1[m + n - 1] = nums2[n - 1];
                n--;
            }

        }
    }
};


int main() {
    Solution test;
    vector<int> a(20), b(20);
    //a[0] = 0; a[2] = 11; a[3] = 2; a[4] = 4;
    a = {0, 2, 18};
    b = {3, 9, 14, 39};

    test.merge(a, 0, b, 1);


    return 0;


}