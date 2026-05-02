class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n + 1, 0);
        int count = 0;

        for (int i = 0; i <= n; i++) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8)
                    dp[i] = 1; // same
                else if (i == 2 || i == 5 || i == 6 || i == 9)
                    dp[i] = 2; // good
                else
                    dp[i] = 0; // invalid
            } else {
                int last = i % 10;
                int rest = i / 10;

                if (dp[last] == 0 || dp[rest] == 0) {
                    dp[i] = 0;
                } else if (dp[last] == 1 && dp[rest] == 1) {
                    dp[i] = 1;
                } else {
                    dp[i] = 2;
                }
            }

            if (dp[i] == 2) count++;
        }

        return count;
    }
};
