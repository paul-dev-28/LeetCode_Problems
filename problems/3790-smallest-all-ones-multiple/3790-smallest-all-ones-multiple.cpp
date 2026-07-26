class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k%2==0 || k%5==0)
            return -1;
        long long i=1%k;
        int c=1;
        while(i!=0)
        {
            c++;
            i=(i*10+1)%k;
        }
        return c;
    }
};