class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pre(n+1,0);
        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+nums[i];
        vector<int> t(2*n+3);
        t[0]=-2;
        t[1]=-1;
        int p=2;
        for(int i=0;i<n;i++)
            {
                t[p++]=nums[i];
                t[p++]=-1;
            }
        t[p]=-3;
        vector<int> rad(t.size(),0);
        int c=0,r=0;
        for(int i=1;i<t.size()-1;i++)
            {
                int mir=2*c-i;
                if (i<r)
                    rad[i]=min(r-i,rad[mir]);
                while(t[i+rad[i]+1]==t[i-rad[i]-1])
                    rad[i]++;
                if (i+rad[i]>r)
                    {
                        c=i;
                        r=i+rad[i];
                    }
            }
        long long ans=LLONG_MIN;
        for(int i=2;i<t.size()-2;i++)
            {
                if (rad[i]==0)
                    continue;
                int l=(i-rad[i]-1)/2;
                int rr=l+rad[i]-1;
                ans=max(ans,pre[rr+1]-pre[l]);
            }
        return ans;
    }
};