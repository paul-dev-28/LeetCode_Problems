class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=0;j<nums.size()-i-1;j++)
            {
                if (nums[j]>nums[j+1])
                    swap(nums[j],nums[j+1]);
            }
            if (i>0)
            {
                if(nums[i]==nums[i-1])
                    return nums[i];
            }
            if (i==nums.size()-2)
                return nums[i+1];
        }
        return 0;
    }
};