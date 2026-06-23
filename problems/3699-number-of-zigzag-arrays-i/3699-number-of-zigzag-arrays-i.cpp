class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        vector<int> up(m + 1), down(m + 1);

        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        if (n == 2) {
            long long ans = 0;
            for (int v = 1; v <= m; v++)
                ans = (ans + up[v] + down[v]) % MOD;
            return (int)ans;
        }

        vector<int> prefUp(m + 1);
        vector<int> prefDown(m + 1);
        vector<int> newUp(m + 1);
        vector<int> newDown(m + 1);

        for (int len = 3; len <= n; len++) {

            prefUp[0] = prefDown[0] = 0;

            for (int i = 1; i <= m; i++) {
                prefUp[i] = (prefUp[i - 1] + up[i]) % MOD;
                prefDown[i] = (prefDown[i - 1] + down[i]) % MOD;
            }

            int totalUp = prefUp[m];

            for (int v = 1; v <= m; v++) {
                newUp[v] = prefDown[v - 1];

                newDown[v] = totalUp - prefUp[v];
                if (newDown[v] < 0)
                    newDown[v] += MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;

        for (int v = 1; v <= m; v++) {
            ans += up[v];
            ans += down[v];
        }

        return (int)(ans % MOD);
    }
};