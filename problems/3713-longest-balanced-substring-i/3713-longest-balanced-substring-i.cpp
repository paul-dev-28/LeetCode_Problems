class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;
        int uniqueChars = 0;
        vector<int> total(26, 0);
        for(char c : s) if(total[c-'a']++ == 0) uniqueChars++;

        for (int k = 1; k <= uniqueChars; ++k) {
            for (int f = 1; f * k <= n; ++f) {
                int targetLen = k * f;
                std::vector<int> count(26, 0);
                int distinctInWindow = 0;
                int balancedCount = 0;

                for (int i = 0; i < n; ++i) {
                    int addIdx = s[i] - 'a';
                    if (count[addIdx] == 0) distinctInWindow++;
                    count[addIdx]++;
                    if (count[addIdx] == f) balancedCount++;
                    else if (count[addIdx] == f + 1) balancedCount--;

                    if (i >= targetLen) {
                        int remIdx = s[i - targetLen] - 'a';
                        if (count[remIdx] == f) balancedCount--;
                        count[remIdx]--;
                        if (count[remIdx] == f) balancedCount++;
                        if (count[remIdx] == 0) distinctInWindow--;
                    }

                    if (distinctInWindow == k && balancedCount == k) {
                        maxLen = max(maxLen, targetLen);
                    }
                }
            }
        }
        return maxLen;
    }
};