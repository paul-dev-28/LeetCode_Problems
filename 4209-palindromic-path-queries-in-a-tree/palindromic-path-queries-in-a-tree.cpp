class Solution {
public:
    int n,timer;
    vector<vector<int>> adj,up;
    vector<int> tin,tout,depth,bit;
    string s;
    void dfs(int u,int p)
    {
        tin[u]=++timer;
        up[u][0]=p;
        for(int j=1;j<20;j++)
            up[u][j]=up[up[u][j-1]][j-1];
        for(int v:adj[u])
        {
            if(v==p)
                continue;
            depth[v]=depth[u]+1;
            bit[v]=bit[u]^(1<<(s[v]-'a'));
            dfs(v,u);
        }
        tout[u]=timer;
    }
    int lca(int u,int v)
    {
        if(depth[u]<depth[v])
            swap(u,v);
        int d=depth[u]-depth[v];
        for(int j=0;j<20;j++)
            if(d>>j&1)
                u=up[u][j];
        if(u==v)
            return u;
        for(int j=19;j>=0;j--)
        {
            if(up[u][j]!=up[v][j])
            {
                u=up[u][j];
                v=up[v][j];
            }
        }
        return up[u][0];
    }
    vector<int> fw;
    void add(int i,int x)
    {
        for(;i<=n;i+=i&-i)
            fw[i]^=x;
    }
    int get(int i)
    {
        int x=0;
        for(;i>0;i-=i&-i)
            x^=fw[i];
        return x;
    }
    vector<bool> palindromePath(int n,vector<vector<int>>& edges,string s,vector<string>& queries)
    {
        this->n=n;
        this->s=s;
        timer=0;
        adj.assign(n,{});
        for(auto& e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        up.assign(n,vector<int>(20));
        tin.resize(n);
        tout.resize(n);
        depth.assign(n,0);
        bit.assign(n,0);
        bit[0]=1<<(s[0]-'a');
        dfs(0,0);
        fw.assign(n+2,0);
        vector<bool> ans;
        for(string& q:queries)
        {
            stringstream ss(q);
            string type;
            int u,v;
            ss>>type>>u;
            if(type=="update")
            {
                char c;
                ss>>c;
                int delta=(1<<(s[u]-'a'))^(1<<(c-'a'));
                if(delta)
                {
                    add(tin[u],delta);
                    add(tout[u]+1,delta);
                    s[u]=c;
                }
            }
            else
            {
                ss>>v;
                int w=lca(u,v);
                int x=(bit[u]^get(tin[u]))^(bit[v]^get(tin[v]));
                x^=1<<(s[w]-'a');
                ans.push_back((x&(x-1))==0);
            }
        }
        return ans;
    }
};