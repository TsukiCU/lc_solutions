#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<time.h>

using namespace std;

class Solution {
public:
    int is_majority(vector<int>& nums, int n) {
        int count = 0;
        int length = nums.size();
        for (int i:nums) {
            if (n == i) count ++;
            if (count > length/2) return 1;
        }
        return 0;
    }

    int majorityElement(vector<int>& nums) {
        srand(time(NULL));
        int size = nums.size();

        while (1) {
            int randomValue = nums[rand() % size];
            if (is_majority(nums, randomValue)) return randomValue;
        }
    }

    int majorityElement1(vector<int>& nums) {
        int n = nums[0];
        int count = 0;

        for (int i : nums) {
            if (count == 0) {n = i; count++;}
            else if (i == n) count++;
            else count--;
        }
        return n;
    }
};

int main()
{
    std::vector<int> nums{1, 1, 1, 1, 2, 3, 4};
    Solution s;
    cout << s.majorityElement(nums) << "\n";
    cout << s.majorityElement1(nums) << endl;
}