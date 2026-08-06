class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true)
        {
            int no=n,p=1;
            while(no!=0)
            {
                p*=(no%10);
                no/=10;
            }
            if (p%t==0)
                return n;
            n++;
            if (n>100)
                break;
        }
        return -1;
    }
};