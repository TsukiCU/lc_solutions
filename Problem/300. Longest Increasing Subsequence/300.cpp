#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i=1; i<n; i++)
            for (int j=i-1; j>=0; j--)
                if (nums[j]<nums[i] && dp[j]>=dp[i])
                    dp[i] = dp[j] + 1;

        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution s;
    cout << s.lengthOfLIS(nums) << endl;
}