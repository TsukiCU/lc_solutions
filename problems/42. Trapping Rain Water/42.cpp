#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Dual Pointers
    int trapTwoPointers(const vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftmax = 0, rightmax = 0;
        int res = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftmax = max(leftmax, height[left]);
                res += leftmax - height[left];
                ++left;
            } else {
                rightmax = max(rightmax, height[right]);
                res += rightmax - height[right];
                --right;
            }
        }

        return res;
    }

    // DP
    int trapDynamicProgramming(const vector<int>& height) {
        if (height.empty()) return 0;

        int n = height.size();
        int res = 0;
        vector<int> leftmax(n, 0), rightmax(n, 0);

        leftmax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }

        rightmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightmax[i] = max(rightmax[i + 1], height[i]);
        }

        for (int i = 0; i < n; ++i) {
            res += min(leftmax[i], rightmax[i]) - height[i];
        }

        return res;
    }

    // Monothic Stack
    int trapMonotonicStack(const vector<int>& height) {
        int res = 0, current = 0;
        stack<int> st;
        int n = height.size();

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int distance = i - st.top() - 1;
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                res += distance * bounded_height;
            }
            st.push(i);
        }

        return res;
    }
};
