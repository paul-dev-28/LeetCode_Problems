class DSU {
public:
    vector<int> parent;
    int components;
    DSU(int n) : components(n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        auto check = [&](int X) -> bool {
            DSU dsu(n);
            int upgrades_used = 0;
            int mandatory_count = 0;
            int total_edges_in_tree = 0;
            for (const auto& e : edges) {
                if (e[3] == 1) {
                    if (e[2] < X) return false; 
                    if (!dsu.unite(e[0], e[1])) return false; 
                    total_edges_in_tree++;
                }
            }
            for (const auto& e : edges) {
                if (e[3] == 0 && e[2] >= X) {
                    if (dsu.unite(e[0], e[1])) {
                        total_edges_in_tree++;
                    }
                }
            }
            for (const auto& e : edges) {
                if (e[3] == 0 && e[2] < X && 2 * e[2] >= X) {
                    if (upgrades_used < k) {
                        if (dsu.unite(e[0], e[1])) {
                            upgrades_used++;
                            total_edges_in_tree++;
                        }
                    }
                }
            }

            return total_edges_in_tree == n - 1;
        };

        int low = 1, high = 200000, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};