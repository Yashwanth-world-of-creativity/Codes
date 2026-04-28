class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>freq;
        for(auto &el: arr1) freq[el]++;
        vector<int>ans;
        for(auto &el:arr2){
            while(freq[el]--){
                ans.push_back(el);
            }
        }
         for(auto &[el,f]:freq){
            while(f>0&&freq[el]--){
                ans.push_back(el);
            }
        }
        return ans;     // T.C o(nlogn+m)
    }
};

// this one is optimized code as it involves the maximum legth of the array in this case it is 1000 so i am taking 1001 so the sorting nlon skips and the T.C is reduced to O(n + k) and space O(1000)
// and here instead of 1001 we can take the 

// class Solution {
// public:
//     vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

//         vector<int> freq(1001,0);  // here maxE is 1000 as the max arr[i]=1000 in the q so maxE+1 so no need to sort the array as the array index store the freq

//         for(int x : arr1)
//             freq[x]++;

//         vector<int> ans;

//         for(int x : arr2){
//             while(freq[x] > 0){
//                 ans.push_back(x);
//                 freq[x]--;
//             }
//         }

//         for(int i = 0; i <= 1000; i++){
//             while(freq[i] > 0){
//                 ans.push_back(i);
//                 freq[i]--;
//             }
//         }

//         return ans;
//     }
// };
