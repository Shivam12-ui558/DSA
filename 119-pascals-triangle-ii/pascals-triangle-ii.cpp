class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1); // Initialize all values with 1

        for (int i = 2; i <= rowIndex; ++i) {
            // Update from right to left to avoid overwriting needed values
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};
