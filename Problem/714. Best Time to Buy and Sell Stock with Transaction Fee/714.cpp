#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 1) return 0;
        int hold = prices[0];
        int profit = 0;

        for (int i=1; i<n; ++i) {
            if (prices[i] < hold) hold = prices[i];
            else if (prices[i] - fee > hold) {
                profit += prices[i] - fee - hold;
                hold = prices[i] - fee;
            }
        }
        return profit;
    }
};