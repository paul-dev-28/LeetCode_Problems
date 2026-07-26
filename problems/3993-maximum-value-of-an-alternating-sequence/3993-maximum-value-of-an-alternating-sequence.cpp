class Solution
{
public:
    long long maximumValue(int n, int s, int m)
    {
        if(n==1)
            return s;

        long long ans=s;

        long long t1=(n-2)/2;
        ans=max(ans,1LL*s+(t1+1)*1LL*m-t1);

        long long t2=(n-1)/2;
        ans=max(ans,1LL*s+t2*1LL*(m-1));

        return ans;
    }
};