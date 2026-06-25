class Solution {
public:
    double myPow(double x, int n) {
        long long n1=n;
        double ans=1LL;
        bool sign=false;
        if (n1<0)
            sign=true;
        n1=llabs(n1);
        while(n1>0)
        {
            if (n1&1)
            {
                ans*=x;
                n1--;
            }
            else
            {
                x*=x;
                n1/=2;
            }
        }
        if (sign)
            ans=(double)1.0/(double)(ans);
        return ans;
    }
};