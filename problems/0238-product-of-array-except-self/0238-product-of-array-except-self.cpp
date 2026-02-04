class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int p=1;
        vector<int> a(n,1);
        for (int i=0;i<n;i++)
        {
            a[i]=p;
            p*=nums[i];
        }
        p=1;
        for (int i=n-1;i>=0;i--)
        {
            a[i]*=p;
            p*=nums[i];
        }
        return a;
    }
};