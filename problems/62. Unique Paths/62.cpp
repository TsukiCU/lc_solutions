#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsSolution1(int m, int n) {
        vector<int> h(n, 1);
        for (int i = 0; i < m - 1; i++) {
            for (int j = 1; j < n; j++) {
                h[j] += h[j - 1];
            }
        }
        return h[n - 1];
    }

    int uniquePathsSolution2(int m, int n) {
        vector<vector<int>> h(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                h[i][j] = h[i - 1][j] + h[i][j - 1];
            }
        }
        return h[m - 1][n - 1];
    }
};

int main() {
    Solution sol;

    int m = 3, n = 7;
    int result1 = sol.uniquePathsSolution1(m, n);
    int result2 = sol.uniquePathsSolution2(m, n);

    return 0;
}
