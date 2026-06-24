class Solution {
    static constexpr long long MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long p) {
        int n = base.size();

        Matrix res(n, vector<long long>(n));
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (p) {
            if (p & 1) {
                res = multiply(res, base);
            }

            base = multiply(base, base);
            p >>= 1;
        }

        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        if (n == 1) {
            return m;
        }

        int S = 2 * m;

        Matrix T(S, vector<long long>(S));

        // up states: [0 ... m-1]
        // down states: [m ... 2m-1]

        for (int i = 0; i < m; i++) {

            // newUp[i] = sum down[j], j < i
            for (int j = 0; j < i; j++) {
                T[i][m + j] = 1;
            }

            // newDown[i] = sum up[j], j > i
            for (int j = i + 1; j < m; j++) {
                T[m + i][j] = 1;
            }
        }

        // DP for length = 2
        vector<long long> vec(S);

        for (int i = 0; i < m; i++) {

            vec[i] = i;               // smaller values
            vec[m + i] = m - 1 - i;  // larger values
        }

        if (n == 2) {
            long long ans = 0;

            for (auto x : vec) {
                ans = (ans + x) % MOD;
            }

            return ans;
        }

        Matrix P = power(T, n - 2);

        vector<long long> ans(S);

        for (int i = 0; i < S; i++) {
            long long cur = 0;

            for (int j = 0; j < S; j++) {
                cur = (cur + P[i][j] * vec[j]) % MOD;
            }

            ans[i] = cur;
        }

        long long res = 0;

        for (auto x : ans) {
            res = (res + x) % MOD;
        }

        return (int)res;
    }
};
