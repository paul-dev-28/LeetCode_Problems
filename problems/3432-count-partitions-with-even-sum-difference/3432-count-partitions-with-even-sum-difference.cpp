class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int t=0,f=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            t+=nums[i];
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            f+=nums[i];
            if (((t-f)-f)%2==0)
                c++;
        }
        return c;
    }
};