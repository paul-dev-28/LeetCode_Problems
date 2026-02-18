class Solution {
public:
    int commonFactors(int a, int b) {
        short int c=0,i;
        for(i=1;i<=min(a,b);i++)
        {
            if (a%i==0 && b%i==0)
                c++;
        }
        return c;
    }
};