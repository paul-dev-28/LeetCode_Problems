class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> f(26);
        for(char c:word)
            f[c-'a']++;
        sort(f.begin(),f.end(),greater<int>());
        int ans=0;
        for(int i=0;i<26;i++)
            ans+=f[i]*(i/8+1);
        return ans;
    }
};