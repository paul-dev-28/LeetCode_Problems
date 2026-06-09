class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ctr=0,n=nums.size(),el=0;
        for(int i=0;i<n;i++)
        {
            if (ctr==0)
            {
                el=nums[i];
                ctr=1;
            }
            else if (nums[i]==el)
                ctr++;
            else
                ctr--;
        }
        return el;
    }
};