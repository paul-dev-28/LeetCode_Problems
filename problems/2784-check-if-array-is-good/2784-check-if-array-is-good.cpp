class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if (n==1)
            return false;
        if (n==2 && nums[0]==1 && nums[1]==1)
            return true;
        for(int i=0;i<n-3;i++)
        {
            if (nums[i+1]==nums[i])
                return false;
        }
        if (n>=3 && nums[n-1]==n-1 && nums[n-2]==n-1 && nums[n-3]!=n-1)
            return true;
        else
            return false;
    }
};