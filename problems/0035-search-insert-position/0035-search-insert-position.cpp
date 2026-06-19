class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,u=nums.size()-1,mid=0;
        int ans = u+1;
        while(l<=u)
        {
            mid=(u+l)/2;
            if (target<=nums[mid])
            {
                    ans=mid;
                    u=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};