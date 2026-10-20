class Solution {
public:
    bool check(vector<int>& nums,vector<int>& a,int start,int k)
    {
        vector<int> p(k),pi(k);
        for(int i=0;i<k;i++)
            p[i]=a[start+i];
        for(int i=1;i<k;i++)
        {
            int j=pi[i-1];
            while(j>0 && p[i]!=p[j])
                j=pi[j-1];
            if(p[i]==p[j])
                j++;
            pi[i]=j;
        }
        int j=0;
        for(int i=0;i<2*k-1;i++)
        {
            int x=nums[start+i%k];
            while(j>0 && x!=p[j])
                j=pi[j-1];
            if(x==p[j])
                j++;
            if(j==k)
                return true;
        }
        return false;
    }

    int sortableIntegers(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> a=nums;
        sort(a.begin(),a.end());
        int ans=0;
        for(int k=1;k<=n/k;k++)
        {
            if(n%k)
                continue;
            bool ok=true;
            for(int i=0;i<n && ok;i+=k)
                ok=check(nums,a,i,k);
            if(ok)
                ans+=k;
            int d=n/k;
            if(d!=k)
            {
                ok=true;
                for(int i=0;i<n && ok;i+=d)
                    ok=check(nums,a,i,d);
                if(ok)
                    ans+=d;
            }
        }
        return ans;
    }
};