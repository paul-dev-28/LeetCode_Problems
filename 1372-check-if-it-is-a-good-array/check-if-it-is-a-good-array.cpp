class Solution {
public:
    bool isGoodArray(vector<int>& nums)
    {
        int g=0;
        for(int x:nums)
        {
            g=__gcd(g,x);
            if(g==1)
                return true;
        }
        return false;
    }
};