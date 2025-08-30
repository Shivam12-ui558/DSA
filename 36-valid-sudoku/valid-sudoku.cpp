class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> boxes(9, vector<bool>(9, false));

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;  
                int num = board[r][c] - '1'; 
                
                int boxIndex = (r / 3) * 3 + (c / 3);
                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num])
                    return false;

                rows[r][num] = cols[c][num] = boxes[boxIndex][num] = true;
            }
        }
        return true;
    }
};
