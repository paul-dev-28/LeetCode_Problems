class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size(),ans=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i)
            {
                if(ans==-1)
                    ans=nums[i];
                else
                    ans&=nums[i];
            }
        }
        return max(0,ans);
    }
};