class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> dp;

    int countWalls(vector<int>& walls, int lo, int hi) {
        if (lo > hi) return 0;
        int left  = (int)(lower_bound(walls.begin(), walls.end(), lo) - walls.begin());
        int right = (int)(upper_bound(walls.begin(), walls.end(), hi) - walls.begin());
        return right - left;
    }

    int solve(vector<int>& walls, vector<P>& roboDist, vector<P>& range, int i, int prevDir) {
        int n = roboDist.size();
        if (i >= n) return 0;

        // return cached result
        if (dp[i][prevDir] != -1) return dp[i][prevDir];

        int leftStart = range[i].first;

        // if previous robot fired RIGHT, its bullet blocks part of left range
        if (prevDir == 1 && i > 0) {
            leftStart = max(leftStart, range[i-1].second + 1);
        }

        // fire LEFT
        int leftTake  = countWalls(walls, leftStart, roboDist[i].first)
                      + solve(walls, roboDist, range, i + 1, 0);

        // fire RIGHT
        int rightTake = countWalls(walls, roboDist[i].first, range[i].second)
                      + solve(walls, roboDist, range, i + 1, 1);

        return dp[i][prevDir] = max(leftTake, rightTake);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<P> roboDist(n);
        for (int i = 0; i < n; i++)
            roboDist[i] = {robots[i], distance[i]};

        sort(begin(roboDist), end(roboDist));
        sort(begin(walls), end(walls));

        vector<P> range(n);
        for (int i = 0; i < n; i++) {
            int pos = roboDist[i].first;
            int d   = roboDist[i].second;

            int leftLimit  = (i == 0)     ? INT_MIN : roboDist[i-1].first + 1;
            int rightLimit = (i == n - 1) ? INT_MAX : roboDist[i+1].first - 1;

            range[i] = {max(pos - d, leftLimit), min(pos + d, rightLimit)};
        }

        // ✅ initialize dp with -1
        dp.assign(n, vector<int>(2, -1));

        return solve(walls, roboDist, range, 0, 0);
    }
};
