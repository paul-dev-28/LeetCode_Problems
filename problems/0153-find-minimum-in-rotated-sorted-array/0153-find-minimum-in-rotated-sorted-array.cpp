class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if (n==1)
            return nums[0];
        if (nums[n-1]>nums[0])
            return nums[0];
        
        int c=n;
        while(nums[c-1]<nums[0] && c>0)
            c--;
        return nums[c];
    }
};