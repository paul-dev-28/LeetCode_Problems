class Solution {
public:
    int addDigits(int num) {
        int rem=0,t=0,c=0;
        if (num>=0 && num<10)
            return num;
        while(num>0)
        {
            rem=num%10;
            num/=10;
            t+=rem;
            if (num==0)
                c++;
            if (num==0 && t>=10)
            {
                num=t;
                t=0;
            }
            else if(num==0 && t<10)
                return t;
        }
        return 0;
    }
};