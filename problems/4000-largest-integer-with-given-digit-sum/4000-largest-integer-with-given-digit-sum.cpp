class Solution {
public:
    int largestInteger(int n, int s) {
        if ((n==2 && s>18) || (n==1 && s>9))
            return -1;
        if (s==0)
            return 0;
        if (s<10)
            return s*(int)pow(10,n-1);
        else
        {
            int num=9;
            n--;
            s-=9;
            while(s>0 && n>0)
            {
                if (s>9)
                    num=num*10+9;
                else
                {
                    num=num*10+s;
                }
                s=s-9;
                n--;
            }
            if (s>0)
                return -1;
            if (n!=0)
                num=num*(int)pow(10,n);
            return num;
        }
    }
};