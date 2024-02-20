#include<vector>
#include<algorithm>
#include<limits>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        if (n==1) return 0;

        vector<vector<int>> dp(2*k+1, vector<int>(n, 0));
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        for (int i=2; i<2*k+1; i++) dp[i][0] = -10000;

        for (int i=1; i<2*k+1; i++) {
            for (int j=1; j<n; j++) {
                if (i%2 == 0)
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + prices[j]);
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] - prices[j]);
            }
        }

        for (int i=2; i<2*k+2; i+=2) {
        //  Should use max_element to find the largest element in one array.
            int temp = *max_element(dp[i].begin(), dp[i].end());
            if (temp > max_profit) max_profit = temp;
        }

        return max_profit;
    }
};

int main()
{
    int k = 2;
    vector<int> test = {2, 4, 1};
    Solution s;
    cout << "result: " << s.maxProfit(k, test) << endl;
}