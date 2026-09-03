class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j] && (j-i<=1 || dp[i+1][j-1]))
                    dp[i][j]=true;
            }
        }
        vector<int>cut(n);
        for(int i=0;i<n;i++)
        {
            if(dp[0][i])
                cut[i]=0;
            else
            {
                cut[i]=i;
                for(int j=1;j<=i;j++)
                {
                    if(dp[j][i])
                        cut[i]=min(cut[i],cut[j-1]+1);
                }
            }
        }
        return cut[n-1];
    }
};