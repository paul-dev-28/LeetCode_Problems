class Solution {
public:
    bool consecutiveSetBits(int n) {
        int rem1=-1,rem2=-1,c=0;
        while(n>0)
        {
            rem1=n%2;
            n/=2;
            if (rem1==1 && rem2==1)
                c++;
            rem2=rem1;
            rem1=-1;
        }
        if (c==1)
            return true;
        return false;
    }
};