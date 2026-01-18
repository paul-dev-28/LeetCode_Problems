class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        if (n==1)
            return nums[0];
        if (n==2)
            {
                if(nums[0]>nums[1])
                    return nums[0];
                else
                    return nums[1];
            }
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if (nums[j]>nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        short int ctr=0;
        int k=0;
        for(int i=n-1;i>0;i--)
        {
            if (nums[i-1]!=nums[i])
            {
                ctr++;
                k=(i-1);
            }
            if (ctr==2)
                break;
        }
        if (ctr==1)
            return nums[(n-1)];
        return nums[k];
    }
};