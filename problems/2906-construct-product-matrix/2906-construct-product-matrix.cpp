class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        long long p = 1;
        int MOD = 12345;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = p;
                p = (p * grid[i][j]) % MOD;
            }
        }

        p = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                res[i][j] = (res[i][j] * p) % MOD;
                p = (p * grid[i][j]) % MOD;
            }
        }

        return res;
    }
};