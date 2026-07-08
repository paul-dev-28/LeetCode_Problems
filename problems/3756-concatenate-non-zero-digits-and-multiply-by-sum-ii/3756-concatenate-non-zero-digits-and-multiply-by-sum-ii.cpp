class Solution {
public:
    static const int MOD=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> cnt(n+1,0);
        vector<int> d;
        for(int i=0;i<n;i++)
        {
            cnt[i+1]=cnt[i];
            if(s[i]!='0')
            {
                cnt[i+1]++;
                d.push_back(s[i]-'0');
            }
        }
        int m=d.size();
        vector<long long> pre(m+1,0),h(m+1,0),p(m+1,1);
        for(int i=0;i<m;i++)
        {
            pre[i+1]=pre[i]+d[i];
            h[i+1]=(h[i]*10+d[i])%MOD;
            p[i+1]=(p[i]*10)%MOD;
        }
        vector<int> ans;
        for(auto &v:queries)
        {
            int l=cnt[v[0]];
            int r=cnt[v[1]+1]-1;
            if(l>r)
            {
                ans.push_back(0);
                continue;
            }
            int len=r-l+1;
            long long x=(h[r+1]-h[l]*p[len]%MOD+MOD)%MOD;
            long long sum=pre[r+1]-pre[l];
            ans.push_back((x*sum)%MOD);
        }
        return ans;
    }
};