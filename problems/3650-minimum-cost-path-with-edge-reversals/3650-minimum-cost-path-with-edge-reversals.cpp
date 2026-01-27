class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n), radj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            radj[e[1]].push_back({e[0], e[2]});
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF);

        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> pq;

        dist[0] = 0;
        pq.push({0,0});

        while (!pq.empty()) {
            auto [d,u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;

            // normal outgoing edges
            for (auto &[v,w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }

            for (auto &[v,w] : radj[u]) {
                long long nd = d + 2LL*w;
                if (dist[v] > nd) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        return dist[n-1] == INF ? -1 : dist[n-1];
    }
};