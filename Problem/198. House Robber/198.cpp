#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int func(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    int twoHousesBack = nums[0];
    int oneHouseBack = max(nums[0], nums[1]);
    int maxProfit = max(oneHouseBack, nums[0] + nums[2]);

    for (int i = 2; i < n; ++i) {
        int current = nums[i] + max(twoHousesBack, i > 2 ? oneHouseBack : 0);
        twoHousesBack = oneHouseBack;
        oneHouseBack = maxProfit;
        maxProfit = max(maxProfit, current);
    }

    return maxProfit;
}
