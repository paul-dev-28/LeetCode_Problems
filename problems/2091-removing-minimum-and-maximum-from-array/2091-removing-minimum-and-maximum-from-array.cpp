class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mxi=-1,mni=-1,mx=INT_MIN,mn=INT_MAX,n=nums.size();
        if (n==2)
            return 2;
        for(int i=0;i<n;i++)
        {
            if (nums[i]>mx)
            {
                mx=nums[i];
                mxi=i;
            }
            if (nums[i]<mn)
            {
                mn=nums[i];
                mni=i;
            }
        }
        int ans=n;
        ans=min(ans,max(mxi,mni)+1);
        ans=min(ans,n-min(mxi,mni));
        ans=min(ans,mxi+1+n-mni);
        ans=min(ans,mni+1+n-mxi);
        return ans;
    }
};