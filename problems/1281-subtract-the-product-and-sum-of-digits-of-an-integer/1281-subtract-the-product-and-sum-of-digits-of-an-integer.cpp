class Solution {
public:
    int subtractProductAndSum(int n) {
        int p=1,t=0;
        while(n>0)
        {
            t+=(n%10);
            p*=(n%10);
            n/=10;
        }
        return (p-t);
    }
};