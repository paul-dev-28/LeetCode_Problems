class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        if (k==1)
        {
            int maxi=INT_MIN;
            for(int i=0;i<nums.size();i++)
            {
                if (mpp[nums[i]]==1 && nums[i]>maxi)
                    maxi=nums[i];
            }
            if (maxi=INT_MIN)
                return -1;
            else
                return maxi;
        }
        if (k==nums.size())
        {
            int maxi=INT_MIN;
            for(int i=0;i<nums.size();i++)
            {
                maxi=max(maxi,nums[i]);
            }
            return maxi;
        }
        if (mpp[nums[0]]==1 && mpp[nums[nums.size()-1]]==1)
        {
            if (nums[0]>nums[nums.size()-1])
                return nums[0];
            else if (nums[0]<nums[nums.size()-1])
                return nums[nums.size()-1];
        }
        else if (mpp[nums[0]]==1)
            return nums[0];
        else if (mpp[nums[nums.size()-1]]==1)
            return nums[nums.size()-1];
        return -1;
    }
};