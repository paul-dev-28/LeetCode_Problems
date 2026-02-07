class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int total_a = 0;
        for (char c : s) if (c == 'a') total_a++;
        
        int min_deletions = total_a; 
        int b_left = 0;
        int a_left = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a_left++;
            else b_left++;
            int current_deletions = b_left + (total_a - a_left);
            min_deletions = min(min_deletions, current_deletions);
        }
        
        return min_deletions;
    }
};