#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (n <= numRows || numRows == 1) {
            return s;
        }

        string res = "";
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < n; j += 2 * (numRows - 1)) {
                res += s[j + i];
                if (0 < i && i < numRows - 1 && j + 2 * (numRows - 1) - i < n) {
                    res += s[j + 2 * (numRows - 1) - i];
                }
            }
        }

        return res;
    }
};
