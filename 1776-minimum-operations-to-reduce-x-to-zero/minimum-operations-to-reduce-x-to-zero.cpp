class Solution
{
public:
    int minOperations(vector<int>& nums,int x)
    {
        int n=nums.size();
        long long total=0;
        for(int i=0;i<n;i++)
            total+=nums[i];
        long long target=total-x;
        if(target<0)
            return -1;
        if(target==0)
            return n;
        long long sum=0;
        int l=0,mx=-1;
        for(int r=0;r<n;r++)
        {
            sum+=nums[r];
            while(l<=r && sum>target)
            {
                sum-=nums[l];
                l++;
            }
            if(sum==target)
                mx=max(mx,r-l+1);
        }
        if(mx==-1)
            return -1;
        return n-mx;
    }
};