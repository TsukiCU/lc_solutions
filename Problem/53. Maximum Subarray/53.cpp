#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (int i=0; i<n; i++) {
            if (dp[i-1] != 0) dp[i] = dp[i-1] + nums[i];
            else dp[i] = nums[i];
        }
        return *max_element(dp.begin(), dp.end());
    }
};
