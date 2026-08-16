class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<int> pre(n+1);
        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+stones[i];
        vector<vector<int>> dp(n,vector<int>(n));
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i+len<=n;i++)
            {
                int j=i+len-1;
                int left=pre[j+1]-pre[i+1];
                int right=pre[j]-pre[i];
                dp[i][j]=max(left-dp[i+1][j],right-dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};