class Solution {
public:
    int findComplement(int num) {
        if (num==0)
            return 1;
        int c=0,complement=0;
        while(num>0)
        {
            if (num%2)
                complement+=(0*(int)(pow(2,c)));
            else
                complement+=(1*(int)(pow(2,c)));
            c++;
            num/=2;
        }
        return complement;
    }
};