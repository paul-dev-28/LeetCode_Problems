class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>par(n);
        for(int i=0;i<n;i++)
            par[i]=i;
        function<int(int)>find=[&](int x) {
            if(par[x]==x)
                return x;
            return par[x]=find(par[x]);
        };
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                if(mp.count(mail))
                {
                    int a=find(i),b=find(mp[mail]);
                    if(a!=b)
                        par[b]=a;
                }
                else
                    mp[mail]=i;
            }
        }
        unordered_map<int,vector<string>>m;
        for(auto &[mail,i]:mp)
            m[find(i)].push_back(mail);
        vector<vector<string>>ans;
        for(auto &[i,v]:m)
        {
            sort(v.begin(),v.end());
            v.insert(v.begin(),accounts[i][0]);
            ans.push_back(v);
        }
        return ans;
    }
};