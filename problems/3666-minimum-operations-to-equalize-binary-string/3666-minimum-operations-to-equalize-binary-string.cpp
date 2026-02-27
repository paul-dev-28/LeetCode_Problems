class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int count0 = 0;
        for (char c : s) 
            if (c == '0') 
                count0++;
        if (count0 == 0) 
            return 0;
        vector<int> dist(n + 1, -1);
        dist[count0] = 0;
        set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) 
        {
            if (i != count0) unvisited[i % 2].insert(i);
        }
        queue<int> q;
        q.push(count0);
        while (!q.empty()) 
        {
            int i = q.front();
            q.pop();int low = abs(i - k); 
            int high = n - abs(n - (i + k));
            int parity = low % 2;
            auto& s_ref = unvisited[parity];
            auto it = s_ref.lower_bound(low);
            while (it != s_ref.end() && *it <= high) 
            {
                int next_i = *it;
                dist[next_i] = dist[i] + 1;
                if (next_i == 0) return dist[next_i];
                q.push(next_i);
                it = s_ref.erase(it);
            }
        }
        return dist[0];
    }
};