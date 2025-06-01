class Solution {
public:
    void reverseString(vector<char>& s) {
      int n = s.size();
        vector<char>temp(n);
        for(int i = 0; i < n; i++){
            temp[i] = s[n-i-1];
        }
        for(int i=0; i < n; i++){
            s[i]=temp[i];
        }
        
    }
};