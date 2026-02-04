class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size()==0 && t.size()==0)
            return true;
        int n=t.size();
        int c=0,ctr=0;
        for(int i=0;i<n;i++)
        {
            if (s[c]==t[i])
            {
                ctr++;
                c++;
            }
            if (c==s.size())
                return true;
        }
        return false;
    }
};