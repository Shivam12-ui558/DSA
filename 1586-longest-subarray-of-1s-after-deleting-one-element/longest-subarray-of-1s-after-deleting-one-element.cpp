class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeroCount = 0, maxLen = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeroCount++;
            
            // shrink window if more than 1 zero
            while (zeroCount > 1) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }
            
            // delete one element (the zero in window), so subtract 1
            maxLen = max(maxLen, right - left);
        }
        
        return maxLen;
    }
};
