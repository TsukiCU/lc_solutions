#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) {
            return s;
        }

        int max_length = 0;
        int begin = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && j - i + 1 > max_length) {
                    max_length = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, max_length);
    }
};

int main() {
    Solution s;
    string a = "ac";
    cout << s.longestPalindrome(a) << endl;
    return 0;
}
