class Solution {
public:
    static const int MOD=1000000007;
    int subsequencePairCount(vector<int>& nums) {
        vector<vector<long long>> dp(201,vector<long long>(201,0));
        dp[0][0]=1;
        for(int x:nums)
        {
            vector<vector<long long>> ndp=dp;
            for(int g1=0;g1<=200;g1++)
            {
                for(int g2=0;g2<=200;g2++)
                {
                    if(dp[g1][g2]==0)
                        continue;
                    int ng1=(g1==0)?x:gcd(g1,x);
                    int ng2=(g2==0)?x:gcd(g2,x);
                    ndp[ng1][g2]=(ndp[ng1][g2]+dp[g1][g2])%MOD;
                    ndp[g1][ng2]=(ndp[g1][ng2]+dp[g1][g2])%MOD;
                }
            }
            dp=move(ndp);
        }
        long long ans=0;
        for(int g=1;g<=200;g++)
            ans=(ans+dp[g][g])%MOD;
        return ans;
    }
};