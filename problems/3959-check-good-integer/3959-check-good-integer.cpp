class Solution {
public:
    bool checkGoodInteger(int n) {
        long long sum=0LL;
        while(n>0)
            {
                sum+=(((n%10)*(n%10))-(n%10));
                n/=10;
            }
        return (sum>=50);
    }
};