class Solution
{
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries)
    {
        int mx=*max_element(nums.begin(),nums.end());
        vector<long long> f(mx+1),mul(mx+1),cnt(mx+1),pre(mx+1);
        for(int x:nums)
            f[x]++;
        for(int i=1;i<=mx;i++)
        {
            for(int j=i;j<=mx;j+=i)
                mul[i]+=f[j];
            cnt[i]=mul[i]*(mul[i]-1)/2;
        }
        for(int i=mx;i>=1;i--)
        {
            for(int j=i+i;j<=mx;j+=i)
                cnt[i]-=cnt[j];
        }
        for(int i=1;i<=mx;i++)
            pre[i]=pre[i-1]+cnt[i];
        vector<int> ans;
        for(long long x:queries)
        {
            int l=1,r=mx,res=mx;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(pre[mid]>x)
                {
                    res=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};