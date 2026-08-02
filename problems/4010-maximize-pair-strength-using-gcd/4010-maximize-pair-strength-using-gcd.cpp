class Solution
{
public:
    long long maxPairStrength(vector<int>& nums)
    {
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                long long g=gcd(nums[i],nums[j]);
                ans=max(ans,1LL*(nums[i]/g)*(nums[j]/g));
            }
        }
        return ans;
    }
};