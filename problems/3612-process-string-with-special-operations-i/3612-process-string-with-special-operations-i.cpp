class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string result="";
        for(int i=0;i<n;i++)
        {
            if (islower(s[i]))
                result+=s[i];
            if (s[i]=='*' && result.size()>0)
                result.pop_back();
            if (s[i]=='#')
                result+=result;
            if (s[i]=='%')
                reverse(result.begin(),result.end());
        }
        
        return result;
    }
};