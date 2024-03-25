#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int check(vector<int>&numbers, int left, int right, int target)
    {
        return numbers[left] + numbers[right] - target;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while (left<right) {
            if (!check(numbers, left, right, target)) return vector<int> {left+1, right+1};
            else if (check(numbers, left, right, target) < 0) left++;
            else right--;    
        }

        return {};
    }
};

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5};
    int target = 9;
    Solution s;
    s.twoSum(numbers, target);
}