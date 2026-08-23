class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Max = nums[0];
        int sum = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            sum =max(nums[i],sum + nums[i]);
            Max =max(sum,Max);
        }
        return Max;
    }
};