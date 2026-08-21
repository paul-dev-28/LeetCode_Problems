class Solution {
public:
    using ll=long long;
    ll gcd(ll a,ll b)
    {
        while(b)
        {
            ll t=a%b;
            a=b;
            b=t;
        }
        return a;
    }
    ll lcm(ll a,ll b)
    {
        return a/gcd(a,b)*b;
    }
    long long findKthSmallest(vector<int>& coins,int k)
    {
        sort(coins.begin(),coins.end());
        vector<int> v;
        for(int x:coins)
        {
            bool flag=true;
            for(int y:v)
            {
                if(x%y==0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                v.push_back(x);
        }
        coins=v;
        int n=coins.size();
        int m=1<<n;
        vector<ll> lc(m,1);
        ll lo=k;
        ll hi=1LL*coins[0]*k;
        for(int mask=1;mask<m;mask++)
        {
            int pm=mask&(mask-1);
            int i=__builtin_ctz(mask);
            ll x=lc[pm]/gcd(lc[pm],coins[i]);
            if(x<=hi/coins[i])
                lc[mask]=x*coins[i];
            else
                lc[mask]=hi+1;
        }
        auto count=[&](ll x)
        {
            ll ans=0;
            for(int mask=1;mask<m;mask++)
            {
                if(lc[mask]>x)
                    continue;
                if(__builtin_popcount(mask)&1)
                    ans+=x/lc[mask];
                else
                    ans-=x/lc[mask];
            }
            return ans;
        };
        while(lo<hi)
        {
            ll mid=lo+(hi-lo)/2;
            if(count(mid)>=k)
                hi=mid;
            else
                lo=mid+1;
        }
        return lo;
    }
};