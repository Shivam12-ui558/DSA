class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), amt(n);
        
        for (int i = 0; i < n; ++i) {
            pos[i] = fruits[i][0];
            amt[i] = fruits[i][1];
        }

        // Prefix sum of fruit amounts
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + amt[i];

        int ans = 0;

        // Case 1: Go left first, then right
        for (int left = 0; left <= k; ++left) {
            int right = k - 2 * left;
            if (right < 0) continue;

            int l = startPos - left;
            int r = startPos + right;

            int lo = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int hi = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

            ans = max(ans, prefix[hi] - prefix[lo]);
        }

        // Case 2: Go right first, then left
        for (int right = 0; right <= k; ++right) {
            int left = k - 2 * right;
            if (left < 0) continue;

            int l = startPos - left;
            int r = startPos + right;

            int lo = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int hi = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

            ans = max(ans, prefix[hi] - prefix[lo]);
        }

        return ans;
    }
};
