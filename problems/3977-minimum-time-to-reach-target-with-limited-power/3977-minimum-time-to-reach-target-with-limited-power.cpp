typedef long long ll;

class Solution
{
public:
    vector<long long> minTimeMaxPower(int n,vector<vector<int>>& edges,int power,vector<int>& cost,int source,int target)
    {
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<edges.size();i++)
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});

        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;

        vector<int> mx(n,-1);

        pq.push({0,-power,source});

        while(!pq.empty())
        {
            ll tm=pq.top()[0];
            int p=-pq.top()[1];
            int u=pq.top()[2];
            pq.pop();

            if(u==target)
                return {tm,1LL*p};

            if(p<=mx[u])
                continue;

            mx[u]=p;

            if(p<cost[u])
                continue;

            int np=p-cost[u];

            for(int i=0;i<adj[u].size();i++)
            {
                int v=adj[u][i].first;
                int w=adj[u][i].second;
                pq.push({tm+w,-np,v});
            }
        }

        return {-1,-1};
    }
};