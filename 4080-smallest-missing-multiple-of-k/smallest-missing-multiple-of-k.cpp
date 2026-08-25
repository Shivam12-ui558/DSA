class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool>ans(101,false);
        for(int num : nums){
            if(num % k == 0){
                ans[num / k] = true;
            }
        }
        for(int i = 1 ; ; i++){
            if(!ans[i]){
                return i * k;
            }
        }
        return -1;
    }
};