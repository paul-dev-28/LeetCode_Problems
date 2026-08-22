class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> dp(cols,vector<int>(cols,-1));
        dp[0][cols-1]=grid[0][0]+grid[0][cols-1];
        for(int i=1;i<rows;i++)
        {
            vector<vector<int>> temp(cols,vector<int>(cols,-1));
            for(int j1=0;j1<cols;j1++)
            {
                for(int j2=0;j2<cols;j2++)
                {
                    if(dp[j1][j2]==-1)
                        continue;
                    for(int d1=-1;d1<=1;d1++)
                    {
                        for(int d2=-1;d2<=1;d2++)
                        {
                            int nj1=j1+d1;
                            int nj2=j2+d2;
                            if(nj1<0 || nj1>=cols || nj2<0 || nj2>=cols)
                                continue;
                            int cherries=grid[i][nj1];
                            if(nj1!=nj2)
                                cherries+=grid[i][nj2];
                            temp[nj1][nj2]=max(temp[nj1][nj2],dp[j1][j2]+cherries);
                        }
                    }
                }
            }
            dp=temp;
        }
        int ans=0;
        for(int j1=0;j1<cols;j1++)
        {
            for(int j2=0;j2<cols;j2++)
                ans=max(ans,dp[j1][j2]);
        }
        return ans;
    }
};