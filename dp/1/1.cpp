#include <iostream>
using namespace std;

const long MOD = 10000000007;

class Solution {
public:
    int trainWays(int num) {
    long long a = 1, b = 1;
    for (int i = 0; i < num; i++) {
        long long temp = (a + b) % MOD;
        a = b;
        b = temp;
    }
    return a;
}
};