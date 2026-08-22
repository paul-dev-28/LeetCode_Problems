class Solution
{
public:
    string toHex(int num)
    {
        if(num==0)
            return "0";
        unsigned int n=num;
        string s="";
        string h="0123456789abcdef";
        while(n>0)
        {
            s+=h[n&15];
            n>>=4;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};