class Solution {
public:
    int minDays(int n) {
        const int INF=1e9;
        vector<int>dp(n+1,INF);
        dp[0]=0;
        for(int s=0;s<=n;s++)
        {
            if(dp[s]==INF)
                continue;
            for(int k=1;s+k*(k+1)/2<=n;k++)
            {
                int x=k*(k+1)/2;
                int add=k+(s>0);
                dp[s+x]=min(dp[s+x],dp[s]+add);
            }
        }
        return dp[n];
    }
};