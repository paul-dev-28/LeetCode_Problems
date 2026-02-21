class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int c=0,ctr=0;
        for(int i=left;i<=right;i++)
        {
            int n=i;
            while(n>0)
            {
                if (n%2!=0)
                    c++;
                n/=2;
            }
            if (c==2 || c==3 || c==5 || c==7 || c==11 || c==13 || c==17 || c==19 || c==23)
                ctr++;
            c=0;
        }
        return ctr;
    }
};