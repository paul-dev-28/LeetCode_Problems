class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        long long total=0LL;
        for(int i=0;i<n;i++)
        {
            if (i>0 && i<n-1 && nums[i]> nums[i-1] && nums[i]>nums[i+1])
            {
                total+=(nums[i]);
                for(int j=i;j<n;j++)
                {
                    total-=nums[j];
                }
                break;
            }
            total+=nums[i];
        }
        if (total>0)
            return 0;
        if (total<0)
            return 1;
        return -1;
    }
};