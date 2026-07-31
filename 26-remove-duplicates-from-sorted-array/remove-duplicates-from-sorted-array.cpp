class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique = 0;
        for(int scan = 1; scan < nums.size(); scan++){
            if(nums[scan] != nums[unique]){
                unique++;
                nums[unique] = nums[scan];
            }
        }
        return unique + 1;
    }
};