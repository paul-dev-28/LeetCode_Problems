class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const int MOD=1000000007;
        if (k==0)
        {
            for(int x:nums)
                if (x>0)
                    return -1;
            return 0;
        }
        long long c=k,ctr=0LL;
        for(int i=0;i<nums.size();i++)
            {
                if (c<nums[i])
                {
                    long long n=nums[i]-c;
                    long long add=(n+k-1)/k;
                    c+=add*1LL*k;
                    ctr+=add;
                    
                }
                c-=nums[i];
            }
        ctr=ctr%MOD;
        long long ans=(ctr%MOD)*((ctr+1)%MOD)%MOD;
        ans=ans*500000004LL%MOD;
        return (int)ans;
    }
};