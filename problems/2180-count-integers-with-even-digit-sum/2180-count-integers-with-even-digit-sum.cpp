class Solution {
public:
    int countEven(int num) {
        short int i,t=0,c=0;
        for(i=1;i<=num;i++)
        {
            short int n=i;
            while(n>0)
            {
                t+=n%10;
                n/=10;
            }
            if (t%2==0)
                c++;
            t=0;
        }
        return c;
    }
};