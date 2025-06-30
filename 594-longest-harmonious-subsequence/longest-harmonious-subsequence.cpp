class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int longest = 0;
        for (auto& [key, val] : freq) {
            if (freq.find(key + 1) != freq.end()) {
                longest = max(longest, val + freq[key + 1]);
            }
        }
        return longest;
    }
};