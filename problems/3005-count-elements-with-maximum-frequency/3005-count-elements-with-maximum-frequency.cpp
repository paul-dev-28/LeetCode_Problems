class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int max=0,ctr=0,total=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();)
        {
            int c=nums[i];
            ctr=0;
            while(i<nums.size() && nums[i]==c)
            {
                ctr++;
                i++;
            }
            if (ctr>max)
                max=ctr;
            
        }
        for(int i=0;i<nums.size();)
        {
            int c=nums[i];
            ctr=0;
            while(i<nums.size() && nums[i]==c)
            {
                ctr++;
                i++;
            }
            if (ctr==max)
                total+=max;
            
        }
        return total;
    }
};