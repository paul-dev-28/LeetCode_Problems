class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n>0)
        {
            int rem1=n%2;
            int rem2=(n/2)%2;
            n/=2;
            if (rem1==rem2)
                return false;
        }
        return true;

    }
};