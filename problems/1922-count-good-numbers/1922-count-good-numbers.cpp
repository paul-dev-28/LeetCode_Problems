class Solution {
public:
    int countGoodNumbers(long long n) {
        const long long MOD=1000000007;
        long long even=(n+1)/2;
        long long odd=n/2;
        auto power=[&](long long a,long long b)
        {
            long long res=1;
            while(b)
            {
                if(b&1)
                    res=res*a%MOD;
                a=a*a%MOD;
                b/=2;
            }
            return res;
        };
        return power(5,even)*power(4,odd)%MOD;
    }
};