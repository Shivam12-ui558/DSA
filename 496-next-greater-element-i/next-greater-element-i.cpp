class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> nextGreater(nums2.size(), -1); 
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (!s.empty()) {
                nextGreater[i] = s.top();
            }
            s.push(nums2[i]);
        }

        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    result.push_back(nextGreater[j]);
                    break;
                }
            }
        }

        return result;
    }
};