class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int c=0,max=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i]>max)
            {
                max=nums[i];
                c=i;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i]!=max && max<(nums[i]*2))
                return -1;
        }
        return c;
    }
};