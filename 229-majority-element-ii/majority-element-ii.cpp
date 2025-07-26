class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;
        vector<int>ans;
        map<int,int>freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        for(auto it:freq){
            if(it.second > n){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};