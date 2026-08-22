class Solution
{
public:
    int alternateDigitSum(int n)
    {
        string s=to_string(n);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int d=s[i]-'0';
            if(i%2==0)
                ans+=d;
            else
                ans-=d;
        }
        return ans;
    }
};