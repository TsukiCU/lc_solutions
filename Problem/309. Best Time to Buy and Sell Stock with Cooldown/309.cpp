#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;

        vector<vector<int>> dp(2, vector<int>(n));
        dp[1][0] = -prices[0];

        for (int i=1; i<n; i++) {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]+prices[i]);
            dp[1][i] = max(dp[1][i-1], (i>=2?dp[0][i-2]:0) - prices[i]);
        }

        return *max_element(dp[0].begin(), dp[0].end());
    }
};

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    Solution s;
    cout << s.maxProfit(prices) << endl;
}