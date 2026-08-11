// class Solution {
// public:
//     vector<int> replaceElements(vector<int>& arr) {
//         vector<int>res;
//         int n=arr.size();
//         for(int i=0;i<arr.size()-1;i++){
//             int maxrig=0;
//             for(int j=i+1;j<arr.size();j++){
//                 maxrig=max(arr[j],maxrig);
//             }
//               res.push_back(maxrig);
//             }

//             res.push_back(-1);
//         return res;
//     }
// };
// // class Solution {
// public:
//     vector<int> replaceElements(vector<int>& arr) {
//         vector<int> res;
//         int n = arr.size();

//         for (int i = 0; i < n - 1; i++) {
//             int maxrig = INT_MIN;

//             for (int j = i + 1; j < n; j++) {
//                 maxrig = max(maxrig, arr[j]);
//             }

//             res.push_back(maxrig);
//         }

//         res.push_back(-1);

//         return res;
//     }
// };
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);

        int maxi = -1;

        for (int i = n - 1; i >= 0; i--) {
            res[i] = maxi;
            maxi = max(maxi, arr[i]);
        }

        return res;
    }
};
