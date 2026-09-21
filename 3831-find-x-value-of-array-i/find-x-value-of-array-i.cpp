class Solution {
public:
    vector<long long> resultArray(vector<int>& nums,int k) {
        vector<long long> ans(k),dp(k);
        for(int x:nums)
        {
            vector<long long> ndp(k);
            ndp[x%k]++;
            for(int j=0;j<k;j++)
            {
                if(dp[j])
                    ndp[(j*(x%k))%k]+=dp[j];
            }
            dp=ndp;
            for(int j=0;j<k;j++)
                ans[j]+=dp[j];
        }
        return ans;
    }
};