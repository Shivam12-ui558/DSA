class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        map<int, int> freq1, freq2;

        int n = basket1.size();
        int global_min = INT_MAX;

        // Count total frequencies and individual basket frequencies
        for (int i = 0; i < n; ++i) {
            freq[basket1[i]]++;
            freq1[basket1[i]]++;
            global_min = min(global_min, basket1[i]);

            freq[basket2[i]]++;
            freq2[basket2[i]]++;
            global_min = min(global_min, basket2[i]);
        }

        // If any fruit count is odd → impossible
        for (auto &[num, count] : freq) {
            if (count % 2 != 0) return -1;
        }

        // Collect surplus elements that need to be swapped
        vector<int> surplus1, surplus2;

        for (auto &[num, _] : freq) {
            int diff = freq1[num] - freq2[num];
            if (diff > 0) {
                for (int i = 0; i < diff / 2; ++i)
                    surplus1.push_back(num);
            } else if (diff < 0) {
                for (int i = 0; i < (-diff) / 2; ++i)
                    surplus2.push_back(num);
            }
        }

        sort(surplus1.begin(), surplus1.end());           // ascending
        sort(surplus2.rbegin(), surplus2.rend());         // descending

        long long cost = 0;
        for (int i = 0; i < surplus1.size(); ++i) {
            cost += min({surplus1[i], surplus2[i], 2 * global_min});
        }

        return cost;
    }
};
