class Solution {
public:
    static const int MOD=1e9+7;
    string s1,s2,t;
    int n,m,l;
    int dp[101][101][101][4];
    int dfs(int pos,int i,int j,int mk)
    {
        if (pos==l)
            return (mk==3);
        int &ans=dp[pos][i][j][mk];
        if (ans!=-1)
            return ans;
        ans=0;
        for(int x=i;x<n;x++)
            {
                if (s1[x]==t[pos])
                    ans=(ans+dfs(pos+1,x+1,j,mk|1))%MOD;
            }
        for(int y=j;y<m;y++)
            {
                if (s2[y]==t[pos])
                    ans=(ans+dfs(pos+1,i,y+1,mk|2))%MOD;
                
            }
        return ans;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        s1=word1;
        s2=word2;
        t=target;
        n=s1.size();
        m=s2.size();
        l=t.size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,0,0);
    }
};