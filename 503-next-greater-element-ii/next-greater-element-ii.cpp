class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        vector<int>v;
        int size = nums.size();
        for(int i =2*(size-1); i>=0; i--)
        {
            int I = i % size; 
            if(s.size()==0)
            {
                if(i < size)
                v.push_back(-1);

            }
            else if (s.size()>0 && s.top()>nums[I])
            {
                if(i < size)
                v.push_back(s.top());

            }
            else if (s.size()>0 && s.top()<=nums[I])
            {
                while(s.size()>0 && s.top()<=nums[I])
                {
                    s.pop();
                }
                if(s.size()==0)
                {
                    if(i < size)
                    v.push_back(-1);
                }
                else
                {
                    if(i < size)
                    v.push_back(s.top());
                }
            }
            s.push(nums[I]);

        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};