

class Solution {
public:
    double dp[26][26][101];

    double solve(int n, int k, int r, int c) {
        if (r < 0 || c < 0 || r >= n || c >= n)
            return 0.0;

        if (k == 0)
            return 1.0;

        if (dp[r][c][k] != -1)
            return dp[r][c][k];

        int dr[8] = {-2,-2,-1,-1,1,1,2,2};
        int dc[8] = {-1,1,-2,2,-2,2,-1,1};

        double prob = 0.0;

        for (int i = 0; i < 8; i++) {
            prob += solve(n, k-1, r + dr[i], c + dc[i]) / 8.0;
        }

        return dp[r][c][k] = prob;
    }

    double knightProbability(int n, int k, int row, int column) {
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                for(int t=0;t<101;t++)
                    dp[i][j][t] = -1;

        return solve(n, k, row, column);
    }
};



// class Solution {
// public:
//     unordered_map<string, double> mp;

//     // 8 possible knight directions
//     int dir[8][2] = {
//         {-2,-1}, {-1,-2}, {1,-2}, {2,-1},
//         {2,1}, {1,2}, {-1,2}, {-2,1}
//     };

//     double findProb(int n, int moves, int r, int c) {
//         // ❌ Out of boundary
//         if (r < 0 || r >= n || c < 0 || c >= n)
//             return 0.0;

//         // ✅ No moves left → still inside
//         if (moves == 0)
//             return 1.0;

//         // 🔑 Create unique key for memo
//         string key = to_string(r) + "," + 
//                      to_string(c) + "," + 
//                      to_string(moves);

//         // 🔁 Already calculated
//         if (mp.find(key) != mp.end())
//             return mp[key];

//         double probability = 0.0;

//         // Try all 8 moves
//         for (int i = 0; i < 8; i++) {
//             int newR = r + dir[i][0];
//             int newC = c + dir[i][1];

//             probability += findProb(n, moves - 1, newR, newC) / 8.0;
//         }

//         // 💾 Store result
//         mp[key] = probability;

//         return probability;
//     }

//     double knightProbability(int n, int k, int row, int column) {
//         return findProb(n, k, row, column);
//     }
// };
