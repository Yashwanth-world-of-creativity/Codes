// class Solution {
// public:
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
//     }
// };


//chat memo

class Solution {
public:
    int solve(int i, vector<vector<int>>& jobs, vector<int>& dp){
        int n = jobs.size();
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int next = lower_bound(jobs.begin(), jobs.end(),
                               vector<int>{jobs[i][1],0,0}) - jobs.begin();

        int take = jobs[i][2] + solve(next, jobs, dp);
        int skip = solve(i+1, jobs, dp);

        return dp[i] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;

        for(int i=0;i<n;i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n,-1);

        return solve(0, jobs, dp);
    }
};


//chat tab
// class Solution {
// public:
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
//         int n = startTime.size();
//         vector<vector<int>> jobs;

//         for(int i=0;i<n;i++)
//             jobs.push_back({startTime[i], endTime[i], profit[i]});

//         sort(jobs.begin(), jobs.end());

//         vector<int> dp(n+1,0);

//         for(int i=n-1;i>=0;i--){
            
//             int next = lower_bound(jobs.begin(), jobs.end(),
//                                    vector<int>{jobs[i][1],0,0}) - jobs.begin();

//             int take = jobs[i][2] + dp[next];
//             int skip = dp[i+1];

//             dp[i] = max(take, skip);
//         }

//         return dp[0];
//     }
// };
