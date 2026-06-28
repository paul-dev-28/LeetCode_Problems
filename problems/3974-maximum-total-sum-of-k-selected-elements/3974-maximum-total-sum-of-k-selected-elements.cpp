class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());
        vector<long long> v;
        for(int i=0;i<k;i++)
            v.push_back(nums[i]);
        sort(v.begin(),v.end());
        long long sum=0LL;
        int l=0,r=k-1;
        for(int i=mul;i>=mul-k+1;i--)
        {
            if (i>1)
            {
                sum+=v[r]*i;
                r--;
            }
            else
            {
                sum+=v[l];
                l++;
            }
        }
        return sum;
    }
};