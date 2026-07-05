class Solution {
public:
    static const int MOD=1e9+7;
    int divisibleGame(vector<int>& nums) {
        int n=nums.size();
         unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            for(int j=1;1LL*j*j<=x;j++)
                {
                    if (x%j)
                        continue;
                    if (j>1)
                        mp[j].push_back(i);
                    if (x/j!=j && x/j>1)
                        mp[x/j].push_back(i);
                        
                }
            
        }
        vector<long long> pre(n+1,0);
        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+nums[i];
        long long b=LLONG_MIN;
        int val=2;
            for(auto &it:mp)
                {
                    int k=it.first;
                    vector<int> &v=it.second;
                    long long cur=0;
                    long long mx=LLONG_MIN;
                    for(int i=0;i<v.size();i++)
                        {
                            if (i)
                            {
                                long long gap=pre[v[i]]-pre[v[i-1]+1];
                                cur-=gap;
                                if (cur<0)
                                    cur=0;
                            }
                            cur+=nums[v[i]];
                            mx=max(mx,cur);
                            if (cur<0)
                                cur=0;
                        }
                    if (mx>b || (mx==b && k<val) )
                    {
                        b=mx;
                        val=k;
                    }
                }
        
        long long mx=LLONG_MIN;
        for(int x:nums)
            mx=max(mx,-1LL*x);
        if (!mp.count(2))
        {
            if (mx>b || (mx==b && 2<val))
            {
                b=mx;
                val=2;
            }
        }
        long long ans=((b%MOD)+MOD)%MOD;
        ans=(ans*val)%MOD;
        return ans;
    }
};