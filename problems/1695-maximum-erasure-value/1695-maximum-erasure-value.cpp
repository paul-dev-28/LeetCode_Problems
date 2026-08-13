class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxi=0,i=0,j=0,total=0;
        unordered_map<int,int> mpp;
        while(i<nums.size())
        {
            mpp[nums[i]]++;
            while(mpp[nums[i]]>1)
            {
                total-=nums[j];
                mpp[nums[j]]--;
                j++;
            }
            if (mpp[nums[i]]==1)
            {
                total+=nums[i];
                maxi=max(maxi,total);
                i++;
            }
        }
        return maxi;
    }
};