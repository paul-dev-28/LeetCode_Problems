class Solution {
public:
    vector<string> ans;
    string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string& digits,int i,string& s)
    {
        if(i==digits.size())
        {
            ans.push_back(s);
            return;
        }
        string& x=mp[digits[i]-'0'];
        for(char c:x)
        {
            s.push_back(c);
            solve(digits,i+1,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};
        string s;
        solve(digits,0,s);
        return ans;
    }
};