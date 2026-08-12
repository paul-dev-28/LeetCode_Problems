class Solution
{
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        unordered_map<int,int> mpp;
        int i=0,ans=0;
        for(int j=0;j<nums.size();j++)
        {
            mpp[nums[j]]++;
            while(mpp[nums[j]]>k)
            {
                mpp[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};