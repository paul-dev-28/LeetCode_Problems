class Solution {
public:
    long long cc(vector<int> &nums,int k, bool b)
    {
        long long dp0=nums[0];
        long long v=(b)? (1LL*nums[0]*k):(nums[0]/k);
        long long dp1=v;
        long long dp2=LLONG_MIN;
        long long ans=dp1;
        for(int i=1;i<nums.size();i++)
        {
            long long c=nums[i];
            if (b)
                v=1LL*c*k;
            else
                v=c/k;
            long long ndp0=max(c,dp0+c);
            long long ndp1=max({v,dp0+v,dp1+v});
            long long ndp2=dp1+c;
            if (dp2!=LLONG_MIN)
                ndp2=max(ndp2,dp2+c);
            dp0=ndp0;
            dp1=ndp1;
            dp2=ndp2;
            ans=max(ans,max(dp1,dp2));
        }
        return ans;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(cc(nums,k,true),cc(nums,k,false));
    }
};