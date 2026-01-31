class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long int t=0LL;
        int c=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            t+=nums[i];
            if (t>0)
                c++;
        }
        return c;
    }
};