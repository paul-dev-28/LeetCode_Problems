class Solution {
public:
    int countDigits(int num) {
        int c=0,nn=num;
        while(num>0)
        {
            if (nn%(num%10)==0)
                c++;
            num/=10;
        }
        return c;
    }
};