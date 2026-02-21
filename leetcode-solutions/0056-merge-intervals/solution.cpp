class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),end(arr));
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(ans.empty()||ans.back()[1]<arr[i][0]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
        }
        return ans;
    }
};
// Brute Froce O(NlogN)+O(N^2)
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         sort(intervals.begin(), intervals.end());
//         vector<vector<int>> ans;
//         for (int i = 0; i < n; i++) {
//             int start = intervals[i][0];
//             int end = intervals[i][1];
//             if (!ans.empty() && end <= ans.back()[1]) {
//                 continue; // if the (2,6) and (2,4) then dont care as the 4 is less then 6
//             }
//             for (int j = i + 1; j < n; j++) {
//                 if (intervals[j][0] <= end) {
//                     end = max(end, intervals[j][1]); // if there is condition of  2,18 and 16,17

//                 } else {
//                     break;
//                 }
//             }
//             ans.push_back({start, end});
//         }
//         return ans;
//     }
// };
