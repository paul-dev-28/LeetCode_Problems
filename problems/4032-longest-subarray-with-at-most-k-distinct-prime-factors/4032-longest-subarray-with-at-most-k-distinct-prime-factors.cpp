class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> cnt;
        int l=0,d=0,ans=0;
        for(int r=0;r<n;r++)
        {
            int x=nums[r];
            for(int p=2;p*p<=x;p++)
                {
                    if (x%p==0)
                    {
                        cnt[p]++;
                        if(cnt[p]==1)
                            d++;
                        while(x%p==0)
                            x/=p;
                        
                    }
                }
            if (x>1)
            {
                cnt[x]++;
                if (cnt[x]==1)
                    d++;
            }
            while(d>k)
            {
                x=nums[l];
                for(int p=2;p*p<=x;p++)
                {
                    if (x%p==0)
                    {
                        cnt[p]--;
                        if (cnt[p]==0)
                            d--;
                        while(x%p==0)
                            x/=p;
                    }
                }
                if (x>1)
                {
                    cnt[x]--;
                    if (cnt[x]==0)
                        d--;
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};