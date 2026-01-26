class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        int maxv = 0, maxc = 0;

        for (char c : s) {
            char lowC = tolower(c);
            if (isalpha(lowC)) {
                freq[lowC - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            char current = i + 'a';
            if (current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u') {
                maxv = max(maxv, freq[i]);
            } else {
                maxc = max(maxc, freq[i]);
            }
        }

        return maxv + maxc;
    }
};