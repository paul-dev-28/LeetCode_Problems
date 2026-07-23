class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n=graph.size();
        vector<vector<int>> rev(n);
        vector<int> out(n);
        for(int i=0;i<n;i++)
        {
            out[i]=graph[i].size();
            for(int v:graph[i])
                rev[v].push_back(i);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(out[i]==0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int v:rev[u])
            {
                out[v]--;
                if(out[v]==0)
                    q.push(v);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};