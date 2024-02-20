#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;

        vector<vector<int>> dp(4, vector<int>(n, 0));
        dp[0][0] = -prices[0];
        dp[1][0] = numeric_limits<int>::min();
        dp[2][0] = numeric_limits<int>::min();
        dp[3][0] = numeric_limits<int>::min();

        for (int i = 1; i < n; ++i) {
            dp[0][i] = max(dp[0][i-1], -prices[i]);
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] + prices[i]);
            dp[2][i] = max(dp[2][i-1], dp[1][i-1] - prices[i]);
            dp[3][i] = max(dp[3][i-1], dp[2][i-1] + prices[i]);
        }
        int max_profit = max(dp[1][n-1], dp[3][n-1]);
        return max_profit > 0 ? max_profit : 0;
    }
};
