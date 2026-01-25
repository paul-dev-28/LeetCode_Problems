class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,c=0,max=0;
        while(i<nums.size())
        {
            if (nums[i]==1)
            {
                c++;
            }
            else 
            {
                if (c>max)
                {
                    max=c;
                }
                c=0;
            }
            if (i==nums.size()-1)
            {
                if (c>max)
                {
                    max=c;
                }
                c=0;
            }
            i++;
        }
        return max;
    }
};