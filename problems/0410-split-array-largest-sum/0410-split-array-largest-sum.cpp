class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end()),high=0,mid=0;
        for(int x:nums)
            high+=x;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            int array=1,sum=0;
            for(int i=0;i<nums.size();i++)
            {
                if (sum+nums[i]<=mid)
                    sum+=nums[i];
                else
                {
                    array++;
                    sum=nums[i];
                }
            }
            if (array<=k)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};