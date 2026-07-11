class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,int &nodes,int &edge)
    {
        vis[node]=1;
        nodes++;
        edge+=adj[node].size();
        for(int it:adj[node])
        {
            if(!vis[it])
                dfs(it,adj,vis,nodes,edge);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &v:edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int nodes=0,edge=0;
                dfs(i,adj,vis,nodes,edge);
                edge/=2;
                if(edge==nodes*(nodes-1)/2)
                    ans++;
            }
        }
        return ans;
    }
};