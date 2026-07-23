class Solution
{
public:
    int uniqueXorTriplets(vector<int>& nums)
    {
        int n=nums.size();
        if(n<3)
            return n;
        int b=0,x=n;
        while(x)
        {
            b++;
            x>>=1;
        }
        return 1<<b;
    }
};