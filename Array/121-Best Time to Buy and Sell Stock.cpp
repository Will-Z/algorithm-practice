//
// Created by Will on 2/16/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        int start = prices[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] - start > ans)
                ans = prices[i] - start;
            if (prices[i] < start)
                start = prices[i];
        }
        return ans;
    }
};
int main() {
    vector<int> prices{3};
    Solution test;
    cout<<test.maxProfit(prices)<<endl;
    return 0;
}