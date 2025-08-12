#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;
    unordered_map<long long, int> memo;

    long long power(long long base, int exp) {
        long long res = 1;
        while (exp--) res *= base;
        return res;
    }

    int dfs(int n, int x, int curr) {
        if (n == 0) return 1; // valid way
        if (n < 0) return 0;  // invalid

        long long key = ((long long)n << 15) | curr; // unique state encoding
        if (memo.count(key)) return memo[key];

        long long pw = power(curr, x);
        if (pw > n) return 0; // no further possible

        int take = dfs(n - pw, x, curr + 1) % MOD;
        int skip = dfs(n, x, curr + 1) % MOD;

        return memo[key] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        memo.clear();
        return dfs(n, x, 1);
    }
};
