class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0, maxFruits = 0;

        for (int right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;

            // If more than 2 types of fruits, shrink the window
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }

            // Update maximum fruits collected
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};
