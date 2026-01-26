class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int t=0;
        for(int i=0;i<nums.size();i++)
        {
            t+=nums[i];
        }
        return (t%k);
    }
};