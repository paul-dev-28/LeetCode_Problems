class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string temp;

        for(char c : s) {
            if(c != '-')
                temp += toupper(c);
        }

        string ans;
        int cnt = 0;

        for(int i = temp.size() - 1; i >= 0; i--) {
            if(cnt == k) {
                ans += '-';
                cnt = 0;
            }

            ans += temp[i];
            cnt++;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};