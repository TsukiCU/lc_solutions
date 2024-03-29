#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            dp[i].resize(triangle[i].size(), 0);
        }

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i-1][0] + triangle[i][j];
                } else if (j == triangle[i].size() - 1) {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                }
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
