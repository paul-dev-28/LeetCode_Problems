class Solution
{
public:
    string smallestPalindrome(string s)
    {
        vector<int> f(26);
        for(char c:s)
            f[c-'a']++;
        string l,m;
        for(int i=0;i<26;i++)
        {
            while(f[i]>=2)
            {
                l.push_back('a'+i);
                f[i]-=2;
            }
            if(f[i])
                m.push_back('a'+i);
        }
        string r=l;
        reverse(r.begin(),r.end());
        return l+m+r;
    }
};