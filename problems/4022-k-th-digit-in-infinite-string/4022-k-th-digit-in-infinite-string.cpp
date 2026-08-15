class Solution {
public:
    int kthDigit(long long k) {
        if (k<=9)
            return k;
        k-=9;
        long long n=2,b=1;
        while(true)
            {
                long long cnt=9;
                for(int i=2;i<n;i++)
                    cnt*=10;
                long long blk=cnt*10*n;
                if (k>blk)
                {
                    k-=blk;
                    b*=10;
                    n++;
                }
                else
                {
                    long long pos=(k-1)/n;
                    long long c=(k-1)%n;
                    long long x=b+pos/10;
                    long long y=pos%10;
                    long long m;
                    if (x%2==0)
                        m=10*x+y;
                    else
                        m=10*x+9-y;
                    for(long long i=0;i<n-1-c;i++)
                        m/=10;
                    return m%10;
                }
            }
    }
};