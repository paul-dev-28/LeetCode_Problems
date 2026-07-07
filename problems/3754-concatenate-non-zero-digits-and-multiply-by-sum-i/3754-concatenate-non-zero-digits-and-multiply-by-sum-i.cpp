class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0,no=0,sum=0;
        while(n>0)
        {
            int d=n%10;
            sum+=d;
            if (d!=0)
                x=x*10+d;
            n/=10;
        }
        while(x>0)
        {
            no=no*10+x%10;
            x/=10;
        }
        return no*sum;
    }
};