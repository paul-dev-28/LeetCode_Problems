class Solution
{
public:
    const long long LIM=1000001;
    long long ncr(int n,int r)
    {
        if(r>n-r)
            r=n-r;
        long long ans=1;
        for(int i=1;i<=r;i++)
        {
            ans=ans*(n-i+1)/i;
            if(ans>=LIM)
                return LIM;
        }
        return ans;
    }
    long long cnt(vector<int> &f)
    {
        int rem=0;
        for(int x:f)
            rem+=x;
        long long ans=1;
        for(int x:f)
        {
            ans*=ncr(rem,x);
            if(ans>=LIM)
                return LIM;
            rem-=x;
        }
        return ans;
    }
    string smallestPalindrome(string s,int k)
    {
        vector<int> c(26);
        string mid="";
        for(char x:s)
            c[x-'a']++;
        for(int i=0;i<26;i++)
        {
            if(c[i]&1)
                mid.push_back('a'+i);
            c[i]/=2;
        }
        if(cnt(c)<k)
            return "";
        string l="";
        int m=s.size()/2;
        while(m--)
        {
            for(int i=0;i<26;i++)
            {
                if(c[i]==0)
                    continue;
                c[i]--;
                long long cur=cnt(c);
                if(cur>=k)
                {
                    l.push_back('a'+i);
                    break;
                }
                k-=cur;
                c[i]++;
            }
        }
        string r=l;
        reverse(r.begin(),r.end());
        return l+mid+r;
    }
};