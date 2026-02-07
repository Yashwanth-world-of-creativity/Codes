class Solution {
public:
    vector<int> dp;        // dp[i] = max profit starting from offer i
    vector<int> nextPos;   // nextPos[i] = next non-overlapping offer index

    int dfs(int i, vector<vector<int>>& offers) {
        // Base case: no offers left
        if (i >= offers.size())
            return 0;

        // If already solved, return stored answer
        if (dp[i] != -1)
            return dp[i];

        // Option 1: skip current offer
        int skip = dfs(i + 1, offers);

        // Option 2: take current offer
        int take = offers[i][2] + dfs(nextPos[i], offers);

        // Store and return best option
        return dp[i] = max(skip, take);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        // Step 1: sort offers by start house
        sort(offers.begin(), offers.end());

        int m = offers.size();

        // Step 2: extract only start positions
        vector<int> start(m);
        for (int i = 0; i < m; i++)
            start[i] = offers[i][0];

        // Step 3: build nextPos array using binary search
        nextPos.resize(m);
        for (int i = 0; i < m; i++) {
            int l = i + 1, r = m;
            while (l < r) {
                int mid = (l + r) / 2;
                if (start[mid] > offers[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }
            nextPos[i] = l;
        }

        // Step 4: initialize dp with -1
        dp.assign(m, -1);

        // Step 5: start recursion from first offer
        return dfs(0, offers);
    }
};
// class Solution {
// public:
//     int solve(int i, vector<vector<int>>& offers, vector<int>& dp) {
//         if (i >= offers.size()) return 0;
//         if (dp[i] != -1) return dp[i];

//         int skip = solve(i + 1, offers, dp);

//         int j = i + 1;
//         while (j < offers.size() && offers[j][0] <= offers[i][1])
//             j++;

//         int take = offers[i][2] + solve(j, offers, dp);

//         return dp[i] = max(skip, take);
//     }

//     int maximizeTheProfit(int n, vector<vector<int>>& offers) {
//         sort(offers.begin(), offers.end());
//         vector<int> dp(offers.size(), -1);
//         return solve(0, offers, dp);
//     }
// };


// 2.)
// 2class Solution {
// 3public:
// 4    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
// 5        int ans = 0;
// 6        vector<int>dp(n);
// 7        
// 8        map<int,vector<pair<int,int>>>range;
// 9        for(auto&x:offers){
// 10            range[x[0]].push_back({x[1],x[2]});
// 11        }
// 12        
// 13        for(int i=0;i<n;++i){
// 14            vector<pair<int,int>>temp = range[i];
// 15            
// 16            if(i)dp[i] = max(dp[i],dp[i-1]);
// 17            
// 18            for(auto&x:temp){
// 19               // max value till i-1 , + value of range starting from i
// 20               if(i) dp[x.first] = max(dp[x.first],dp[i-1]+x.second);
// 21                else dp[x.first] = max(dp[x.first],x.second);
// 22            }
// 23            
// 24            temp.clear();
// 25        }
// 26        
// 27        
// 28        return dp[n-1];
// 29        
// 30    }
// 31    
// 32};

