#include <algorithm>
#include <vector>
#include <iostream>
#include "limits.h"

using namespace std;

class Solution {
    public:
    int coinChange(vector<int>& coins, int amount) {
    /* NOTE! Should use long long instead of int in case of overflow! */
        vector<long long> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(auto coin:coins) {
            for(long long i=coin; i<amount+1; i++)
                dp[i] = min(dp[i], dp[i-coin] + 1);
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << s.coinChange(coins, amount) << endl;
}