class Solution {
public:
    int numberOfSets(int n,int k) {
        const long long MOD=1e9+7;
        long long ans=1;
        for(int i=1;i<=2*k;i++)
        {
            ans=ans*(n+k-i)%MOD;
            ans=ans*modpow(i,MOD-2)%MOD;
        }
        return ans;
    }
    long long modpow(long long a,long long b) {
        long long ans=1;
        while(b)
        {
            if(b&1)
                ans=ans*a%1000000007;
            a=a*a%1000000007;
            b>>=1;
        }
        return ans;
    }
};