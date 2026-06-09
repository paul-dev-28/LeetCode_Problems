class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        long long max=INT_MIN,sum=0LL;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if (sum>max)
            {
                max=sum;
            }
            if (sum<0)
                sum=0;
        }
        return max;
    }
};