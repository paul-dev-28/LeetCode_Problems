class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        if (n != goal.size())
            return false;

        for (int shift = 0; shift < n; shift++) {

            bool match = true;

            for (int i = 0; i < n; i++) {
                if (s[(shift + i) % n] != goal[i]) {
                    match = false;
                    break;
                }
            }

            if (match)
                return true;
        }

        return false;
    }
};