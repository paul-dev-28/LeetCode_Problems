class Solution {
public:
    bool checkPerfectNumber(int num) {
        long long int t=0LL;
        for(int i=1;i<=num/2;i++)
        {
            if (num%i==0)
                t+=i;
        }
        return (t==num);
    }
};