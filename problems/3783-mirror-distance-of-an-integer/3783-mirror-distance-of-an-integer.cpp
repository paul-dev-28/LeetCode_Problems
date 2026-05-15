class Solution {
public:
    int mirrorDistance(int n) {
        int no=n,n2=0;;
        while(no>0)
        {
            int d=no%10;
            n2=n2*10+d;
            no/=10;
        }
        return abs(n2-n);
    }
};