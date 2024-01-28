#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {""};
        }
        vector<string> res;

        for (int p = 0; p < n; ++p) {
            for (const auto& p_ : generateParenthesis(p)) {
                for (const auto& q_ : generateParenthesis(n - 1 - p)) {
                    res.push_back("(" + p_ + ")" + q_);
                }
            }
        }

        return res;
    }
};
