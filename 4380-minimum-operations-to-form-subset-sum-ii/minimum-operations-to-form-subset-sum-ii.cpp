class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF=1e9;
        vector<int>dp(sum+1,INF);
        dp[0]=0;
        for(int x:nums)
        {
            map<int,int>mp;
            long long y=x;
            int div=0;
            while(y)
            {
                long long z=y;
                int mul=0;
                while(z<=sum)
                {
                    if(!mp.count(z))
                        mp[z]=div+mul;
                    else
                        mp[z]=min(mp[z],div+mul);
                    if(z>sum/2)
                        break;
                    z*=2;
                    mul++;
                }
                y/=2;
                div++;
            }
            vector<int>ndp=dp;
            for(auto [v,c]:mp)
            {
                for(int j=v;j<=sum;j++)
                {
                    if(dp[j-v]!=INF)
                        ndp[j]=min(ndp[j],dp[j-v]+c);
                }
            }
            dp.swap(ndp);
        }
        return dp[sum]==INF?-1:dp[sum];
    }
};