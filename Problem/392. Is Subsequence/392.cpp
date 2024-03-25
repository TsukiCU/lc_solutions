#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (!s.size()) return true;
        int left = 0, right = t.size() - 1;
        int i=0, j=s.size() - 1;

        while (left <= right) {
            if (right - left < j - i)
                return false;
            if (t[left] == s[i])
                i += 1;
            if (t[right] == s[j])
                j -= 1;
            left += 1;
            right -= 1;

            if (i > j)
                return true;
        }

        return false;
    }

    bool followup(string s, string t)
    {
        
    }
};

int main()
{
    string s = "b";
    string t = "b";
    Solution ss;
    cout << ss.isSubsequence(s, t) << endl;
}