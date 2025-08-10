class Solution {
public:
    // Helper to get sorted string of digits
    string getDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
    
    bool reorderedPowerOf2(int n) {
        string target = getDigits(n);
        
        // Check powers of 2 from 1 up to 2^30
        for (int i = 0; i < 31; i++) {
            int pow2 = 1 << i;
            if (getDigits(pow2) == target) {
                return true;
            }
        }
        return false;
    }
};
