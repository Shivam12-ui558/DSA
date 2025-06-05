class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>freq;
        for(int i = 0; i < n; i++){
           freq[nums[i]]++;
        }
        
        for(auto it:freq){
            if(it.second!=2)
            return it.first;
        }
        return -1;
    }
};