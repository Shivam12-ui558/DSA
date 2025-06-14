class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int maximum = num, minimum = num;

        // Try all digits to replace with 9 for max
        for (char d = '0'; d <= '9'; ++d) {
            string temp = s;
            for (char& c : temp) {
                if (c == d) c = '9';
            }
            maximum = max(maximum, stoi(temp));
        }

        // Try all digits to replace with 0 for min
        for (char d = '0'; d <= '9'; ++d) {
            string temp = s;
            for (char& c : temp) {
                if (c == d) c = '0';
            }
            minimum = min(minimum, stoi(temp));
        }

        return maximum - minimum;
    }
};
