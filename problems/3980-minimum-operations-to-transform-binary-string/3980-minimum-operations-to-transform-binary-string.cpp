class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.size();
        const long long INF=1e15;
        vector<long long> dp(2,INF);
        dp[0]=0;
        for(int i=0;i<n;i++)
            {
                vector<long long> nt(2,INF);
                for(int p=0;p<=1;p++)
                    {
                        if (dp[p]==INF)
                            continue;
                        long long cur=dp[p];
                        if (p && s1[i]=='0')
                            cur++;
                        int bit;
                        if (p)
                            bit=0;
                        else
                            bit=s1[i]-'0';
                        int t=s2[i]-'0';
                        if (bit==0 && t==1)
                            nt[0]=min(nt[0],cur+1);
                        else if (bit==t)
                            nt[0]=min(nt[0],cur);
                        if (i==n-1)
                            continue;
                        long long v=cur;
                        if (bit==0)
                            v++;
                        v++;
                        if(t==1)
                            v++;
                        nt[1]=min(nt[1],v);
                        
                    }
                dp=nt;
            }
        if (dp[0]==INF)
            return -1;
        return dp[0];
    }
};