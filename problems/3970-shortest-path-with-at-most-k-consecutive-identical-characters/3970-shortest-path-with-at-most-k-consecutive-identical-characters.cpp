class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> a(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            a[u].push_back({v,w});
        }
        vector<vector<long long>> dist(n, vector<long long>(k+1,1e18));
        priority_queue<tuple<long long,int,int>,vector<tuple<long long, int ,int>>,greater<>> pq;
        dist[0][1]=0;
        pq.push({0,0,1});
        while(!(pq.empty()))
        {
            auto[d,u,cnt]=pq.top();
            pq.pop();
            if (d!=dist[u][cnt])
                continue;
            for(auto &[v,w]:a[u])
            {
                int ctr=0;
                if(labels[v]==labels[u])
                {
                    ctr=cnt+1;
                    if (ctr>k)
                        continue;
                }
                else
                    ctr=1;
                long long nd=d+w;
                if (nd<dist[v][ctr])
                {
                    dist[v][ctr]=nd;
                    pq.push({nd,v,ctr});
                }
            }
        }
        long long ans=1e18;
        for(int i=1;i<=k;i++)
            ans=min(ans,dist[n-1][i]);
        return ans==(1e18)? -1:ans;
    }
};