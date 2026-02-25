class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> mp;
        mp[0] = -1;   // very important

        int sum = 0;
        int maxlen = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0)
                sum += -1;
            else
                sum += 1;

            if(mp.find(sum) != mp.end()) {
                maxlen = max(maxlen, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }

        return maxlen;
    }
};
//Brute Force
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int n=nums.size();
//         int maxlen=0;
//         for(int i=0;i<n;i++){
//             int zeros=0, ones=0;
//             for(int j=i;j<n;j++){
//                 if(nums[j]==0)
//                 zeros++;
//                 else
//                 ones++;

//                 if(zeros==ones)
//                 maxlen=max(maxlen,j-i+1);
//             }
//         }
//         return maxlen;
//             }
// };
