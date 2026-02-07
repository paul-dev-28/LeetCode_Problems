class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int c=0,ctr=0;
        for(int i=0;i<n;i++)
        {
            while(nums[i]>0)
            {
                c++;
                nums[i]/=10;
            }
            if (c%2==0)
                ctr++;
            c=0;
        }
        return ctr;
    }
};