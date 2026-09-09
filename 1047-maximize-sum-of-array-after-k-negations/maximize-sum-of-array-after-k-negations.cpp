class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() && k;i++)
        {
            if(nums[i]<0)
            {
                nums[i]=-nums[i];
                k--;
            }
        }
        if(k%2)
        {
            int i=min_element(nums.begin(),nums.end(),[](int a,int b) {
                return abs(a)<abs(b);
            })-nums.begin();
            nums[i]=-nums[i];
        }
        int ans=0;
        for(int x:nums)
            ans+=x;
        return ans;
    }
};