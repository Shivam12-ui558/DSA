class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0); 
        int l = 0, maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;

            while (freq[s[r]] > 1) {
                freq[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
