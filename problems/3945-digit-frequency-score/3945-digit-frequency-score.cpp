class Solution {
public:
    int digitFrequencyScore(int n) {
        long long sum=0LL;
        while(n>0)
        {
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
};