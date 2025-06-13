class Solution {
public:
    bool canFormPairs(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1;) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.back() - nums.front();
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFormPairs(nums, p, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }

        return result;
    }
};
