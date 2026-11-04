class Solution {
public:
    long long minOperations(vector<int>& nums,int x,int k)
    {
        int n=nums.size();
        multiset<int> l,r;
        long long sl=0,sr=0;
        auto balance=[&]()
        {
            while(l.size()>r.size()+1)
            {
                int v=*l.rbegin();
                l.erase(l.find(v));
                sl-=v;
                r.insert(v);
                sr+=v;
            }
            while(l.size()<r.size())
            {
                int v=*r.begin();
                r.erase(r.find(v));
                sr-=v;
                l.insert(v);
                sl+=v;
            }
        };
        auto add=[&](int v)
        {
            if(l.empty() || v<=*l.rbegin())
            {
                l.insert(v);
                sl+=v;
            }
            else
            {
                r.insert(v);
                sr+=v;
            }
            balance();
        };
        auto remove=[&](int v)
        {
            auto it=l.find(v);
            if(it!=l.end())
            {
                l.erase(it);
                sl-=v;
            }
            else
            {
                it=r.find(v);
                r.erase(it);
                sr-=v;
            }
            balance();
        };
        vector<long long> cost(n-x+1);
        for(int i=0;i<n;i++)
        {
            add(nums[i]);
            if(i>=x)
                remove(nums[i-x]);
            if(i>=x-1)
            {
                long long med=*l.rbegin();
                cost[i-x+1]=med*l.size()-sl+sr-med*r.size();
            }
        }
        const long long INF=1e18;
        vector<vector<long long>> dp(n+1,vector<long long>(k+1,INF));
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(i>=x && dp[i-x][j-1]!=INF)
                    dp[i][j]=min(dp[i][j],dp[i-x][j-1]+cost[i-x]);
            }
        }
        return dp[n][k];
    }
};