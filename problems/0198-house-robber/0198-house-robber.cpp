class Solution {
public:
    int rob(vector<int>& nums) {
        int a=0,b=0;
        for(int x:nums)
        {
            int c=max(b,a+x);
            a=b;
            b=c;
        }
        return b;
    }
};