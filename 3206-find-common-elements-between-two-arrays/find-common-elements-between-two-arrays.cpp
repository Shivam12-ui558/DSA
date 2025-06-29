class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int ans1=0;
        int ans2=0;
        int n = nums1.size();
        int m = nums2.size();
        for(int i =0; i < n; i++){
            int count =0;
            for(int j=0; j<m; j++){
                if(nums1[i]==nums2[j]){
                    ans1++;
                    break;
                }
            }
        }
        for(int j =0; j < m; j++){
            int count =0;
            for(int i=0; i<n; i++){
                if(nums2[j]==nums1[i]){
                    ans2++;
                    break;
                }
            }
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};