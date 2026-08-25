class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums,int k)
    {
        int sum=0;
        for(int x:nums)
            sum+=x;
        if(sum%k!=0)
            return false;
        int target=sum/k;
        sort(nums.rbegin(),nums.rend());
        if(nums[0]>target)
            return false;
        vector<bool> used(nums.size(),false);
        return helper(nums,used,k,target,0,0);
    }
    bool helper(vector<int>& nums,vector<bool>& used,int k,int target,int curr,int start)
    {
        if(k==1)
            return true;
        if(curr==target)
            return helper(nums,used,k-1,target,0,0);
        for(int i=start;i<nums.size();i++)
        {
            if(used[i])
                continue;
            if(curr+nums[i]>target)
                continue;
            if(i>start && nums[i]==nums[i-1] && !used[i-1])
                continue;
            used[i]=true;
            if(helper(nums,used,k,target,curr+nums[i],i+1))
                return true;
            used[i]=false;
            if(curr==0)
                return false;
        }
        return false;
    }
};