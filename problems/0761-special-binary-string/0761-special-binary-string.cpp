class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, i = 0;
        vector<string> substrings;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '1') count++;
            else count--;
            if (count == 0) {
                substrings.push_back("1" + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + "0");
                i = j + 1;
            }
        }
        sort(substrings.begin(), substrings.end(), greater<string>());
        string res = "";
        for (const string& sub : substrings) res += sub;
        return res;
    }
};