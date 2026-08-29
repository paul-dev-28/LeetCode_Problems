class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int d=-1;d<n;d++)
            {
                vector<int> a;
                for(int i=0;i<n;i++)
                    {
                        if (i!=d)
                            a.push_back(nums[i]);
                    }
                int m=a.size();
                if (m<2)
                    continue;
                vector<int> s(m+1,0);
                for(int i=m-1;i>=0;i--)
                    s[i]=gcd(a[i],s[i+1]);
                int l=0,sc=0;
                for(int i=0;i<m-1;i++)
                    {
                        l=gcd(l,a[i]);
                        if (l==s[i+1])
                            sc++;
                    }
                ans=max(ans,sc);
            }
        return ans;
    }
};