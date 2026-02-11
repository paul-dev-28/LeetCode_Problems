class SegmentTree {
    int n;
    vector<int> tree_min, tree_max, lazy;

    void push(int node) {
        if (lazy[node] != 0) {
            tree_min[2 * node] += lazy[node];
            tree_max[2 * node] += lazy[node];
            lazy[2 * node] += lazy[node];
            tree_min[2 * node + 1] += lazy[node];
            tree_max[2 * node + 1] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            tree_min[node] += val;
            tree_max[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }

    int find_rightmost_zero(int node, int start, int end, int l) {
        if (end < l || tree_min[node] > 0 || tree_max[node] < 0) return -1;
        if (start == end) return start;

        push(node);
        int mid = (start + end) / 2;
        int res = find_rightmost_zero(2 * node + 1, mid + 1, end, l);
        if (res == -1) res = find_rightmost_zero(2 * node, start, mid, l);
        return res;
    }

public:
    SegmentTree(int n) : n(n), tree_min(4 * n, 0), tree_max(4 * n, 0), lazy(4 * n, 0) {}
    void update(int l, int r, int val) { if (l <= r) update(1, 0, n - 1, l, r, val); }
    int query(int l) { return find_rightmost_zero(1, 0, n - 1, l); }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = n - 1; i >= 0; --i) {
            pos[nums[i]].push_back(i);
        }

        SegmentTree st(n);
        unordered_map<int, int> ptr; 
        for (auto& entry : pos) {
            int val = entry.first;
            int first_idx = entry.second.back();
            int sign = (val % 2 != 0) ? 1 : -1;
            st.update(first_idx, n - 1, sign);
            ptr[val] = entry.second.size() - 1;
        }

        int max_len = 0;
        for (int l = 0; l < n; ++l) {
            int r = st.query(l);
            if (r != -1) max_len = max(max_len, r - l + 1);
            int val = nums[l];
            int sign = (val % 2 != 0) ? 1 : -1;
            
            int current_idx_in_vec = ptr[val];
            int next_p = (current_idx_in_vec > 0) ? pos[val][current_idx_in_vec - 1] : n;
            st.update(l, next_p - 1, -sign);
            ptr[val]--;
        }

        return max_len;
    }
};