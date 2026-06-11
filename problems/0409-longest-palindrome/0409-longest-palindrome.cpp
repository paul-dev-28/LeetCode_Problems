class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128] = {0};

        for(char c : s)
            freq[c]++;

        int ans = 0;

        for(int count : freq) {
            ans += (count / 2) * 2;
            if(ans % 2 == 0 && count % 2 == 1)
                ans++;
        }

        return ans;
    }
};