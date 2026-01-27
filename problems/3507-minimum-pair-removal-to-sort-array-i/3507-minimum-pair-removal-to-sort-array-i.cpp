class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int min=0,c=0;
        while(!(is_sorted(begin(nums),end(nums))))
        {
            min=nums[0]+nums[1];
            for(int i=0;i<nums.size()-1;i++)
            {
                if ((nums[i]+nums[i+1])<min)
                {
                    min=nums[i]+nums[i+1];
                }
            }
            for(int i=0;i<nums.size()-1;i++)
            {
                if ((nums[i]+nums[i+1])==min)
                {
                    nums[i]=nums[i]+nums[i+1];
                    nums.erase(nums.begin()+i+1);
                    c++;
                    break;
                }
            }
        }
        return c;
    }
};