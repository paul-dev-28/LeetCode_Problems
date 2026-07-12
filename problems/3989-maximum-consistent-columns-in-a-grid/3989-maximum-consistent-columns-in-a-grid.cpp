class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dp(n,1);
        int ans=1;
        for(int j=1;j<n;j++)
            {
                for(int i=0;i<j;i++)
                    {
                        bool f=true;
                        for(int x=0;x<m;x++)
                            {
                                if (abs(grid[x][j]-grid[x][i])>limit)
                                {
                                    f=false;
                                    break;
                                }
                            }
                        if (f)
                            dp[j]=max(dp[j],dp[i]+1);
                    }
                ans=max(ans,dp[j]);
                
            }
        return ans;
    }
};