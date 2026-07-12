class Solution {
public:
    long long path(vector<string> &grid,int m,int n)
    {
        if (grid[0][0]=='#' || grid[m-1][n-1]=='#')
            return 0;
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        if (grid[i][j]=='#')
                        {
                            dp[i][j]=0;
                            continue;
                        }
                        if (i)
                            dp[i][j]+=dp[i-1][j];
                        if (j)
                            dp[i][j]+=dp[i][j-1];
                    }
            }
        return dp[m-1][n-1];
    }
    vector<string> createGrid(int m, int n, int k) {
        vector<string> grid(m,string(n,'.'));
        if (path(grid,m,n)<k)
            return {};
        for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        if ((i==0 && j==0) || (i==m-1 && j==n-1))
                            continue;
                        grid[i][j]='#';
                        if (path(grid,m,n)<k)
                            grid[i][j]='.';
                    }
            }
        if (path(grid,m,n)==k)
            return grid;
        return {};
    }
};