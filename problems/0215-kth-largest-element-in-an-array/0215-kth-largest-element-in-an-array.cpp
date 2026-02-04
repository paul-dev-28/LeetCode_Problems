class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int c=1;
        sort(nums.begin(),nums.end());
        return nums[n-k];
    }
};