class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int i=0,j=nums.size()-1,c=0;
        while(i<j)
        {
            if (nums[i]!=0)
                i++;
            if (nums[j]==0)
                j--;
            if (nums[i]==0 && nums[j]!=0 && i<j)
            {
                swap(nums[i],nums[j]);
                c++;
                i++;
                j--;
            }
        }
        return c;
    }
};