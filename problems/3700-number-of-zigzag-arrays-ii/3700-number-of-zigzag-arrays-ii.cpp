class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int N = A.size();

        Matrix C(N, vector<long long>(N, 0));

        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                if (!A[i][k]) continue;

                for (int j = 0; j < N; j++) {
                    if (!B[k][j]) continue;

                    C[i][j] =
                        (C[i][j] +
                         A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int N = base.size();

        Matrix res(N, vector<long long>(N, 0));

        for (int i = 0; i < N; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(long long n, int l, int r) {

        int m = r - l + 1;

        if (n == 1)
            return m;

        int S = 2 * m;

        auto U = [&](int v) {
            return v - 1;
        };

        auto D = [&](int v) {
            return m + (v - 1);
        };

        Matrix T(S, vector<long long>(S, 0));

        // D(u) -> U(v), v > u
        for (int u = 1; u <= m; u++) {
            for (int v = u + 1; v <= m; v++) {
                T[U(v)][D(u)] = 1;
            }
        }

        // U(u) -> D(v), v < u
        for (int u = 1; u <= m; u++) {
            for (int v = 1; v < u; v++) {
                T[D(v)][U(u)] = 1;
            }
        }

        vector<long long> init(S, 0);

        // length = 2
        for (int v = 1; v <= m; v++) {
            init[U(v)] = v - 1;
            init[D(v)] = m - v;
        }

        if (n == 2) {
            long long ans = 0;

            for (auto x : init)
                ans = (ans + x) % MOD;

            return (int)ans;
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                finalState[i] =
                    (finalState[i] +
                     P[i][j] * init[j]) % MOD;
            }
        }

        long long ans = 0;

        for (auto x : finalState)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};