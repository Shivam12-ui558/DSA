class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxDiag = -1; 
        int maxArea = -1;

        for (auto &rect : dimensions) {
            long long l = rect[0], w = rect[1];
            long long diag = l * l + w * w; // diagonal squared
            int area = l * w;

            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } else if (diag == maxDiag && area > maxArea) {
                maxArea = area;
            }
        }
        return maxArea;
    }
};
