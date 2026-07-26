class Solution
{
public:
    int largestPrime(int n)
    {
        if(n<2)
            return 0;
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i])
            {
                for(int j=i*i;j<=n;j+=i)
                    prime[j]=false;
            }
        }
        long long sum=0;
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(!prime[i])
                continue;
            sum+=i;
            if(sum>n)
                break;
            if(prime[sum])
                ans=sum;
        }
        return ans;
    }
};