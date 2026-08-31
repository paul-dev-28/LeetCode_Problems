class Solution {
public:
    bool prime(int x)
    {
        if(x<2)
            return false;
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
                return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(prime(nums[i][i]))
                ans=max(ans,nums[i][i]);
            if(prime(nums[i][n-i-1]))
                ans=max(ans,nums[i][n-i-1]);
        }
        return ans;
    }
};