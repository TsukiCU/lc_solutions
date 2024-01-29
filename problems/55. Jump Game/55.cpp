#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return true;
        }
        int farthest = 0;
        int end = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);
            if (i == end) {
                if (farthest == i) {
                    return false;
                }
                end = farthest;
            }
        }

        return true;
    }
};
