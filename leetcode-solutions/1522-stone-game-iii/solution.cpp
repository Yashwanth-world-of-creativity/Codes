class Solution {
public:
int n;
int solve(vector<int>& stone,int i,vector<int>& dp){
    if(i>=n) return 0;

    if(dp[i]!=-1) return dp[i];
    int result = stone[i]-solve(stone,i+1,dp);
    if(i+1<n)

    result = max(result,stone[i]+stone[i+1]-solve(stone,i+2,dp));
    if(i+2<n)

    result = max(result,stone[i]+stone[i+1]+stone[i+2]-solve(stone,i+3,dp));
    return dp[i]=result;
}
    string stoneGameIII(vector<int>& stone) {
        n=stone.size();
        vector<int>dp(n+1,-1);
        int diff=solve(stone,0,dp);

        if(diff<0)
        return "Bob";
        else if(diff>0){
            return "Alice";
        }
        else{
            return "Tie";
        }

    }
};
