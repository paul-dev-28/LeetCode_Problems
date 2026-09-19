class Solution
{
public:
    int power(long long a,long long b)
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
        int p=0;
        for(int x:b)
            p=(p*10+x)%1140;
        if(p==0)
            p=1140;
        return power(a,p);
    }
};