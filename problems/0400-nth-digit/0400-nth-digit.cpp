class Solution
{
public:
    int findNthDigit(int n)
    {
        long long len=1,cnt=9,start=1;
        while(n>len*cnt)
        {
            n-=len*cnt;
            len++;
            cnt*=10;
            start*=10;
        }
        long long num=start+(n-1)/len;
        int pos=(n-1)%len;
        string s=to_string(num);
        return s[pos]-'0';
    }
};