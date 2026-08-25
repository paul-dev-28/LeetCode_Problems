class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int hash[101];
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i]%k==0)
            {
                hash[nums[i]/k]++;
            }
        }
        for(int i=1;i<101;i++)
        {
            if (hash[i]==0)
                return k*i;
        }
        return 101;
    }
};