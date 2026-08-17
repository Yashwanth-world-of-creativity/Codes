// class Solution {
// public:
//     int smallestAbsent(vector<int>& nums) {
//         long long sum = 0;
//         unordered_set<int> st;

//         for (int x : nums) {
//             sum += x;
//             st.insert(x);
//         }

//         long long  avg = sum / nums.size();

//         int ans = max(1LL , avg + 1);

//         while (st.count(ans)) {
//             ans++;
//         }

//         return ans;
//     }
// }; // it fails for -ve num


class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        long long sum = 0;
        unordered_set<int> st;

        for (int x : nums) {
            sum += x;
            st.insert(x);
        }

        int n = nums.size();
        int ans = 1;

        while ((long long)ans * n <= sum || st.count(ans)) {
            ans++;
        }

        return ans;
    }
};
