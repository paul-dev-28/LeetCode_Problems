class Solution {
public:
    bool validDigit(int n, int x) {
        int c=0;
        if (n==x)
            return false;
        while(n>0)
        {
            if (n%10==x)
                c++;
            n/=10;
            if (n==x && n>0)
                return false;
        }
        if (c>=1)
            return true;
        return false;
    }
};