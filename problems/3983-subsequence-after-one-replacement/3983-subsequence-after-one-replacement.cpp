class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size(),j=0;
        if (n>m)
            return false;
        const int INF = 1e9;
        vector<int> p(n,INF),su(n,-INF);
        for(int i=0;i<n;i++)
            {
                while(j<m && s[i]!=t[j])
                    {
                        j++;
                    }
                if (j<m)
                {
                    p[i]=j;
                    j++;
                }
                else
                {
                   break;
                }
            }
        if (p[n-1]!=INF)
            return true;
        j=m-1;
        for(int i=n-1;i>=0;i--)
            {
                while(j>=0 && s[i]!=t[j])
                    j--;
                if (j>=0)
                {
                    su[i]=j;
                    j--;
                }
                else
                {
                   break;
                }
            }
            for(int i=0;i<n;i++)
                {
                    int l,r;
                    if (i==0)
                    {
                        l=-1;
                    }
                    else
                        l=p[i-1];
                    if (i==n-1)
                    {
                        r=m;
                    }
                    else
                        r=su[i+1];
                    if (l!=INF && r!=-INF && r-l>1)
                        return true;
                }
        return false;
        
    }
};