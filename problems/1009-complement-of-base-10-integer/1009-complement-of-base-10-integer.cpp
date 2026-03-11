class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0)
            return 1;
        int c=0,complement=0;
        while(n>0)
        {
            if (n%2)
                complement+=(0*(int)(pow(2,c)));
            else
                complement+=(1*(int)(pow(2,c)));
            c++;
            n/=2;
        }
        return complement;
    }
};