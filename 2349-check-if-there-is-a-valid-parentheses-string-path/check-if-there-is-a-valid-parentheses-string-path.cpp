class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid)
    {
        int m=grid.size(),n=grid[0].size();
        if((m+n-1)%2!=0)
            return false;
        if(grid[0][0]!='(' || grid[m-1][n-1]!=')')
            return false;
        vector<bitset<205>> dp(n);
        int bal=0;
        for(int j=0;j<n;j++)
        {
            bal+=(grid[0][j]=='('?1:-1);
            if(bal<0)
                break;
            dp[j].set(bal);
        }
        for(int i=1;i<m;i++)
        {
            vector<bitset<205>> newDp(n);
            for(int j=0;j<n;j++)
            {
                bitset<205> incoming;
                if(j>0)
                    incoming|=newDp[j-1];
                incoming|=dp[j];
                if(incoming.none())
                    continue;
                if(grid[i][j]=='(')
                    incoming<<=1;
                else
                    incoming>>=1;
                newDp[j]=incoming;
            }
            dp=move(newDp);
        }
        return dp[n-1].test(0);
    }
};