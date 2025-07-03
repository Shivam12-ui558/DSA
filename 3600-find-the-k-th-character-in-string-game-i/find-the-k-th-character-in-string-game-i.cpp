class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        int i = 0;
        while (word.size() < k) {
            int n = word.size();
            for (int j = 0; j < n; ++j) {
                char nextChar = (word[j] - 'a' + 1) % 26 + 'a';
                word += nextChar;
                if (word.size() >= k) break;
            }
        }
        return word[k - 1];
    }
};
