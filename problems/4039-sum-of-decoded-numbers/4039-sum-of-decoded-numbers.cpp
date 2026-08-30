class Solution {
public:
    long long power(long long n1,long long n2)
    {
        long long a=1;
        while(n2)
            {
                if (n2&1)
                    a=a*n1%1000000007;
                n1=n1*n1%1000000007;
                n2>>=1;
            }
        return a;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans=0;
        for(long long x:nums)
            {
                int w=x%10;
                long long d=x/10;
                string s=to_string(d);
                long long n1=stoi(s.substr(0,w));
                long long n2=stoi(s.substr(w));
                ans=(ans+power(n1,n2))%1000000007;
            }
        return ans;
    }
};