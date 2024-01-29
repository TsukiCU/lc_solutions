#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        int end = 0;
        int jumps = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);

            if (i == end) {
                jumps++;
                end = farthest;
            }
        }

        return jumps;
    }
};
