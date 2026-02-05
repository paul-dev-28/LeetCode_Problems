class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        short int n=nums.size();
        vector<int> result(n,1);
        for(int i=0;i<n;i++)
        {
            short int k=((i+nums[i])%n+n)%n;
            result[i]=nums[k];
        }
        return result;
    }
};