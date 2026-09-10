class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF=1e9;
        vector<int>dp(sum+1,INF);
        dp[0]=0;
        for(int x:nums)
        {
            vector<pair<int,int>>v;
            for(int y=x,c=0;y<=sum;c++,y*=2)
                v.push_back({y,c});
            for(int y=x,c=0;y;y/=2,c++)
                v.push_back({y,c});
            vector<int>ndp=dp;
            for(auto [y,c]:v)
            {
                for(int j=sum;j>=y;j--)
                {
                    if(dp[j-y]!=INF)
                        ndp[j]=min(ndp[j],dp[j-y]+c);
                }
            }
            dp.swap(ndp);
        }
        return dp[sum]==INF?-1:dp[sum];
    }
};