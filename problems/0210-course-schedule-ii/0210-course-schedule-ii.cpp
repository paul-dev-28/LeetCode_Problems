class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> in(numCourses);
        for(auto &x:prerequisites)
        {
            g[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            topo.push_back(u);
            for(int v:g[u])
            {
                in[v]--;
                if(in[v]==0)
                    q.push(v);
            }
        }
        if(topo.size()!=numCourses)
            return {};
        return topo;
    }
};