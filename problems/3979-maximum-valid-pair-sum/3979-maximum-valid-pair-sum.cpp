class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int b=nums[0];
        int ans=INT_MIN;
        for(int i=k;i<nums.size();i++)
            {
                b=max(b,nums[i-k]);
                ans=max(ans,b+nums[i]);
            }
        return ans;
    }
};