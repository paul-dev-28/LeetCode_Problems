class Solution {
public:
    bool isHappy(int n) {
        int no=0;
        while(n>0)
        {
            int digit=n%10;
            no+=(digit*digit);
            n/=10;
            if ((no==1 || no==7) && n==0)
                return true;
            else if (no>=0 && no<=9 && n==0)
                break;
            else if (no>=10 && n==0)
            {
                n=no;
                no=0;
            }
        }
        return false;
    }
};