class Solution {
public:
    using ll=long long;
    ll mod=1000000007;
    ll base=911382323;

    vector<ll> h,pw;

    ll getHash(int l,int r)
    {
        if(l>r)
            return 0;
        return (h[r+1]-h[l]*pw[r-l+1]%mod+mod)%mod;
    }

    bool smaller(string& s,int a,int b,int len)
    {
        int l=0,r=len;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(getHash(a,a+mid-1)==getHash(b,b+mid-1))
                l=mid;
            else
                r=mid-1;
        }
        if(l==len)
            return false;
        return s[a+l]<s[b+l];
    }

    string shortestBeautifulSubstring(string s,int k)
    {
        int n=s.size();

        h.assign(n+1,0);
        pw.assign(n+1,1);

        for(int i=0;i<n;i++)
        {
            h[i+1]=(h[i]*base+s[i])%mod;
            pw[i+1]=pw[i]*base%mod;
        }

        vector<int> pos;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                pos.push_back(i);
        }

        if(pos.size()<k)
            return "";

        int bestLen=INT_MAX;
        int bestStart=0;

        for(int i=0;i+k-1<pos.size();i++)
        {
            int l=pos[i];
            int r=pos[i+k-1];
            int len=r-l+1;

            if(len<bestLen)
            {
                bestLen=len;
                bestStart=l;
            }
            else if(len==bestLen)
            {
                if(smaller(s,l,bestStart,len))
                    bestStart=l;
            }
        }

        return s.substr(bestStart,bestLen);
    }
};