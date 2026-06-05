class Solution {
public:
    string s;

    struct Node {
        long long ways;
        long long waviness;
    };

    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node solve(int pos, int prev1, int prev2, bool tight, bool started) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (vis[pos][prev1 + 1][prev2 + 1][tight][started]) {
            return dp[pos][prev1 + 1][prev2 + 1][tight][started];
        }

        vis[pos][prev1 + 1][prev2 + 1][tight][started] = true;

        Node ans = {0, 0};

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            bool ntight = tight && (d == limit);

            if (!started && d == 0) {

                Node nxt = solve(pos + 1, -1, -1, ntight, false);

                ans.ways += nxt.ways;
                ans.waviness += nxt.waviness;
            }
            else {

                Node nxt = solve(pos + 1, d, prev1, ntight, true);

                long long add = 0;

                if (prev2 != -1) {

                    if ((prev2 < prev1 && prev1 > d) ||
                        (prev2 > prev1 && prev1 < d)) {

                        add = 1;
                    }
                }

                ans.ways += nxt.ways;
                ans.waviness += nxt.waviness + add * nxt.ways;
            }
        }

        return dp[pos][prev1 + 1][prev2 + 1][tight][started] = ans;
    }

    long long get(long long x) {

        if (x < 0) {
            return 0;
        }

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return solve(0, -1, -1, true, false).waviness;
    }

    long long totalWaviness(long long num1, long long num2) {

        return get(num2) - get(num1 - 1);
    }
};
