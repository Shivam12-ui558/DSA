class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, streak = 0;
        for (int num : nums) {
            if (num == 0) {
                streak++;           // Extend the current zero streak
                count += streak;    // Add all subarrays ending at this index
            } else {
                streak = 0;         // Reset streak when non-zero is found
            }
        }
        return count;
    }
};
