class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>mp(k,0);
        for(int x:arr){
            int rem=(x%k+k)%k;
            mp[rem]++;
        }
        if(mp[0]%2!=0){
            return false;
        }
        for(int rem=1;rem<=k/2;rem++){
            int counterHalf=k-rem;
            if(mp[counterHalf]!=mp[rem]){
                return false;
            }
        }
        return true;
    }
};
// class Solution {
// public:
//     bool canArrange(vector<int>& arr, int k) {
//         unordered_map<int,int> mp;

//         for(int x : arr){
//             int rem = ((x % k) + k) % k; // handle negative
//             mp[rem]++;
//         }

//         for(auto &it : mp){
//             int rem = it.first;

//             if(rem == 0){
//                 if(it.second % 2 != 0) return false;
//             }
//             else if(2 * rem == k){
//                 if(it.second % 2 != 0) return false;
//             }
//             else{
//                 if(mp[rem] != mp[k - rem]) return false;
//             }
//         }

//         return true;
//     }
// };
