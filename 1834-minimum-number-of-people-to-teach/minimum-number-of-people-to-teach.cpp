class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();  // number of users

        // Convert languages[i] into a set for quick lookup
        vector<unordered_set<int>> userLang(m+1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                userLang[i+1].insert(lang);
            }
        }

        // Step 1: find problematic friendships
        unordered_set<int> usersToFix;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int lang : userLang[u]) {
                if (userLang[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                usersToFix.insert(u);
                usersToFix.insert(v);
            }
        }

        // If no problematic friendships, no teaching needed
        if (usersToFix.empty()) return 0;

        // Step 2: try each language
        int answer = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int count = 0;
            for (int user : usersToFix) {
                if (!userLang[user].count(lang)) {
                    count++;  // must teach this user
                }
            }
            answer = min(answer, count);
        }

        return answer;
    }
};
