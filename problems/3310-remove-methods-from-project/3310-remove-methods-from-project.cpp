class Solution
{
public:
    void dfs(int u,vector<vector<int>> &g,vector<int> &vis)
    {
        vis[u]=1;
        for(int v:g[u])
        {
            if(!vis[v])
                dfs(v,g,vis);
        }
    }
    vector<int> remainingMethods(int n,int k,vector<vector<int>>& invocations)
    {
        vector<vector<int>> g(n);
        for(auto &x:invocations)
            g[x[0]].push_back(x[1]);
        vector<int> vis(n);
        dfs(k,g,vis);
        for(auto &x:invocations)
        {
            if(!vis[x[0]]&&vis[x[1]])
            {
                vector<int> ans;
                for(int i=0;i<n;i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};