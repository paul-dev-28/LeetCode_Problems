class Solution {
public:
    int trailingZeroes(int n) {
        long int c=0;
        while(n>=5)
        {
            n/=5;
            c+=n;
        }
        return c;
    }
};