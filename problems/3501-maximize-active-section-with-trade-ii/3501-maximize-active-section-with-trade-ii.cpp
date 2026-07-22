class Solution
{
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries)
    {
        int n=s.size(),one=0;
        for(char c:s)
            one+=(c=='1');
        vector<int> st,en;
        for(int i=0;i<n;)
        {
            if(s[i]=='0')
            {
                int j=i;
                while(j<n && s[j]=='0')
                    j++;
                st.push_back(i);
                en.push_back(j-1);
                i=j;
            }
            else
                i++;
        }
        int m=st.size();
        vector<int> val;
        for(int i=0;i+1<m;i++)
            val.push_back((en[i]-st[i]+1)+(en[i+1]-st[i+1]+1));
        int sz=val.size();
        vector<vector<int>> sp;
        sp.push_back(val);
        for(int k=1;(1<<k)<=sz;k++)
        {
            vector<int> cur;
            for(int i=0;i+(1<<k)<=sz;i++)
                cur.push_back(max(sp[k-1][i],sp[k-1][i+(1<<(k-1))]));
            sp.push_back(cur);
        }
        auto rmq=[&](int l,int r)
        {
            int len=r-l+1;
            int k=31-__builtin_clz(len);
            return max(sp[k][l],sp[k][r-(1<<k)+1]);
        };
        auto clip=[&](int id,int l,int r)
        {
            return val[id]-max(0,l-st[id])-max(0,en[id+1]-r);
        };
        auto gain=[&](int l,int r)
        {
            if(m<2)
                return 0;
            int a=lower_bound(en.begin(),en.end(),l)-en.begin();
            int b=upper_bound(st.begin(),st.end(),r)-st.begin()-2;
            if(a>b)
                return 0;
            int ans=max(clip(a,l,r),clip(b,l,r));
            if(b-a>=2)
                ans=max(ans,rmq(a+1,b-1));
            return ans;
        };
        vector<int> ans;
        for(auto &q:queries)
            ans.push_back(one+gain(q[0],q[1]));
        return ans;
    }
};