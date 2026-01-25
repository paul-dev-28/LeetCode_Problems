class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c=0;
            for(int j=1;j<nums.size();j++)
            {
                if (nums[j]!=nums[c])
                {
                    c++;
                    nums[c]=nums[j];
                }
            }
             return c+1;
        

       
        }
    
};