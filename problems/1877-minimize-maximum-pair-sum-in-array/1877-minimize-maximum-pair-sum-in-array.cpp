class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int c=nums.size()-1,i=0;
        sort(nums.begin(),nums.end());
        int max=nums[0]+nums[c];
        while(i<c)
        {
            if (nums[i]+nums[c]>max)
                max=nums[i]+nums[c];
            c--;
            i++;
        }
        return max;
    }
};