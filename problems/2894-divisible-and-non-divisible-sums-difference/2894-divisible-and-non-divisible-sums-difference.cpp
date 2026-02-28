class Solution {
public:
    int differenceOfSums(int n, int m) {
        int t=0;
        for(int i=1;i<=n;i++)
        {
            if (i%m!=0)
                t+=i;
            else
                t-=i;
        }
        return t;
    }
};