class Solution {
public:
bool hasDuplicate(string &s1,string &s2){
    int arr[26]={0};
    for(char &ch:s1){
        if(arr[ch-'a']>0) return true; // checking for elements like "aa"
        arr[ch-'a']++;
    }
    for(char &ch:s2){
        if(arr[ch-'a']>0){
            return true;
        }
        arr[ch-'a']++;
    }
    return false;
}
int solve(int i,vector<string>& arr,string temp,int n){
    if(i>=n) return temp.length(); // at last index and after that
    int include=0;
    int exclude=0;
    if(hasDuplicate(arr[i],temp)){
        exclude=solve(i+1,arr,temp,n);
    }
    else{
        exclude=solve(i+1,arr,temp,n);
        include=solve(i+1,arr,temp+arr[i],n);
    }
    return max(exclude,include);
}
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string temp="";
        int i=0;
        return solve(i,arr,temp,n);
    }
};



//chatgpt memo
// class Solution {
// public:
//     int solve(int i, int mask, vector<int>& masks, vector<int>& len, vector<vector<int>>& dp){
//         if(i == masks.size()) return 0;

//         if(dp[i][mask] != -1) return dp[i][mask];

//         int notTake = solve(i+1, mask, masks, len, dp);

//         int take = 0;
//         if((mask & masks[i]) == 0){
//             take = len[i] + solve(i+1, mask | masks[i], masks, len, dp);
//         }

//         return dp[i][mask] = max(take, notTake);
//     }

//     int maxLength(vector<string>& arr) {

//         vector<int> masks, len;

//         for(string &s : arr){
//             int mask = 0;
//             bool valid = true;

//             for(char c : s){
//                 int bit = c - 'a';
//                 if(mask & (1<<bit)){
//                     valid = false;
//                     break;
//                 }
//                 mask |= (1<<bit);
//             }

//             if(valid){
//                 masks.push_back(mask);
//                 len.push_back(s.size());
//             }
//         }

//         int n = masks.size();
//         vector<vector<int>> dp(n, vector<int>(1<<26, -1));

//         return solve(0,0,masks,len,dp);
//     }
// };

// class Solution {
// public:

// bool hasDuplicate(string &s1,string &s2){
//     int arr[26]={0};

//     for(char &ch:s1){
//         if(arr[ch-'a']>0) return true;
//         arr[ch-'a']++;
//     }

//     for(char &ch:s2){
//         if(arr[ch-'a']>0) return true;
//         arr[ch-'a']++;
//     }

//     return false;
// }

// unordered_map<string,int> dp;

// int solve(int i, vector<string>& arr, string temp, int n){

//     if(i>=n) return temp.length();

//     string key = to_string(i) + "#" + temp;

//     if(dp.count(key)) return dp[key];

//     int exclude = solve(i+1, arr, temp, n);

//     int include = 0;

//     if(!hasDuplicate(arr[i], temp)){
//         include = solve(i+1, arr, temp + arr[i], n);
//     }

//     return dp[key] = max(include, exclude);
// }

// int maxLength(vector<string>& arr) {

//     int n = arr.size();

//     string temp = "";

//     return solve(0, arr, temp, n);
// }
// };


//tab
// class Solution {
// public:
//     int maxLength(vector<string>& arr) {

//         vector<int> dp = {0};

//         int ans = 0;

//         for(string &s : arr){

//             int mask = 0;
//             bool valid = true;

//             for(char c : s){
//                 int bit = c - 'a';
//                 if(mask & (1<<bit)){
//                     valid = false;
//                     break;
//                 }
//                 mask |= (1<<bit);
//             }

//             if(!valid) continue;

//             int m = dp.size();

//             for(int i = 0; i < m; i++){

//                 if((dp[i] & mask) == 0){

//                     int newMask = dp[i] | mask;
//                     dp.push_back(newMask);

//                     ans = max(ans, __builtin_popcount(newMask));
//                 }
//             }
//         }

//         return ans;
//     }
// };
