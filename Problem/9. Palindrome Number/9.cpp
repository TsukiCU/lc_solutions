#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || !(x%10)&&x) return false;  // !优先级高于%
        int half_revert = 0;
        while (x>half_revert) {
            half_revert = half_revert * 10 + x%10;
            x /= 10;
        }

        return x == half_revert || x == half_revert / 10;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome(10) << endl;
}