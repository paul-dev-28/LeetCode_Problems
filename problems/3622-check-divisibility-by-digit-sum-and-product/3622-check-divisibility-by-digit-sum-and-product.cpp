class Solution {
public:
    bool checkDivisibility(int n) {
        int prod=1;
        int sum=0;
        int nn=n;
        while(nn>0)
        {
            prod*=(nn%10);
            sum+=(nn%10);
            nn/=10;
        }
        if(n%(sum+prod)!=0)
            return false;
        return true;
    }
};