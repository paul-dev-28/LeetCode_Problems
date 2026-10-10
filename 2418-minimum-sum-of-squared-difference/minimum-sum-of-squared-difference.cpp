class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,vector<int>& nums2,int k1,int k2)
    {
        int n=nums1.size();
        long long k=(long long)k1+k2;
        vector<int> cnt(100001,0);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            int d=abs(nums1[i]-nums2[i]);
            cnt[d]++;
            mx=max(mx,d);
        }
        for(int d=mx;d>0 && k>0;d--)
        {
            if(cnt[d]==0)
                continue;
            long long take=min(k,(long long)cnt[d]);
            cnt[d]-=take;
            cnt[d-1]+=take;
            k-=take;
        }
        long long ans=0;
        for(int d=1;d<=100000;d++)
            ans+=1LL*d*d*cnt[d];
        return ans;
    }
};