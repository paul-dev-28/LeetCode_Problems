class Solution
{
public:
    int power(long long a,int b)
    {
        long long ans=1;
        a%=1337;
        while(b>0)
        {
            if(b&1)
                ans=ans*a%1337;
            a=a*a%1337;
            b>>=1;
        }
        return ans;
    }
    int superPow(int a,vector<int>& b)
    {
        long long ans=1;
        a%=1337;
        for(int x:b)
            ans=power(ans,10)*power(a,x)%1337;
        return ans;
    }
};