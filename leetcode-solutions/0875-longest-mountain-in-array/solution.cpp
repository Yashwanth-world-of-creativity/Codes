
//memo
// class Solution {
// public:
//     int incSolve(int i, vector<int>& arr, vector<int>& inc) {
//         if(i == 0) return inc[i] = 1;
//         if(inc[i] != -1) return inc[i];

//         if(arr[i] > arr[i-1])
//             return inc[i] = 1 + incSolve(i-1, arr, inc);

//         return inc[i] = 1;
//     }

//     int decSolve(int i, vector<int>& arr, vector<int>& dec) {
//         int n = arr.size();
//         if(i == n-1) return dec[i] = 1;
//         if(dec[i] != -1) return dec[i];

//         if(arr[i] > arr[i+1])
//             return dec[i] = 1 + decSolve(i+1, arr, dec);

//         return dec[i] = 1;
//     }

//     int longestMountain(vector<int>& arr) {
//         int n = arr.size();
//         if(n < 3) return 0;

//         vector<int> inc(n, -1), dec(n, -1);

//         for(int i = 0; i < n; i++)
//             incSolve(i, arr, inc);

//         for(int i = n-1; i >= 0; i--)
//             decSolve(i, arr, dec);

//         int ans = 0;

//         for(int i = 0; i < n; i++) {
//             if(inc[i] > 1 && dec[i] > 1)
//                 ans = max(ans, inc[i] + dec[i] - 1);
//         }

//         return ans;
//     }
// };




// class Solution {
// public:
//     int dp1[10001];
//     int dp2[10001];

//     int inc(vector<int>& arr, int i){
//         if(i == 0) return 1;
//         if(dp1[i] != -1) return dp1[i];

//         if(arr[i] > arr[i-1])
//             return dp1[i] = 1 + inc(arr, i-1);

//         return dp1[i] = 1;
//     }

//     int dec(vector<int>& arr, int n, int i){
//         if(i == n-1) return 1;
//         if(dp2[i] != -1) return dp2[i];

//         if(arr[i] > arr[i+1])
//             return dp2[i] = 1 + dec(arr, n, i+1);

//         return dp2[i] = 1;
//     }

//     int solve(vector<int>& arr, int n){
//         int ans = 0;

//         for(int i = 0; i < n; i++){
//             int left = inc(arr, i);
//             int right = dec(arr, n, i);

//             if(left > 1 && right > 1)
//                 ans = max(ans, left + right - 1);
//         }

//         return ans;
//     }

//     int longestMountain(vector<int>& arr) {
//         int n = arr.size();
//         if(n < 3) return 0;

//         memset(dp1, -1, sizeof(dp1));
//         memset(dp2, -1, sizeof(dp2));

//         return solve(arr, n);
//     }
// };
//two pointer
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int i = 1;

        while(i <= n - 2) {

            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {

                int l = i, r = i;

                while(l > 0 && arr[l] > arr[l-1])
                    l--;

                while(r < n-1 && arr[r] > arr[r+1])
                    r++;

                ans = max(ans, r - l + 1);

                i = r;
            }
            else {
                i++;
            }
        }

        return ans;
    }
};

//tab


// class Solution {
// public:
//     int longestMountain(vector<int>& arr) {
//         int n = arr.size();
//         if(n < 3) return 0;

//         vector<int> inc(n,0), dec(n,0);

//         for(int i = 1; i < n; i++){
//             if(arr[i] > arr[i-1])
//                 inc[i] = inc[i-1] + 1;
//         }

//         for(int i = n-2; i >= 0; i--){
//             if(arr[i] > arr[i+1])
//                 dec[i] = dec[i+1] + 1;
//         }

//         int ans = 0;

//         for(int i = 0; i < n; i++){
//             if(inc[i] > 0 && dec[i] > 0){
//                 ans = max(ans, inc[i] + dec[i] + 1);
//             }
//         }

//         return ans;
//     }
// };
