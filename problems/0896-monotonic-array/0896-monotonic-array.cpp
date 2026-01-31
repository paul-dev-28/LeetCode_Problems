class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if (nums[i+1]>nums[i])
            {
                k=1;
                break;
            }
        }
        if (k==1){
        for(int i=0;i<nums.size()-1;i++)
        {
            if (nums[i+1]<nums[i])
                return false;
        }}
        else
        {
            for(int i=0;i<nums.size()-1;i++)
        {
            if (nums[i+1]>nums[i])
                return false;
        }}
        return true;
    }
};