class Solution {
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    long long inv(long long n) {
        return power(n, 1000000007 - 2); 
    }

    long long nCr_mod_p(int n, int r, const std::vector<long long>& fact, const std::vector<long long>& invFact) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % 1000000007) * invFact[n - r]) % 1000000007;
    }

    int countGoodArrays(int n, int m, int k) {
        if (k < 0 || k > n - 1) {
            return 0;
        }

        long long MOD = 1000000007;

        std::vector<long long> fact(n);
        std::vector<long long> invFact(n);
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i < n; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
            invFact[i] = inv(fact[i]);
        }

        long long term2;
        if (m == 1) {
             if (n - 1 - k == 0) { // k == n - 1
                term2 = 1;
            } else {
                term2 = 0;
            }
        } else {
            term2 = power(m - 1, n - 1 - k);
        }
        
        long long combinations = nCr_mod_p(n - 1, k, fact, invFact);

        long long term_m = m % MOD;

        long long ans = (combinations * term_m) % MOD;
        ans = (ans * term2) % MOD;

        return static_cast<int>(ans);
    }
};