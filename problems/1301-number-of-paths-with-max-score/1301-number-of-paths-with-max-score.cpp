class Solution {
public:
    static const int MOD=1e9+7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<vector<int>> ways(n,vector<int>(n,0));

        dp[0][0]=0;
        ways[0][0]=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='X' || (i==0 && j==0))
                    continue;

                int mx=-1;
                long long cnt=0;

                if(i>0 && dp[i-1][j]!=-1)
                {
                    if(dp[i-1][j]>mx)
                    {
                        mx=dp[i-1][j];
                        cnt=ways[i-1][j];
                    }
                    else if(dp[i-1][j]==mx)
                    {
                        cnt=(cnt+ways[i-1][j])%MOD;
                    }
                }

                if(j>0 && dp[i][j-1]!=-1)
                {
                    if(dp[i][j-1]>mx)
                    {
                        mx=dp[i][j-1];
                        cnt=ways[i][j-1];
                    }
                    else if(dp[i][j-1]==mx)
                    {
                        cnt=(cnt+ways[i][j-1])%MOD;
                    }
                }

                if(i>0 && j>0 && dp[i-1][j-1]!=-1)
                {
                    if(dp[i-1][j-1]>mx)
                    {
                        mx=dp[i-1][j-1];
                        cnt=ways[i-1][j-1];
                    }
                    else if(dp[i-1][j-1]==mx)
                    {
                        cnt=(cnt+ways[i-1][j-1])%MOD;
                    }
                }

                if(mx==-1)
                    continue;

                dp[i][j]=mx;

                if(board[i][j]>='1' && board[i][j]<='9')
                    dp[i][j]+=board[i][j]-'0';

                ways[i][j]=cnt;
            }
        }

        if(dp[n-1][n-1]==-1)
            return {0,0};

        return {dp[n-1][n-1],ways[n-1][n-1]};
    }
};