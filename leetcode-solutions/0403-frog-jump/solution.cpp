

class Solution {
public:
    bool canCross(vector<int>& stones) {

        unordered_map<int, unordered_set<int>> mp;

        mp[1] = {1};   // first jump must be 1

        for(int i = 1; i < stones.size(); ++i) {

            for(auto jumpSize : mp[stones[i]]) {

                mp[stones[i] + jumpSize].insert(jumpSize);

                mp[stones[i] + jumpSize + 1].insert(jumpSize + 1);

                mp[stones[i] + jumpSize - 1].insert(jumpSize - 1);
            }
        }

        return mp[stones.back()].size() != 0;
    }
};

// class Solution {
// public:
//     int n;
//     unordered_map<int,int> mp;   // stone value -> index
//     vector<vector<int>> dp;      // memo table

//     bool solve(vector<int>& stones, int currIdx, int prevJump) {

//         if(currIdx == n - 1)
//             return true;

//         if(dp[currIdx][prevJump] != -1)
//             return dp[currIdx][prevJump];

//         bool result = false;

//         for(int nextJump = prevJump - 1;
//             nextJump <= prevJump + 1;
//             nextJump++) {

//             if(nextJump > 0) {

//                 int nextStone = stones[currIdx] + nextJump;

//                 if(mp.find(nextStone) != mp.end()) {
//                     result = result || 
//                              solve(stones, mp[nextStone], nextJump);
//                 }
//             }
//         }

//         return dp[currIdx][prevJump] = result;
//     }

//     bool canCross(vector<int>& stones) {

//         n = stones.size();

//         if(stones[1] != 1)
//             return false;

//         for(int i = 0; i < n; i++)
//             mp[stones[i]] = i;

//         // dp[index][lastJump]
//         dp.assign(n, vector<int>(n+1, -1));

//         return solve(stones, 0, 0);
//     }
// };
