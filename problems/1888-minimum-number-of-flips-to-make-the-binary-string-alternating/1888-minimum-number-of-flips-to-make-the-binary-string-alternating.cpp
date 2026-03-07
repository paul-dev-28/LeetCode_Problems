class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string doubled = s + s;
        string target1 = "", target2 = "";
        for (int i = 0; i < doubled.length(); ++i) {
            target1 += (i % 2 == 0) ? '0' : '1';
            target2 += (i % 2 == 0) ? '1' : '0';
        }
        int diff1 = 0, diff2 = 0;
        int min_operations = n;
        for (int i = 0; i < doubled.length(); ++i) {
            if (doubled[i] != target1[i]) diff1++;
            if (doubled[i] != target2[i]) diff2++;
            if (i >= n) {
                if (doubled[i - n] != target1[i - n]) diff1--;
                if (doubled[i - n] != target2[i - n]) diff2--;
            }
            if (i >= n - 1) {
                min_operations = min({min_operations, diff1, diff2});
            }
        }
        
        return min_operations;
    }
};