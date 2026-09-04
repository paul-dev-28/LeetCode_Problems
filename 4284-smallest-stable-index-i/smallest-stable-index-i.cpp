class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mx=nums[0];
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            mx=max(mx,nums[i]);
            int mn=*min_element(nums.begin()+i,nums.end());
            if ((mx-mn)<=k)
                return i;
        }
        return -1;
    }
};