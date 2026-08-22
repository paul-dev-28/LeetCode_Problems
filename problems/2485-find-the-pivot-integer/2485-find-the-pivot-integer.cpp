class Solution {
public:
    int pivotInteger(int n) {
        int total=n*(n+1)/2;
        for(int i=1;i<=n;i++)
        {
            int t1=i*(i+1)/2;
            int t2=total+i-t1;
            if (t1==t2)
                return i;
        }
        return -1;
    }
};